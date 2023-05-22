%{
	#include <stdio.h>
  	#include "cgen.h"
	
	extern int yylex(void);
%}

%union {
	char* str;
}

%token <str> TK_IDENT 
%token <str> TK_INT 
%token <str> TK_REAL 
%token TK_ASSGN 
%token KW_IF   
%token KW_ELSE 

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



	#define TK_ERROR -3
	#define TK_NEWLINE -2
	#define TK_IDENT 258
	#define TK_ASSIGN 259
	#define TK_ARITHMETIC 260
	#define TK_KEYWORD 261
	#define TK_CONSTINT 262
	#define TK_CONSTFLOAT 263
	#define TK_CONSTSTR 264
	#define TK_CONSTBOOL 265
	#define TK_LOGICAL 266
	#define TK_RELATIONAL 267
	#define TK_DELIMITER 268