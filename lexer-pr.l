%{
	#define TK_ERROR -1
	#define TK_NEWLINE -2
	#define TK_IDENT 258
	#define TK_ASSIGN 259
	#define TK_PLUS 260
	#define TK_MINUS 261
	#define TK_KEYWORD 262
	#define TK_CONSTINT 263
	#define TK_CONSTFLOAT 264
	#define TK_CONSTSTR 265
	#define TK_CONSTBOOL 266
	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	int lineNum = 1;
%}

DIGIT					[0-9]
IDENTIFIER		[a-zA-Z][a-zA-Z0-9_]*
CONST_INT		[0{DIGIT}+]
CONST_FLOAT	{CONST_INT}"."({DIGIT}+)([eE][+-]?CONST_INT)?
CONST_BOOL		["True""False"]
CONST_STR		"\"" [a-zA-Z0-9-+*/:_$%!#@&~^()., \n\t\r\\\"]+ "\""
		


%%
"integer"|"False"|"for"|"break"|"def"|"endcomp"|"scalar"|"const"|"in"|"continue"|"enddef"|"of"|"str"|"if"|"endfor"|"not"|"main"|"boolean"|"else"|"while"|"and"|return"|"True"|"endif"|"endwhile"|"or"|comp"			{ printf("Line %d token KEYWORD: ", lineNum); return TK_KEYWORD;}
"True"						{printf("token CONST_BOOL: "); return TK_CONSTBOOL;}
"False"						{printf("token CONST_BOOL: "); return TK_CONSTBOOL;}
{IDENTIFIER}			{printf("token IDENTIFIER: "); return TK_IDENT;}
{CONST_INT}			{printf("token CONST_INT: "); return TK_INTCONST;}
{CONST_FLOAT}			{printf("token CONST_FLOAT: "); return TK_CONSTFLOAT;}		
{CONST_STR}			{printf("token CONST_STR: "); return TK_CONSTSTR;}
"+"						{printf("token PLUS_OP: "); return TK_PLUS;}
"-"						{printf("token MINUS_OP: "); return TK_MINUS;}
"="						{printf("token ASSIGN_OP: "); return TK_ASSIGN;}

[ \r\t]+		/* eat whitespace */
"--"[^\n]*  	/* eat line comments */
\n 					 {++lineNum; return TK_NEWLINE;}

<<EOF>> 	return EOF;
.           { printf("Unrecognized token %s in line: %d\n", yytext, lineNum); return TK_ERROR;}


%%
int main ()
{
   int token;
   char* str;
   char* nline = "\n";
	while ( (token = yylex()) != EOF ){
		if(token == TK_NEWLINE){
			str[0] = "";			//have to truncate string
		}else{
			strcat(str, yytext);
		}
		if(token != TK_ERROR)
			printf("%s\n", yytext);
		else{
			printf("%s", str);
		}
	}
}