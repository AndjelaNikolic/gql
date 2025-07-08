#include "ast.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

extern int yyparse();
extern ASTNode *root;
extern FILE *yyin;
extern int syntax_error;
#define COLOR_RESET   "\033[0m"
#define ZELENA     "\033[32m"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Greska prilikom otvaranja fajla");
        return 1;
    }

    if (yyparse() == 0 && !syntax_error) {
        printf(ZELENA"\nAST:\n"COLOR_RESET);
        int levels[100] = {0};
        printAST(root, 0, 1, levels);
    } else {
        fprintf(stderr, "\nGreska u parsiranju \n");
    }

    freeAST(root);
    fclose(yyin);
    return 0;
}