#define TK_ERROR -1
#define TK_NEWLINE -2
#define TK_IDENT 258
#define TK_ASSIGN 259
#define TK_PLUS 260
#define TK_KEYWORD 261
#include <math.h>
#include <stdio.h>
#include <string.h>
int lineNum = 1;

int main ()
{
   int token;
   char* str;
   char* nline = "\n";
	while ( (token = yylex()) != EOF ){
		if(token == TK_NEWLINE){
			str = "";			//have to truncate string
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