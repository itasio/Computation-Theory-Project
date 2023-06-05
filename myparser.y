%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
  	#include "cgen.h"
	#define MAX_COMPS 100 	//number of comp types / functions permitted in ka language
	#define MAX_COMP_VARS 100 //number of variables permitted per comp in ka language
	#define MAX_CHARS_FOR_FUNCTIONS 3000	//number of characters permitted for .c functions being translated from .ka language 

	char expression[100], toBeReplaced[100], replacer[100];		//for list comprehension
	char comp_func_to_C[MAX_CHARS_FOR_FUNCTIONS];			//used for printinf struct functions after their declaration
	char helper_comp_func[500];	//used to store self functions (ctor)
	char* comps[MAX_COMPS];	//name of comp types will be stored here
	char* comp_vars[MAX_COMP_VARS];	//name of comp variables will be stored here for each comp, during comp declaration. After that elements will be erased. 
	char* comp_funcs[MAX_COMP_VARS];	//name of comp functions will be stored here for each comp, during comp declaration. After that elements will be erased. 
	char* all_comp_vars[MAX_COMP_VARS];	//name of all comp variables declared in .ka program
	char* all_comp_funcs[MAX_COMP_VARS];	//name of all comp functions declared in .ka program
	char* temp;		//used to temporarily store name of a Comp(multiple var decl per line)
	char* comp_var_name;		//used to temporarily store name of a Comp variable
	
	int insideCompDecl = 0;	//used to indicate that we are inside a comp declaration. For function comp variables handling inside functions
	int numOfCompVars = 0; //num of variables per comp. Used in conjunction with comp_vars[MAX_COMP_VARS]
	int numOfCompFuncs = 0; //num of functions per comp. Used in conjunction with comp_funcs[MAX_COMP_VARS]
	int numOfAllCompVars = 0;	//num of all variables declared in .ka program
	int numOfAllCompFuncs = 0;	//num of all functions declared in .ka program
	int isStr = 0;	//used for multiple variables declaration in one line
	int numOfComps = 0;		//number of different Comp types declared in program
	int isComp = 0; // used for Comp type variables
	
	void replaceWord(char* str, char* oldWord, char* newWord);
	extern int yylex(void);
	int find_comp(char* compToSearch, char* whereToSearch);


%}

%union {
	char* str;
}
%define parse.error verbose

%token <str> TK_IDENT 
%token <str> TK_CONSTINT 
%token <str> TK_CONSTFLOAT 
%token <str> TK_CONSTSTR

%token TK_POW
%token TK_PLUEQ
%token TK_MINEQ
%token TK_MULEQ
%token TK_DIVEQ
%token TK_MODEQ
%token TK_EQEQ
%token TK_NOTEQ
%token TK_GREEQ
%token TK_LESEQ
%token TK_COLEQ
%token TK_FUNC_RET

%token KW_AND
%token KW_OR
%token KW_NOT														
%token KW_INTEGER
%token KW_FOR
%token KW_BREAK
%token KW_DEF
%token KW_ENDCOMP
%token KW_SCALAR
%token KW_CONST
%token KW_IN
%token KW_CONTINUE
%token KW_ENDDEF
%token KW_OF
%token KW_STR
%token KW_IF
%token KW_ENDFOR
%token KW_MAIN
%token KW_BOOLEAN
%token KW_ELSE
%token KW_WHILE
%token KW_RETURN
%token KW_ENDIF
%token KW_ENDWHILE
%token KW_COMP
%token KW_TRUE
%token KW_FALSE

%start program

%type <str> statements listofexpr listofinstructions  main_block function_blocks function_return_type var_declarations const_declarations comp_declarations
%type <str> statement if_statement while_statement for_statement expr data_type const_declaration var_declaration function_block one_var comp_declaration
%type <str> multi_var multi_var_1 multi_var_2 multi_var_3 func_param_call function_param_decl function_call_no_assgn listof_comp_instructions comp_multi_var
%type <str> fict_token listCompr_with_int_values listCompr_with_array comp_var_declarations comp_var_declaration
%type <str> comp_multi_var_1 comp_multi_var_2 comp_multi_var_3

%right '=' TK_PLUEQ TK_MINEQ TK_MULEQ TK_DIVEQ TK_MODEQ TK_COLEQ
%left KW_OR
%left KW_AND
%right KW_NOT
%left TK_EQEQ TK_NOTEQ
%left '<' TK_LESEQ '>' TK_GREEQ
%left '+' '-' 
%left '*' '/' '%'
%left UMINUS UPLUS
%right TK_POW
%left '.' '(' ')' '[' ']'
%%

