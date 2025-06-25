%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"

// Color definitions
#define COLOR_RESET   "\033[0m"
#define COLOR_ID      "\033[32m"  // Green
#define COLOR_ERROR   "\033[31m"  // Red

char *my_strdup(const char *s) {
    char *d = malloc(strlen(s) + 1);
    if (d) strcpy(d, s);
    return d;
}

int curr_column = 1;

#define YY_USER_ACTION curr_column += yyleng;

void print_syntax_err(const char *msg, const char *text, int line, int column);
%}

%option noyywrap
%option nounput
%option noinput
%option yylineno

%x COMMENT

%%

"QUERY"            { printf(" " COLOR_ID "Keyword:"COLOR_RESET "QUERY" "\n"); return QUERY; }
"RESULT_OF_QUERY"  { printf(" " COLOR_ID "Keyword:"COLOR_RESET " RESULT_OF_QUERY"  "\n"); return RESULT_OF_QUERY; }
"EXEC"             { printf(" " COLOR_ID "Keyword:"COLOR_RESET " EXEC"  "\n"); return EXEC; }
"IF"               { printf(" " COLOR_ID "Keyword:"COLOR_RESET " IF"  "\n"); return IF; }
"BEGIN"            { printf(" " COLOR_ID "Keyword:"COLOR_RESET " BEGIN"  "\n"); return BEGIN_KW; }
"END"              { printf(" " COLOR_ID "Keyword:"COLOR_RESET " END"  "\n"); return END_KW; }
"FOR"              { printf(" " COLOR_ID "Keyword:"COLOR_RESET " FOR"  "\n"); return FOR; }
"IN"               { printf(" " COLOR_ID "Keyword:"COLOR_RESET " IN"  "\n"); return IN; }
"EMPTY"            { printf(" " COLOR_ID "Keyword:"COLOR_RESET " EMPTY"  "\n"); return EMPTY; }
"URL_EXISTS"       { printf(" " COLOR_ID "Keyword:"COLOR_RESET " URL_EXISTS"  "\n"); return URL_EXISTS; }
"NOT_EMPTY"        { printf(" " COLOR_ID "Keyword:"COLOR_RESET " NOT_EMPTY"  "\n"); return NOT_EMPTY; }

"++"               { printf(" " COLOR_ID "Token:"COLOR_RESET " ++"  "\n"); return SET_UNION; }
"--"               { printf(" " COLOR_ID "Token:"COLOR_RESET " --"  "\n"); return SET_DIFFERENCE; }
"**"               { printf(" " COLOR_ID "Token:"COLOR_RESET " **"  "\n"); return SET_INTERSECTION; }

"+"                { printf(" " COLOR_ID "Token:"COLOR_RESET " +"  "\n"); return PLUS; }
"-"                { printf(" " COLOR_ID "Token:"COLOR_RESET " -"  "\n"); return MINUS; }
"*"                { printf(" " COLOR_ID "Token:"COLOR_RESET " *"  "\n"); return MULT; }
"|"                { printf(" " COLOR_ID "Token:"COLOR_RESET " |"  "\n"); return OR; }

"<"                { printf(" " COLOR_ID "Token:"COLOR_RESET " <"  "\n"); return LT; }
">"                { printf(" " COLOR_ID "Token:"COLOR_RESET " >"  "\n"); return GT; }
"["                { printf(" " COLOR_ID "Token:"COLOR_RESET " ["  "\n"); return LBRACKET; }
"]"                { printf(" " COLOR_ID "Token:"COLOR_RESET " ]"  "\n"); return RBRACKET; }
"("                { printf(" " COLOR_ID "Token:"COLOR_RESET " ("  "\n"); return LPAREN; }
")"                { printf(" " COLOR_ID "Token:"COLOR_RESET " )"  "\n"); return RPAREN; }
","                { printf(" " COLOR_ID "Token:"COLOR_RESET " ,"  "\n"); return COMMA; }
";"                { printf(" " COLOR_ID "Token:"COLOR_RESET " ;"  "\n"); return SEMICOLON; }
":"                { printf(" " COLOR_ID "Token:"COLOR_RESET " :"  "\n"); return COLON; }
"="                { printf(" " COLOR_ID "Token:"COLOR_RESET " ="  "\n"); return EQUALS; }
"-="               { printf(" " COLOR_ID "Token:"COLOR_RESET "-="  "\n"); return MINUS_EQ; }

\"[^\"]*\"         { yylval.str = my_strdup(yytext); printf(" " COLOR_ID "Token:"COLOR_RESET " STRING %s"  "\n", yytext); return STRING; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = my_strdup(yytext);
    printf(" " COLOR_ID "Token:"COLOR_RESET " ID %s"  "\n", yytext);
    return ID;
}

[ \t]+              { curr_column += yyleng; }
\n                  { curr_column = 1; }
"//"                { BEGIN(COMMENT); }
<COMMENT>[^\n]*     { }
<COMMENT>\n         { curr_column = 1; BEGIN(INITIAL); }
.                   { print_syntax_err("Unsupported character", yytext, yylineno, curr_column - yyleng); }

%%

void print_syntax_err(const char *msg, const char *text, int line, int column) {
    fprintf(stderr, COLOR_ERROR "Syntax error at line %d, column %d: %s '%s'" COLOR_RESET "\n", line, column, msg, text);
    exit(1);
}