myparser : lex_file
	gcc -o mycompiler lex.yy.c myparser.tab.c cgen.c -lfl
lex_file : parser_files
	flex mylexer.l
parser_files :
	bison -d -v -r all myparser.y