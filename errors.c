#include "errors.h"
#include <stdio.h>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void report_syntax_error(const char* msg, int line, int column) {
    fprintf(stderr, RED "Sintaksna greška na liniji %d, kolona %d: %s\n" RESET, line, column, msg);
}

void report_lexical_error(const char* msg, int line, int column) {
    fprintf(stderr, RED "Leksička greška na liniji %d, kolona %d: %s\n" RESET, line, column, msg);
}

void report_semantic_error(const char* msg, int line, int column) {
    fprintf(stderr, RED "Semantička greška na liniji %d, kolona %d: %s\n" RESET, line, column, msg);
}