mylexer : flex_c_file
flex_c_file : lex_file
	gcc -o mylexer lex.yy.c -lfl
lex_file :
	flex lexer-pr.l