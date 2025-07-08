%{
    #ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "parser.tab.h"
#include "ast.h"

#define COLOR_RESET   "\033[0m"
#define ZELENA     "\033[32m"  
#define COLOR_ERROR   "\033[31m" 

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

"QUERY"            { printf(" " ZELENA"Keyword:"COLOR_RESET "QUERY" "\n"); return QUERY; }
"RESULT_OF_QUERY"  { printf(" " ZELENA"Keyword:"COLOR_RESET " RESULT_OF_QUERY"  "\n"); return RESULT_OF_QUERY; }
"EXEC"             { printf(" " ZELENA"Keyword:"COLOR_RESET " EXEC"  "\n"); return EXEC; }
"IF"               { printf(" " ZELENA"Keyword:"COLOR_RESET " IF"  "\n"); return IF; }
"BEGIN"            { printf(" " ZELENA"Keyword:"COLOR_RESET " BEGIN"  "\n"); return BEGIN_KW; }
"END"              { printf(" " ZELENA"Keyword:"COLOR_RESET " END"  "\n"); return END_KW; }
"FOR"              { printf(" " ZELENA"Keyword:"COLOR_RESET " FOR"  "\n"); return FOR; }
"IN"               { printf(" " ZELENA"Keyword:"COLOR_RESET " IN"  "\n"); return IN; }
"EMPTY"            { printf(" " ZELENA"Keyword:"COLOR_RESET " EMPTY"  "\n"); return EMPTY; }
"URL_EXISTS"       { printf(" " ZELENA"Keyword:"COLOR_RESET " URL_EXISTS"  "\n"); return URL_EXISTS; }
"NOT_EMPTY"        { printf(" " ZELENA"Keyword:"COLOR_RESET " NOT_EMPTY"  "\n"); return NOT_EMPTY; }

"++"               { printf(" " ZELENA"Token:"COLOR_RESET " ++"  "\n"); return SET_UNION; }
"--"               { printf(" " ZELENA"Token:"COLOR_RESET " --"  "\n"); return SET_DIFFERENCE; }
"**"               { printf(" " ZELENA"Token:"COLOR_RESET " **"  "\n"); return SET_INTERSECTION; }
"^^"               { printf(" " ZELENA"Token:"COLOR_RESET " ^^"  "\n"); return POW; }

"+"                { printf(" " ZELENA"Token:"COLOR_RESET " +"  "\n"); return PLUS; }
"-"                { printf(" " ZELENA"Token:"COLOR_RESET " -"  "\n"); return MINUS; }
"*"                { printf(" " ZELENA"Token:"COLOR_RESET " *"  "\n"); return MULT; }
"|"                { printf(" " ZELENA"Token:"COLOR_RESET " |"  "\n"); return OR; }

"<"                { printf(" " ZELENA"Token:"COLOR_RESET " <"  "\n"); return LT; }
">"                { printf(" " ZELENA"Token:"COLOR_RESET " >"  "\n"); return GT; }
"["                { printf(" " ZELENA"Token:"COLOR_RESET " ["  "\n"); return LBRACKET; }
"]"                { printf(" " ZELENA"Token:"COLOR_RESET " ]"  "\n"); return RBRACKET; }
"("                { printf(" " ZELENA"Token:"COLOR_RESET " ("  "\n"); return LPAREN; }
")"                { printf(" " ZELENA"Token:"COLOR_RESET " )"  "\n"); return RPAREN; }
","                { printf(" " ZELENA"Token:"COLOR_RESET " ,"  "\n"); return COMMA; }
";"                { printf(" " ZELENA"Token:"COLOR_RESET " ;"  "\n"); return SEMICOLON; }
":"                { printf(" " ZELENA"Token:"COLOR_RESET " :"  "\n"); return COLON; }
"="                { printf(" " ZELENA"Token:"COLOR_RESET " ="  "\n"); return EQUALS; }
"-="               { printf(" " ZELENA"Token:"COLOR_RESET "-="  "\n"); return MINUS_EQ; }

\"[^\"]*\"         { yylval.str = my_strdup(yytext); printf(" " ZELENA"Token:"COLOR_RESET " STRING %s"  "\n", yytext); return STRING; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = my_strdup(yytext);
    printf(" " ZELENA"Token:"COLOR_RESET "  %s"  "\n", yytext);
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