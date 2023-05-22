%{

	#include "myparser.tab.h"
	#include "cgen.h"	
	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	int lineNum = 1;
	int j;
	int MAX_STR_CONST = 500;
%}

DIGIT			[0-9]
IDENTIFIER		[a-zA-Z][a-zA-Z0-9_]*
CONST_INT		0|([1-9]{DIGIT}*)
CONST_FLOAT		{CONST_INT}"."({DIGIT}+)(([eE][+-]?{CONST_INT})?)


%x string


%%
													char string_buf[MAX_STR_CONST];

\"													{BEGIN(string); string_buf[0]='"'; string_buf[1]='\0';}
<string>\\+\"										strcat(string_buf, yytext);
<string>[a-zA-Z0-9+-/*=:_$%!#@&~^()., \n\t\r\\] 		strcat(string_buf, yytext);
<string>\"											{BEGIN(INITIAL);
													j=strlen(string_buf);			/*Placing " in the end of string*/
													string_buf[j]='"';
													j++;
													string_buf[j]='\0';
													printf("token CONST_STRING: %s\n", string_buf);
													for(;j>=0;j--){
														string_buf[j] = '\0';
													}
													return TK_CONSTSTR;}
													
"and"|"or"|"not"							{printf("token LOGICAL_OP: "); return TK_LOGICAL;}																		
"integer"|"for"|"break"|"def"|"endcomp"|"scalar"|"const"|"in"|"continue"|"enddef"|"of"|"str"|"if"|"endfor"|"main"|"boolean"|"else"|"while"|return"|"endif"|"endwhile"|comp"			{ printf("token KEYWORD: "); return TK_KEYWORD;}
"True"										{printf("token CONST_BOOL: "); return TK_CONSTBOOL;}
"False"										{printf("token CONST_BOOL: "); return TK_CONSTBOOL;}
{CONST_INT}									{printf("token CONST_INT: "); return TK_CONSTINT;}
{CONST_FLOAT}								{printf("token CONST_FLOAT: "); return TK_CONSTFLOAT;}
{IDENTIFIER}								{printf("token IDENTIFIER: "); return TK_IDENT;}
"+"|"-"|"*"|"/"|"%"|"**"					{printf("token ARITHMETIC_OP: "); return TK_ARITHMETIC;}
"="|"+="|"-="|"*="|"/="|"%="				{printf("token ASSIGN_OP: "); return TK_ASSIGN;}
"=="|"!="|"<"|"<="|">"|">="					{printf("token RELATIONAL_OP: "); return TK_RELATIONAL;}
";"|"("|")"|","|"["|"]"|":"|"."				{printf("token DELIMITER: "); return TK_DELIMITER;}

[ \r\t]+		/* eat whitespace */
"--"[^\n]*  	/* eat line comments */
\n 				{++lineNum; return TK_NEWLINE;}

<<EOF>> 	return EOF;
.           { printf("Unrecognized token %s in line: %d ", yytext, lineNum); return TK_ERROR;}


%%
