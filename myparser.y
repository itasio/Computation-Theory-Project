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

%type <str> listOfExprs expr main_block function_block

%left '+' '-' 
%left '*' '/'

%%

program:
	main_block {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", $1);}}
	| main_block function_block {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", $1, $2);}}
	;

main_block:
	KW_DEF KW_MAIN '(' ')' ':' KW_ENDDEF ';' { printf("q");$$ = template("int main(){}");}
	| KW_DEF KW_MAIN '(' ')' ':' listOfExprs KW_ENDDEF ';' { printf("w");$$ = template("int main(){\n%s\n}",$6);}
	;

function_block:
	KW_DEF TK_IDENT '(' ')' ':' listOfExprs KW_ENDDEF ';' { printf("e");$$ = template("void %s(){\n%s}", $2, $6);}
	| KW_DEF TK_IDENT '(' ')' ':' listOfExprs KW_RETURN ';' KW_ENDDEF ';' { printf("r");$$ = template("void %s(){\n%s\nreturn;}", $2, $6);}
	;
	
listOfExprs:
	expr ';' {$$ = template("%s;", $1);}
	| listOfExprs expr ';' { printf("t"); $$ = template("%s \n%s;", $1, $2); }
	;

expr:
	TK_IDENT '=' TK_CONSTINT { printf("y");$$ = template("%s=%s",$1, $3);}
	;

%%
int main ()
{
   if ( yyparse() == 0 )
		printf("Accepted!\n");
	else
		printf("Rejected!\n");
}
