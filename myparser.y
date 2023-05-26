%{
	#include <stdio.h>
  	#include "cgen.h"
	
	extern int yylex(void);
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
%token TK_ASSIGN
%token TK_EQEQ
%token TK_NOTEQ
%token TK_GREEQ
%token TK_LESEQ

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

%type <str> listOfExprs expr main_block function_block var_declarations const_declarations /*comp_declarations*/
%type <str> data_type const_declaration //array

%left '+' '-' 
%left '*' '/'

%%

program:
	main_block 																			{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", $1);}}
	| function_block main_block  														{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", $1, $2);}}
	| var_declarations function_block main_block 										{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", $1, $2, $3);}}
	| const_declarations var_declarations function_block main_block						{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", $1, $2, $3, $4);}}
	/*| comp_declarations const_declarations var_declarations function_block main_block	{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s\n%s", $1, $2, $3, $4, $5);}}
	*/;

main_block:
	KW_DEF KW_MAIN '(' ')' ':' KW_ENDDEF ';' { printf("q");$$ = template("int main(){}");}
	| KW_DEF KW_MAIN '(' ')' ':' listOfExprs KW_ENDDEF ';' { printf("w");$$ = template("int main(){\n%s\n}",$6);}
	;

function_block:
	KW_DEF TK_IDENT '(' ')' ':' listOfExprs KW_ENDDEF ';' { printf("e");$$ = template("void %s(){\n%s\n}", $2, $6);}
	| KW_DEF TK_IDENT '(' ')' ':' listOfExprs KW_RETURN ';' KW_ENDDEF ';' { printf("r");$$ = template("void %s(){\n%s\nreturn;\n}", $2, $6);}
	; 	/*????????todo*/	
listOfExprs:
	expr ';' {$$ = template("%s;", $1);}
	| listOfExprs expr ';' { printf("t"); $$ = template("%s \n%s;", $1, $2); }
	;

expr:
	TK_CONSTINT
	| TK_CONSTFLOAT
	| expr '+' expr {$$ = $1 + $2;}
	;
	
const_declarations:
	const_declaration ';' {$$ = template("%s;", $1);}
	| const_declarations const_declaration ';' {$$ = template("%s \n%s;", $1, $2);}
	;
	
const_declaration:
	KW_CONST TK_IDENT '=' TK_CONSTFLOAT ':' KW_SCALAR {$$ = template("const double %s = %s", $2, $4);}
	|	KW_CONST TK_IDENT '=' TK_CONSTINT ':' KW_INTEGER {$$ = template("const int %s = %s", $2, $4);}
	|	KW_CONST TK_IDENT '=' TK_CONSTSTR ':' KW_STR {$$ = template("const char* %s = %s", $2, $4);}
	|	KW_CONST TK_IDENT '=' KW_TRUE ':' KW_BOOLEAN {$$ = template("const int %s = 1", $2);}
	|	KW_CONST TK_IDENT '=' KW_FALSE ':' KW_BOOLEAN {$$ = template("const int %s = 0", $2);}
	;

var_declarations:
	TK_IDENT ':' data_type {$$ = template("%s %s", $3, $1);}
	;

data_type:
	KW_INTEGER {$$ = template("int");}
	| KW_SCALAR {$$ = template("double");}
	| KW_STR {$$ = template("char*");}
	| KW_BOOLEAN  {$$ = template("int");}
	/*| array		????????????
	| KW_COMP ????????????
	*/
	;

/*array:
	'[' TK_CONSTINT ']' ':' data_type
	| '[' ']' ':' data_type
	;
*/
%%
int main ()
{
   if ( yyparse() == 0 )
		printf("Accepted!\n");
	else
		printf("Rejected!\n");
}
