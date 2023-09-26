%{

	#include "myparser.tab.h"
	#include "cgen.h"	
	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	int line_num = 1;
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
													//printf("token CONST_STRING: %s\n", string_buf);
													yylval.str = strdup(string_buf);
													for(;j>=0;j--){
														string_buf[j] = '\0';
													}
													return TK_CONSTSTR;
													}
													
"and"		return KW_AND;
"or"		return KW_OR;
"not"		return KW_NOT;														
"integer"	return KW_INTEGER;
"for"		return KW_FOR;
"break"		return KW_BREAK;
"def"		return KW_DEF;
"endcomp"	return KW_ENDCOMP;
"scalar"	return KW_SCALAR;
"const"		return KW_CONST;
"in"		return KW_IN;
"continue"	return KW_CONTINUE;
"enddef"	return KW_ENDDEF;
"of"		return KW_OF;
"str"		return KW_STR;
"if"		return KW_IF;
"endfor"	return KW_ENDFOR;
"main"		return KW_MAIN;
"boolean"	return KW_BOOLEAN;
"else"		return KW_ELSE;
"while"		return KW_WHILE;
"return"	return KW_RETURN;
"endif"		return KW_ENDIF;
"endwhile"	return KW_ENDWHILE;
"comp"		return KW_COMP;
"True"		return KW_TRUE;
"False"		return KW_FALSE;
{CONST_INT}								{yylval.str = strdup(yytext); return TK_CONSTINT;}
{CONST_FLOAT}							{yylval.str = strdup(yytext); return TK_CONSTFLOAT;}
{IDENTIFIER}							{yylval.str = strdup(yytext); return TK_IDENT;}

"+"			return '+';
"-"			return '-';
"*"			return '*';
"/"			return '/';
"%"			return '%';
"="			return '=';
"#"			return '#';	
"**"									return TK_POW;
"+="									return TK_PLUEQ;
"-="									return TK_MINEQ;
"*="									return TK_MULEQ;
"/="									return TK_DIVEQ;
"%="									return TK_MODEQ;
":="									return TK_COLEQ;
"=="									return TK_EQEQ;
"!="									return TK_NOTEQ;
">="									return TK_GREEQ;
"<="									return TK_LESEQ;
"->"									return TK_FUNC_RET;
"<"			return '<';
">"			return '>';
";"			return ';';
"("			return '(';
")"			return ')';
","			return ',';
"["			return '[';
"]"			return ']';
":"			return ':';
"."			return '.';

[ \r\t]+		/* eat whitespace */
"--"[^\n]*  	/* eat line comments */
\n 				++line_num;

<<EOF>> 	return EOF;
.           { yyerror("lexical error: unrecognized literal '%s'\n", yytext);}


%%
