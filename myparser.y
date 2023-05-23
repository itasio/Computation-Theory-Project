%{
	#include <stdio.h>
  	#include "cgen.h"
	
	extern int yylex(void);
%}

%union {
	char* str;
}

%token <str> TK_IDENT 
%token <str> TK_CONSTINT 
%token <str> TK_CONSTFLOAT 


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

%start input

%type <str> listOfExprs expr

%left '+' '-' 
%left '*' '/'

%%

input: 
	listOfExprs  
	{
		if (yyerror_count == 0) {
			//puts(c_prologue);
			printf("here\n");
			printf("%s\n", $1);
			printf("there\n");	
		}
	}
	;

listOfExprs: 
	expr 
	| listOfExprs ',' expr { $$ = template("%s\n%s", $1, $3);}
	;
	
expr:
	TK_INT
	| TK_REAL 
	| TK_IDENT
	| expr '+' expr { $$ = template("%s %s +", $1, $3); }
	| expr '-' expr { $$ = template("%s %s -", $1, $3); }
	| expr '*' expr { $$ = template("%s %s *", $1, $3); }
	| expr '/' expr { $$ = template("%s %s /", $1, $3); }
	| '(' expr ')' { $$ = template("%s", $2); }
	;
	
%%
int main ()
{
   if ( yyparse() == 0 )
		printf("Accepted!\n");
	else
		printf("Rejected!\n");
}