program:
	main_block 																			{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", $1);}}
	| function_blocks main_block  														{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", $1, $2);}}
	| var_declarations main_block  														{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", $1, $2);}}
	| const_declarations main_block  													{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", $1, $2);}}
	| comp_declarations main_block  													{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", $1, $2);}}
	| const_declarations function_blocks main_block 									{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", $1, $2, $3);}}
	| comp_declarations function_blocks main_block 										{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", $1, $2, $3);}}
	| var_declarations function_blocks main_block 										{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", $1, $2, $3);}}
	| const_declarations var_declarations function_blocks main_block					{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", $1, $2, $3, $4);}}
	| comp_declarations var_declarations function_blocks main_block						{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", $1, $2, $3, $4);}}
	| comp_declarations const_declarations var_declarations function_blocks main_block	{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s\n%s", $1, $2, $3, $4, $5);}}
	;

main_block:
	KW_DEF KW_MAIN '(' ')' ':' KW_ENDDEF ';' {$$ = template("int main(){}");}
	| KW_DEF KW_MAIN '(' ')' ':' listofinstructions KW_ENDDEF ';' {$$ = template("int main(){\n%s\n}",$6);}
	;

function_param_decl:
	%empty {$$ = template("");}
	| var_declaration {$$ = template("%s", $1);}
	| function_param_decl ',' var_declaration {$$ = template("%s, %s", $1, $3);}
	;

function_return_type:
	TK_FUNC_RET data_type {$$ = template("%s", $2);}
	//| TK_FUNC_RET KW_SCALAR {$$ = template("double");}
	//| TK_FUNC_RET KW_STR {$$ = template("char*");}
	//| TK_FUNC_RET KW_BOOLEAN  {$$ = template("int");}
	//| TK_FUNC_RET TK_IDENT 
	;

function_blocks:
	function_block ';' {$$ = template("%s", $1);}
	| function_blocks function_block ';' {$$ = template("%s \n%s", $1, $2);}
	;

function_block:
	KW_DEF TK_IDENT '(' function_param_decl ')' ':' listofinstructions KW_ENDDEF {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = $2;
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = $2;
			numOfAllCompFuncs ++;
			if(strcmp($4, "") == 0) $$ = template("void (*%s)(SELF);", $2); //empty parameters 
			else $$ = template("void (*%s)(SELF, %s);", $2, $4); 
			strcat(comp_func_to_C, "void ");
			strcat(comp_func_to_C, $2); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp($4, "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, $4); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, $7);   strcat(comp_func_to_C, "\n}\n");
		}else{
			$$ = template("void %s(%s){\n%s\n}", $2, $4, $7);
		}
	}
	| KW_DEF TK_IDENT '(' function_param_decl ')' ':' listofinstructions KW_RETURN ';' KW_ENDDEF {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = $2;
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = $2;
			numOfAllCompFuncs ++;
			if(strcmp($4, "") == 0) $$ = template("void (*%s)(SELF);", $2); //empty parameters 
			else $$ = template("void (*%s)(SELF, %s);", $2, $4); 
			strcat(comp_func_to_C, "void ");
			strcat(comp_func_to_C, $2); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp($4, "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, $4); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, $7);   strcat(comp_func_to_C, "\nreturn;\n}\n");
		}else{
			$$ = template("void %s(%s){\n%s\nreturn;\n}", $2, $4, $7);
		}	
	}
	| KW_DEF TK_IDENT '(' function_param_decl ')' ':'  KW_RETURN ';' KW_ENDDEF {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = $2;
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = $2;
			numOfAllCompFuncs ++;
			if(strcmp($4, "") == 0) $$ = template("void (*%s)(SELF);", $2); //empty parameters 
			else $$ = template("void (*%s)(SELF, %s);", $2, $4); 
			strcat(comp_func_to_C, "void ");
			strcat(comp_func_to_C, $2); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp($4, "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, $4); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, "return;\n}\n");
		}else{
			$$ = template("void %s(%s){\nreturn;\n}", $2, $4);
		}
	}
	| KW_DEF TK_IDENT '(' function_param_decl ')' function_return_type ':' listofinstructions KW_RETURN  expr ';' KW_ENDDEF {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = $2;
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = $2;
			numOfAllCompFuncs ++;
			if(strcmp($4, "") == 0) $$ = template("%s (*%s)(SELF);", $6, $2); //empty parameters 
			else $$ = template("%s (*%s)(SELF, %s);", $6, $2, $4); 
			strcat(comp_func_to_C, $6); strcat(comp_func_to_C, " ");
			strcat(comp_func_to_C, $2); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp($4, "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, $4); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, $8);
			strcat(comp_func_to_C, "\nreturn "); strcat(comp_func_to_C, $10); strcat(comp_func_to_C, ";\n}");
		}else{
			$$ = template("%s %s(%s){\n%s\nreturn %s;\n}", $6, $2, $4, $8, $10);
		}
	}
	| KW_DEF TK_IDENT '(' function_param_decl ')' function_return_type ':'  KW_RETURN  expr ';' KW_ENDDEF {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = $2;
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = $2;
			numOfAllCompFuncs ++;
			if(strcmp($4, "") == 0) $$ = template("%s (*%s)(SELF);", $6, $2); //empty parameters 
			else $$ = template("%s (*%s)(SELF, %s);", $6, $2, $4); 
			strcat(comp_func_to_C, $6); strcat(comp_func_to_C, " ");
			strcat(comp_func_to_C, $2); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp($4, "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, $4); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, "return "); strcat(comp_func_to_C, $9); strcat(comp_func_to_C, ";\n}");
		}else{
			$$ = template("%s %s(%s){\nreturn %s;\n}", $6, $2, $4, $9);
		}
	}
	;


function_call_no_assgn:
	TK_IDENT '(' func_param_call ')' {$$ = template("%s(%s)", $1, $3);}
	| TK_IDENT '(' ')' {$$ = template("%s()", $1);}
	;

func_param_call:
	expr {$$ = template("%s", $1);}
	| func_param_call ',' expr {$$ = template("%s, %s", $1, $3);}
	;

listofexpr:
	expr {$$ = template("%s", $1);}
	| listofexpr expr {$$ = template("%s \n%s", $1, $2); }
	;

expr:
	TK_CONSTINT
	| TK_CONSTFLOAT
	| TK_IDENT	{
				if( (insideCompDecl == 1) && (find_comp($1, "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
							yyerror("Comp variables are preceded by # ");
				}else {$$ = template("%s", $1);}
				}
	| '#' TK_IDENT 	{
					if( (insideCompDecl == 1) && (find_comp($2, "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
							$$ = template("self->%s", $2);
					}else if ((insideCompDecl == 1) && (find_comp($2, "all_comp_vars"))){
						//first if stmt will catch variables that belong to current
						//comp declaration
						//this if stmt will catch vars that belong to other comps
						$$ = template("%s", $2);
					}
					else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
					}
	| TK_CONSTSTR
	| KW_FALSE	{$$ = template("0");}
	| KW_TRUE	{$$ = template("1");}
	| expr KW_OR expr {$$ = template("%s || %s", $1, $3);}
	| expr KW_AND expr {$$ = template("%s && %s", $1, $3);}
	| KW_NOT expr {$$ = template("!%s", $2);}
	| expr TK_NOTEQ expr {$$ = template("%s != %s", $1, $3);}
	| expr TK_EQEQ expr {$$ = template("%s == %s", $1, $3);}
	| expr TK_LESEQ expr {$$ = template("%s <= %s", $1, $3);}
	| expr TK_GREEQ expr {$$ = template("%s >= %s", $1, $3);}
	| expr '<' expr {$$ = template("%s < %s", $1, $3);}
	| expr '>' expr {$$ = template("%s > %s", $1, $3);}
	| expr '+' expr {$$ = template("%s + %s", $1, $3);}
	| expr '-' expr {$$ = template("%s - %s", $1, $3);}
	| expr '*' expr {$$ = template("%s * %s", $1, $3);}
	| expr '/' expr {$$ = template("%s / %s", $1, $3);}
	| expr '%' expr {$$ = template("%s %% %s", $1, $3);}
	| expr TK_POW expr {$$ = template("pow(%s, %s)", $1, $3);}
	| '-' expr %prec UMINUS {$$ = template("- %s", $2);}
	| '+' expr %prec UPLUS {$$ = template("%s", $2);}
	| '(' expr ')' {$$ = template("(%s)", $2);}
	| TK_IDENT '[' expr ']' { 
			if( (insideCompDecl == 1) && (find_comp($1, "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
				yyerror("Comp variables are preceded by # ");
			}else {$$ = template("%s[%s]", $1, $3);}
		
		}
	| '#' TK_IDENT '[' expr ']' { 
			if( (insideCompDecl == 1) && (find_comp($2, "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
				$$ = template("self->%s[%s]", $2, $4);
			}else if ((insideCompDecl == 1) && (find_comp($2, "all_comp_vars"))){
				//first if stmt will catch variables that belong to current
				//comp declaration
				//this if stmt will catch vars that belong to other comps
				$$ = template("%s[%s]", $2, $4);
			}
			else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		
		}
	| expr '.' expr {$$ = template("%s.%s", $1, $3);}
	| function_call_no_assgn {$$ = template("%s", $1);}
	;

listofinstructions:
	var_declarations const_declarations statements {$$ = template("%s\n%s\n%s",$1, $2, $3);}
	| const_declarations var_declarations statements {$$ = template("%s\n%s\n%s",$1, $2, $3);}
	| statements {$$ = template("%s",$1);}
	| var_declarations statements {$$ = template("%s\n%s",$1, $2);}
	| const_declarations statements {$$ = template("%s\n%s",$1, $2);}
	;



statements:
	statement  { $$ = template("%s", $1);}
	| statements statement { $$ = template("%s \n%s", $1, $2); }
	;

statement:
	fict_token '=' listofexpr ';' {$$ = template("%s = %s;",$1, $3);}
	| fict_token TK_PLUEQ expr ';' {$$ = template("%s += %s;",$1, $3);}
	| fict_token TK_MINEQ expr ';' {$$ = template("%s -= %s;",$1, $3);}
	| fict_token TK_MULEQ expr ';' {$$ = template("%s *= %s;",$1, $3);}
	| fict_token TK_MODEQ expr ';' {$$ = template("%s %= %s;",$1, $3);}
	| fict_token TK_DIVEQ expr ';' {$$ = template("%s /= %s;",$1, $3);}
	| fict_token TK_COLEQ expr ';' {$$ = template("%s := %s;",$1, $3);}
	| fict_token '.' function_call_no_assgn ';' {$$ = template("%s.%s;",$1, $3);}
	| function_call_no_assgn ';' {$$ = template("%s;",$1);}
	| if_statement ';' {$$ = template("%s",$1);}
	| for_statement ';' {$$ = template("%s",$1);}
	| while_statement ';' {$$ = template("%s",$1);}
	| KW_BREAK ';' {$$ = template("break;");}
	| KW_CONTINUE ';' {$$ = template("continue;");}
	| listCompr_with_int_values ';'{$$ = template("%s;",$1);}
	| listCompr_with_array ';' {$$ = template("%s;",$1);}
	| ';' {$$ = template("");}
	;

fict_token:
	TK_IDENT { if( (insideCompDecl == 1) && (find_comp($1, "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
			   		yyerror("Comp variables are preceded by # ");
			   }else {$$ = template("%s", $1);}
			 }
	| '#' TK_IDENT { if( (insideCompDecl == 1) && (find_comp($2, "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
			   			$$ = template("self->%s", $2);
						
			   		}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		 }
	| TK_IDENT '[' TK_CONSTINT ']' 	{ if( (insideCompDecl == 1) && (find_comp($1, "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {$$ = template("%s[%s]",$1, $3);}
									}
	| '#' TK_IDENT '[' TK_CONSTINT ']' {if( (insideCompDecl == 1) && (find_comp($2, "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
											$$ = template("self->%s[%s]",$2, $4);
										}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
	| TK_IDENT '[' TK_IDENT ']' { if( (insideCompDecl == 1) && (find_comp($1, "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {$$ = template("%s[%s]",$1, $3);}
		}
	| '#' TK_IDENT '[' '#' TK_IDENT ']' {if( (insideCompDecl == 1) && (find_comp($2, "comp_vars")) && (find_comp($5, "comp_vars"))){ //if inside comp declaration and tokens are member of comp then correct
											$$ = template("self->%s[self->%s]",$2, $5);
									}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
	| '#' TK_IDENT '[' TK_IDENT ']' {if( (insideCompDecl == 1) && (find_comp($2, "comp_vars")) && (!find_comp($4, "comp_vars")) ){ //if inside comp declaration, 1st token is member of comp and 2nd isn't then correct
											$$ = template("self->%s[%s]",$2, $4);
									}else {yyerror("Comp variables inside comp declarations are preceded by # ");}
		}
	| TK_IDENT '[' '#' TK_IDENT ']' {if( (insideCompDecl == 1) && (!find_comp($1, "comp_vars")) && (find_comp($4, "comp_vars")) ){ //if inside comp declaration, 1st token not member of comp and 2nd is then correct
											$$ = template("%s[self->%s]",$1, $4);
									}else {yyerror("Comp variables inside comp declarations are preceded by # ");}
		}
	;

if_statement:
	KW_IF '(' listofexpr ')' ':' statements KW_ENDIF {$$ = template("if(%s){\n%s\n}", $3, $6);}
	| KW_IF '(' listofexpr ')' ':' KW_ENDIF {$$ = template("if(%s){\n}", $3);}
	| KW_IF '(' listofexpr ')' ':' statements KW_ELSE ':' statements KW_ENDIF {$$ = template("if(%s){\n%s\n}\nelse{\n%s\n}", $3, $6, $9);}
	| KW_IF '(' listofexpr ')' ':'  KW_ELSE ':' statements KW_ENDIF {$$ = template("if(%s){\n}\nelse{\n%s\n}", $3, $8);}
	| KW_IF '(' listofexpr ')' ':' statements KW_ELSE ':'  KW_ENDIF {$$ = template("if(%s){\n%s\n}\nelse{\n}", $3, $6);}
	| KW_IF '(' listofexpr ')' ':' KW_ELSE ':'  KW_ENDIF {$$ = template("if(%s){\n}\nelse{\n}", $3);}
	;




while_statement:
	KW_WHILE '(' listofexpr ')' ':' statements KW_ENDWHILE {$$ = template("while(%s){\n%s\n}", $3, $6);}
	| KW_WHILE '(' listofexpr ')' ':' KW_ENDWHILE {$$ = template("while(%s){\n}", $3);}
	;

for_statement:
	KW_FOR TK_IDENT KW_IN '[' expr ':' expr ':' expr ']' ':' statements KW_ENDFOR {$$ = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", $2, $5, $2, $7, $2, $9, $12);}
	| KW_FOR TK_IDENT KW_IN '[' expr ':' expr ':' expr ']' ':' KW_ENDFOR {$$ = template("for (int %s=%s; %s<%s; %s+=%s){\n}", $2, $5, $2, $7, $2, $9);}
	| KW_FOR TK_IDENT KW_IN '[' expr ':' expr ']' ':' statements KW_ENDFOR {$$ = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", $2, $5, $2, $7, $2, $10);}
	| KW_FOR TK_IDENT KW_IN '[' expr ':' expr ']' ':' KW_ENDFOR {$$ = template("for (int %s=%s; %s<%s; %s++){\n}", $2, $5, $2, $7, $2);}
	;

listCompr_with_int_values:
	TK_IDENT TK_COLEQ '[' expr KW_FOR TK_IDENT ':' TK_CONSTINT ']' ':' data_type 
	{$$ = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s = 0; %s < %s; ++%s)\n%s[%s] = %s", $11, $1, $11, $8, $11, $6, $6, $8, $6, $1, $6, $4);}
	;

listCompr_with_array:
	TK_IDENT TK_COLEQ '[' expr KW_FOR TK_IDENT ':' data_type KW_IN TK_IDENT KW_OF TK_CONSTINT ']' ':' data_type
	{	strcpy(expression, $4);
		strcpy(toBeReplaced, $6);
		strcpy(replacer, $10);
		strcat(replacer, "[");
		strcat(replacer, $10);
		strcat(replacer, "_i]");
		//strcpy(replacer, $10);
		replaceWord(expression, toBeReplaced, replacer);
		$$ = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i)\n%s[%s_i] = %s", $15, $1, $15, $12, $15, $10, $10, $12, $10, $1, $10, expression);
		}
	;

comp_declarations:
	comp_declaration ';' {$$ = template("%s", $1);}
	| comp_declarations comp_declaration ';' {$$ = template("%s \n%s", $1, $2);}
	;

comp_declaration:
	KW_COMP TK_IDENT ':' listof_comp_instructions KW_ENDCOMP 
	{	for(int i=0; i< numOfCompFuncs; i++){
			if(i>0) strcat(helper_comp_func, ", ");
			strcat(helper_comp_func, ".");
			strcat(helper_comp_func, comp_funcs[i]);
			strcat(helper_comp_func, "=");
			strcat(helper_comp_func, comp_funcs[i]);
		}
		$$ = template("#define SELF struct %s *self\ntypedef struct %s{\n%s\n}%s;\n\n%s\n\nconst %s ctor_%s = {%s};\n#undef SELF\n",$2, $2, $4, $2, comp_func_to_C, $2, $2, helper_comp_func);
		comps[numOfComps] = $2;
		numOfComps++;
		insideCompDecl = 0;
		for(int i=numOfCompVars; i>=0; i--){
			comp_vars[i] = '\0';
		}
		numOfCompVars = 0;
		for(int i=numOfCompFuncs; i>=0; i--){
			comp_funcs[i] = '\0';
		}
		numOfCompFuncs = 0;
		strcpy(comp_func_to_C, "\0");
		strcpy(helper_comp_func, "\0");
	}
	;

listof_comp_instructions:
	//comp_var_declarations	{$$ = template("%s", $1);}
	//| comp_function_blocks	{$$ = template("%s", $1);}
	comp_var_declarations function_blocks {$$ = template("%s\n%s", $1, $2);}
	;

comp_var_declarations:
	comp_var_declaration ';' {$$ = template("%s;", $1); insideCompDecl = 1;}
	| comp_var_declarations comp_var_declaration ';' { $$ = template("%s \n%s;", $1, $2);}
	;


comp_var_declaration:
	'#' one_var {
				$$ = template("%s", $2); comp_vars[numOfCompVars] = comp_var_name; numOfCompVars++;
				all_comp_vars[numOfAllCompVars] = comp_var_name; numOfAllCompVars++;
				}
	| comp_multi_var {$$ = template("%s", $1);}
	;

comp_multi_var:
	comp_multi_var_1 {$$ = template("%s", $1);}		//a, b :type
	| comp_multi_var_2 {$$ = template("%s", $1);}	//a[N], b[N]: type
	| comp_multi_var_3 {$$ = template("%s", $1);}	//a[], b[]: type
	;

comp_multi_var_3:
	'#' TK_IDENT '[' ']' ',' '#' TK_IDENT '[' ']' ':' data_type {	if(isStr == 1){
																		$$ = template("%s* %s, **%s", $11, $2, $7);
																	}
																	else{
																		$$ = template("%s* %s, *%s", $11, $2, $7);
																	}
										comp_vars[numOfCompVars] = $2; numOfCompVars++;
										comp_vars[numOfCompVars] = $7; numOfCompVars++;
										all_comp_vars[numOfAllCompVars] = $2; numOfAllCompVars++;
										all_comp_vars[numOfAllCompVars] = $7; numOfAllCompVars++;
										}
	| '#' TK_IDENT '[' ']' ',' comp_multi_var_3  {	if(isStr == 1){
														$$ = template("%s, **%s", $6, $2);
													}
													else{
														$$ = template("%s, *%s", $6, $2);
													}
										comp_vars[numOfCompVars] = $2; numOfCompVars++;
										all_comp_vars[numOfAllCompVars] = $2; numOfAllCompVars++;
										}
	; 

comp_multi_var_2:
	'#' TK_IDENT '[' TK_CONSTINT ']' ',' '#' TK_IDENT '[' TK_CONSTINT ']' ':' data_type {if(isStr == 1){
											$$ = template("%s %s[%s], *%s[%s]", $13, $2, $4, $8, $10);
										}
										else{
											$$ = template("%s %s[%s], %s[%s]", $13, $2, $4, $8, $10);
										}
										comp_vars[numOfCompVars] = $2; numOfCompVars++;
										comp_vars[numOfCompVars] = $8; numOfCompVars++;
										all_comp_vars[numOfAllCompVars] = $2; numOfAllCompVars++;
										all_comp_vars[numOfAllCompVars] = $8; numOfAllCompVars++;
										}
	| '#' TK_IDENT '[' TK_CONSTINT ']' ',' comp_multi_var_2 {	if(isStr == 1){
																	$$ = template("%s, *%s[%s]", $7, $2, $4);
																}
																else{
																	$$ = template("%s, %s[%s]", $7, $2, $4);
																}
								comp_vars[numOfCompVars] = $2; numOfCompVars++;
								all_comp_vars[numOfAllCompVars] = $2; numOfAllCompVars++;
								}
	; 

comp_multi_var_1:
	'#' TK_IDENT ',' '#' TK_IDENT ':' data_type {if (isStr == 1){
											$$ = template("%s %s, *%s", $7, $2, $5);
										}
										else{
											if(isComp == 1){
												$$ = template("%s %s = ctor_%s, %s = ctor_%s", $7, $2, $7, $5, $7);
											}else
											$$ = template("%s %s, %s", $7, $2, $5);
										}
										comp_vars[numOfCompVars] = $2; numOfCompVars++;
										comp_vars[numOfCompVars] = $5; numOfCompVars++;
										all_comp_vars[numOfAllCompVars] = $2; numOfAllCompVars++;
										all_comp_vars[numOfAllCompVars] = $5; numOfAllCompVars++;
										}
	| '#' TK_IDENT ',' comp_multi_var_1 {	if(isStr == 1){
												$$ = template("%s, *%s", $4, $2);
											}
											else{
												if(isComp == 1){
													$$ = template("%s, %s = ctor_%s", $4, $2, temp);
												}else
												$$ = template("%s, %s", $4, $2);
											}
								comp_vars[numOfCompVars] = $2; numOfCompVars++;
								all_comp_vars[numOfAllCompVars] = $2; numOfAllCompVars++;
								}
	;
/*
comp_function_blocks:
	comp_function_block ';' {$$ = template("%s", $1);}
	| comp_function_blocks comp_function_block ';' {$$ = template("%s\n%s", $1, $2);}
	;

comp_function_block:
	KW_DEF TK_IDENT '(' function_param_decl ')' ':' listofinstructions KW_ENDDEF {$$ = template("void %s(%s){\n%s\n}", $2, $4, $7);}
	| KW_DEF TK_IDENT '(' function_param_decl ')' ':' listofinstructions KW_RETURN ';' KW_ENDDEF {$$ = template("void %s(%s){\n%s\nreturn;\n}", $2, $4, $7);}
	| KW_DEF TK_IDENT '(' function_param_decl ')' ':'  KW_RETURN ';' KW_ENDDEF {$$ = template("void %s(%s){\nreturn;\n}", $2, $4);}
	| KW_DEF TK_IDENT '(' function_param_decl ')' function_return_type ':' listofinstructions KW_RETURN  expr ';' KW_ENDDEF {$$ = template("%s %s(%s){\n%s\nreturn %s;\n}", $6, $2, $4, $8, $10);}
	| KW_DEF TK_IDENT '(' function_param_decl ')' function_return_type ':'  KW_RETURN  expr ';' KW_ENDDEF {$$ = template("%s %s(%s){\nreturn %s;\n}", $6, $2, $4, $9);}
	;
	
*/

const_declarations:
	const_declaration ';' {$$ = template("%s;", $1);}
	| const_declarations const_declaration ';' {$$ = template("%s \n%s;", $1, $2);}
	;
	
const_declaration:
	KW_CONST TK_IDENT '=' TK_CONSTFLOAT ':' KW_SCALAR {$$ = template("const double %s = %s", $2, $4);}
	| KW_CONST TK_IDENT '=' '+' TK_CONSTFLOAT ':' KW_SCALAR {$$ = template("const double %s = %s", $2, $5);}
	| KW_CONST TK_IDENT '=' '-' TK_CONSTFLOAT ':' KW_SCALAR {$$ = template("const double %s = -%s", $2, $5);}
	|	KW_CONST TK_IDENT '=' TK_CONSTINT ':' KW_INTEGER {$$ = template("const int %s = %s", $2, $4);}
	|	KW_CONST TK_IDENT '=' '+' TK_CONSTINT ':' KW_INTEGER {$$ = template("const int %s = %s", $2, $5);}
	|	KW_CONST TK_IDENT '=' '-' TK_CONSTINT ':' KW_INTEGER {$$ = template("const int %s = -%s", $2, $5);}
	|	KW_CONST TK_IDENT '=' TK_CONSTSTR ':' KW_STR {$$ = template("const char* %s = %s", $2, $4);}
	|	KW_CONST TK_IDENT '=' KW_TRUE ':' KW_BOOLEAN {$$ = template("const int %s = 1", $2);}
	|	KW_CONST TK_IDENT '=' KW_FALSE ':' KW_BOOLEAN {$$ = template("const int %s = 0", $2);}
	;


var_declarations:
	var_declaration ';' {$$ = template("%s;", $1);}
	| var_declarations var_declaration ';' { $$ = template("%s \n%s;", $1, $2);}
	;

var_declaration:
	one_var {$$ = template("%s", $1);}
	| multi_var {$$ = template("%s", $1);}
	;

one_var:
	TK_IDENT ':' data_type {if(isComp == 1){
							$$ = template("%s %s = ctor_%s", $3, $1, $3);
							}else{
							$$ = template("%s %s", $3, $1);}
							comp_var_name = $1;	//maybe not a comp var, but i need it if it is
							 }
	| TK_IDENT '[' TK_CONSTINT ']' ':' data_type {	$$ = template("%s %s[%s]", $6, $1, $3);	comp_var_name = $1;}
	| TK_IDENT '[' ']' ':' data_type {$$ = template("%s* %s", $5, $1); comp_var_name = $1;}
	;

multi_var:
	multi_var_1 {$$ = template("%s", $1);}		//a, b :type
	| multi_var_2 {$$ = template("%s", $1);}	//a[N], b[N]: type
	| multi_var_3 {$$ = template("%s", $1);}	//a[], b[]: type
	;

multi_var_3:
	TK_IDENT '[' ']' ',' TK_IDENT '[' ']' ':' data_type {if(isStr == 1){
											$$ = template("%s* %s, **%s", $9, $1, $5);
										}
										else{
											$$ = template("%s* %s, *%s", $9, $1, $5);
										}}
	| TK_IDENT '[' ']' ',' multi_var_3  {if(isStr == 1){
											$$ = template("%s, **%s", $5, $1);
										}
										else{
											$$ = template("%s, *%s", $5, $1);
										}}
	; 

multi_var_2:
	TK_IDENT '[' TK_CONSTINT ']' ',' TK_IDENT '[' TK_CONSTINT ']' ':' data_type {if(isStr == 1){
											$$ = template("%s %s[%s], *%s[%s]", $11, $1, $3, $6, $8);
										}
										else{
											$$ = template("%s %s[%s], %s[%s]", $11, $1, $3, $6, $8);
										}}
	| TK_IDENT '[' TK_CONSTINT ']' ',' multi_var_2  	{if(isStr == 1){
									$$ = template("%s, *%s[%s]", $6, $1, $3);
								}
								else{
									$$ = template("%s, %s[%s]", $6, $1, $3);
								}}
	; 

multi_var_1:
	TK_IDENT ',' TK_IDENT ':' data_type {if (isStr == 1){
											$$ = template("%s %s, *%s", $5, $1, $3);
										}
										else{
											if(isComp == 1){
												$$ = template("%s %s = ctor_%s, %s = ctor_%s", $5, $1, $5, $3, $5);
											}else
											$$ = template("%s %s, %s", $5, $1, $3);
										}}
	| TK_IDENT ',' multi_var_1  	{if(isStr == 1){
									$$ = template("%s, *%s", $3, $1);
								}
								else{
									if(isComp == 1){
										$$ = template("%s, %s = ctor_%s", $3, $1, temp);
									}else
									$$ = template("%s, %s", $3, $1);
								}}
	; 

data_type:
	KW_INTEGER {$$ = template("int"); isComp = 0; isStr = 0;}
	| KW_SCALAR {$$ = template("double"); isComp = 0; isStr = 0;}
	| KW_STR {$$ = template("char*"); isComp = 0; isStr = 1;}
	| KW_BOOLEAN  {$$ = template("int"); isComp = 0; isStr = 0;}
	| TK_IDENT { isStr = 0;
					if(find_comp($1, "comps") == 1){		//allow Comp data_type only if it is already declared 
					isComp = 1;
					$$ = template("%s", $1);
					}else{
						yyerror("Unknown data type");
					}

				}
	;


%%
void replaceWord(char* str, char* oldWord, char* newWord)
{
	char *pos, temp[1000];
	int index = 0;
	int owlen;

	owlen = strlen(oldWord);

	// Repeat This loop until all occurrences are replaced.

	while ((pos = strstr(str, oldWord)) != NULL) {
		// Bakup current line
		strcpy(temp, str);

		// Index of current found word
		index = pos - str;

		// Terminate str after word found index
		str[index] = '\0';

		// Concatenate str with new word
		strcat(str, newWord);

		// Concatenate str with remaining words after
		// oldword found index.
		strcat(str, temp + index + owlen);
	}
}

int find_comp(char* compToSearch, char* whereToSearch){
	if(strcmp(whereToSearch, "comps") == 0){	//search in list of comps declared
		for(int i = 0; i< numOfComps; i++){
			if(strcmp(compToSearch, comps[i]) == 0){
				temp = compToSearch;
				return 1;	//comp exists
			}
		}
		return 0; //comp does not exist
	}
	else if(strcmp(whereToSearch, "comp_vars") == 0){
		for(int i = 0; i< numOfCompVars; i++){
			if(strcmp(compToSearch, comp_vars[i]) == 0){
				return 1;	//comp var exists
			}
		}
		return 0; //comp var does not exist
	}
	else if(strcmp(whereToSearch, "all_comp_vars") == 0){
		for(int i = 0; i< numOfAllCompVars; i++){
			if(strcmp(compToSearch, all_comp_vars[i]) == 0){
				return 1;	//comp var exists
			}
		}
		return 0; //comp var does not exist
	}
	else{
		yyerror("Unknown Comp / Comp variable");
		return -1;
	}
}

int main ()
{
	comps[0] = "Adress";
	yyparse();
}


