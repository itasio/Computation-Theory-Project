%{
	//-1 is for EOF
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
int main ()
{
   int token, i;
   int counter = 0;
   char str[MAX_STR_CONST];						//keep here the input to show whole text of line where an error has occured
   str[0]='\0';
	while ( (token = yylex()) != EOF ){
		if(token == TK_NEWLINE){		
			for(i=strlen(str);i>=0;i--){	//<<erasing>> the former line, to be ready for the next one
				str[i] = '\0';
			}
		}else{
			strcat(str, yytext);
		}
		if(token != TK_ERROR){
			if(token != TK_NEWLINE && token != TK_CONSTSTR)		//do not print new line or string literal(has already been printed)
				printf("%s\n", yytext);
		}
		else{
			printf("%s\n", str);
			return -1;
		}
	}
}