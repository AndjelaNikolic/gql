#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yyparse();
extern ASTNode *root;
extern FILE *yyin;

#define COLOR_RESET   "\033[0m"
#define COLOR_ID      "\033[32m"  

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening input file");
        return 1;
    }

    if (yyparse() == 0) {
        printf(COLOR_ID"AST:"COLOR_RESET"\n");
        int levels[100] = {0};
        printAST(root, 0, 1, levels);
    } else {
        fprintf(stderr, "Parsing failed!\n");
    }
    
    freeAST(root);
    fclose(yyin);
    return 0;
}