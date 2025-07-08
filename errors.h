#ifndef ERRORS_H
#define ERRORS_H

typedef struct {
    int line;
    int column;
} SourcePosition;

void report_syntax_error(const char* msg, int line, int column);
void report_lexical_error(const char* msg, int line, int column);
void report_semantic_error(const char* msg, int line, int column);

#endif