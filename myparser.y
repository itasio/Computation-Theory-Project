%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
  	#include "cgen.h"
	
	extern int yylex(void);
	int i1, i2;
	double d1, d2;

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

%type <str> statements listofexpr listofinstructions  main_block function_blocks var_declarations const_declarations /*comp_declarations*/
%type <str> statement in_loop_stmts if_statement while_statement for_statement expr data_type const_declaration var_declaration function_block //array

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
	| var_declarations function_blocks main_block 										{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", $1, $2, $3);}}
	| const_declarations var_declarations function_blocks main_block						{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", $1, $2, $3, $4);}}
	/*| comp_declarations const_declarations var_declarations function_blocks main_block	{if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s\n%s", $1, $2, $3, $4, $5);}}
	*/;

main_block:
	KW_DEF KW_MAIN '(' ')' ':' KW_ENDDEF ';' { printf("q");$$ = template("int main(){}");}
	| KW_DEF KW_MAIN '(' ')' ':' listofinstructions KW_ENDDEF ';' { printf("w");$$ = template("int main(){\n%s\n}",$6);}
	;

function_blocks:
	function_block ';' {$$ = template("%s", $1);}
	| function_blocks function_block ';' {$$ = template("%s \n%s", $1, $2);}
	;

function_block:
	KW_DEF TK_IDENT '(' ')' ':' listofinstructions KW_ENDDEF {$$ = template("void %s(){\n%s\n}", $2, $6);}
	| KW_DEF TK_IDENT '(' ')' ':' listofinstructions KW_RETURN ';' KW_ENDDEF {$$ = template("void %s(){\n%s\nreturn;\n}", $2, $6);}
	| KW_DEF TK_IDENT '(' ')' ':'  KW_RETURN ';' KW_ENDDEF {$$ = template("void %s(){\nreturn;\n}", $2);}
	| KW_DEF TK_IDENT '(' ')' ':' listofinstructions KW_RETURN  expr ';' KW_ENDDEF {$$ = template("void %s(){\n%s\nreturn %s;\n}", $2, $6, $8);}
	| KW_DEF TK_IDENT '(' ')' ':'  KW_RETURN  expr ';' KW_ENDDEF {$$ = template("void %s(){\nreturn %s;\n}", $2, $7);}
	;//todo na return xwris na epistrefei timh mono otan den exei dhlw8ei typos epistrofhs
	 //na ftiaxw kai tis synarthseis me typo epistrofhs

listofexpr:
	expr {$$ = template("%s", $1);}
	| listofexpr expr {$$ = template("%s \n%s", $1, $2); }
	;

expr:
	TK_CONSTINT
	| TK_CONSTFLOAT
	| TK_IDENT
	//| TK_IDENT '=' expr {$$ = template("%s = %s",$1, $3);}
	//| TK_IDENT TK_PLUEQ expr {$$ = template("%s += %s",$1, $3);}
	//| TK_IDENT TK_MINEQ expr {$$ = template("%s -= %s",$1, $3);}
	//| TK_IDENT TK_MULEQ expr {$$ = template("%s *= %s",$1, $3);}
	//| TK_IDENT TK_DIVEQ expr {$$ = template("%s /= %s",$1, $3);}
	//| TK_IDENT TK_MODEQ expr {$$ = template("%s %= %s",$1, $3);}
	//| TK_IDENT TK_COLEQ expr {$$ = template("%s := %s",$1, $3);}
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
	| TK_IDENT '[' expr ']' {$$ = template("%s[%s]", $1, $3);}
	| expr '.' expr {$$ = template("%s.%s", $1, $3);}
	;

listofinstructions:
	var_declarations const_declarations statements {$$ = template("%s\n%s\n%s",$1, $2, $3);}
	| const_declarations var_declarations statements {$$ = template("%s\n%s\n%s",$1, $2, $3);}
	| statements {$$ = template("%s",$1);}
	;



statements:
	statement  { $$ = template("%s", $1);}
	| statements statement { $$ = template("%s \n%s", $1, $2); }
	;

statement:
	TK_IDENT '=' listofexpr ';' {$$ = template("%s = %s;",$1, $3);}
	| TK_IDENT TK_PLUEQ expr ';' {$$ = template("%s += %s;",$1, $3);}
	| TK_IDENT TK_MINEQ expr ';' {$$ = template("%s -= %s;",$1, $3);}
	| TK_IDENT TK_MULEQ expr ';' {$$ = template("%s *= %s;",$1, $3);}
	| TK_IDENT TK_MODEQ expr ';' {$$ = template("%s %= %s;",$1, $3);}
	| TK_IDENT TK_DIVEQ expr ';' {$$ = template("%s /= %s;",$1, $3);}
	| TK_IDENT TK_COLEQ expr ';' {$$ = template("%s := %s;",$1, $3);}
	| if_statement ';' {$$ = template("%s",$1);}
	| for_statement ';' {$$ = template("%s",$1);}
	| while_statement ';' {$$ = template("%s",$1);}
	| KW_BREAK ';' {$$ = template("break;");}
	| KW_CONTINUE ';' {$$ = template("continue;");}
	| ';' {$$ = template("");}
	;

if_statement:
	KW_IF '(' listofexpr ')' ':' statements KW_ENDIF {$$ = template("if(%s){\n%s\n}", $3, $6);}
	| KW_IF '(' listofexpr ')' ':' KW_ENDIF {$$ = template("if(%s){\n}", $3);}
	| KW_IF '(' listofexpr ')' ':' statements KW_ELSE ':' statements KW_ENDIF {$$ = template("if(%s){\n%s\n}\nelse{\n%s\n}", $3, $6, $9);}
	| KW_IF '(' listofexpr ')' ':'  KW_ELSE ':' statements KW_ENDIF {$$ = template("if(%s){\n}\nelse{\n%s\n}", $3, $8);}
	| KW_IF '(' listofexpr ')' ':' statements KW_ELSE ':'  KW_ENDIF {$$ = template("if(%s){\n%s\n}\nelse{\n}", $3, $6);}
	| KW_IF '(' listofexpr ')' ':' KW_ELSE ':'  KW_ENDIF {$$ = template("if(%s){\n}\nelse{\n}", $3);}
	;
/*
in_loop_stmts:
	statements {$$ = template("%s", $1);}
	| KW_BREAK {$$ = template("break;");}
	| KW_CONTINUE {$$ = template("continue;");}
	;
*/



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
	var_declaration ';' {$$ = template("%s;", $1);}
	| var_declarations var_declaration ';' {$$ = template("%s \n%s;", $1, $2);}
	;

var_declaration:
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
