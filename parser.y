%{
#include "ast.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern void yyerror(const char *s);
extern FILE *yyin;
extern char *yytext;
extern int yylineno;

ASTNode *root;
int syntax_error = 0;

%}

%union {
    char *str;
    struct ASTNode *ast;
}

%token QUERY RESULT_OF_QUERY EXEC IF FOR IN EMPTY URL_EXISTS NOT_EMPTY
%token BEGIN_KW END_KW
%token SET_UNION SET_DIFFERENCE SET_INTERSECTION POW
%token PLUS MINUS MULT OR
%token LT GT LBRACKET RBRACKET LPAREN RPAREN COMMA SEMICOLON COLON EQUALS MINUS_EQ
%token <str> ID STRING

%type <ast> program declarations declaration
%type <ast> commands command assign_command
%type <ast> condition query terms term
%type <ast> directive list_of_queries query_list

%left OR
%left PLUS MINUS
%left MULT
%left POW
%nonassoc UMINUS

%start program

%%

program: declarations commands {
    SourceLocation loc = {yylineno, 0};
    $$ = createProgramNode($1, $2, loc);
    root = $$;
    printf("\nParsiranje uspjesno!\n");
};

declarations: declaration {
    SourceLocation loc = {yylineno, 0};
    $$ = createDeclarationsNode($1, NULL, loc);
}
| declarations declaration {
    ASTNode *tail = $1;
    while (tail->declarations.more_decls != NULL)
        tail = tail->declarations.more_decls;
    SourceLocation loc = {yylineno, 0};
    tail->declarations.more_decls = createDeclarationsNode($2, NULL, loc);
    $$ = $1;
};

declaration: QUERY ID EQUALS query SEMICOLON {
    SourceLocation loc = {yylineno, 0};
    $$ = createQueryDeclarationNode($2, $4, loc);
}
| QUERY ID EQUALS list_of_queries SEMICOLON {
    SourceLocation loc = {yylineno, 0};
    $$ = createQueryListDeclarationNode($2, $4, loc);
}
| RESULT_OF_QUERY ID SEMICOLON {
    SourceLocation loc = {yylineno, 0};
    $$ = createResultOfQueryNode($2, loc);
};

commands: command {
    SourceLocation loc = {yylineno, 0};
    $$ = createCommandsNode($1, NULL, loc);
}
| commands command {
    ASTNode *tail = $1;
    while (tail->commands.more_cmds != NULL)
        tail = tail->commands.more_cmds;
    SourceLocation loc = {yylineno, 0};
    tail->commands.more_cmds = createCommandsNode($2, NULL, loc);
    $$ = $1;
};

command: EXEC ID SEMICOLON {
    SourceLocation loc = {yylineno, 0};
    $$ = createExecCommandNode($2, loc);
}
| IF condition BEGIN_KW commands END_KW {
    SourceLocation loc = {yylineno, 0};
    $$ = createIfCommandNode($2, $4, loc);
}
| FOR ID IN list_of_queries BEGIN_KW commands END_KW {
    SourceLocation loc = {yylineno, 0};
    $$ = createForCommandNode($2, $4, $6, loc);
}
| assign_command SEMICOLON {
    $$ = $1;
};

assign_command: ID MINUS_EQ EXEC ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createAssignCommandNode($1, $4, loc);
}
| ID EQUALS EXEC ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createAssignCommandNode($1, $4, loc);
}
| ID EQUALS ID SET_UNION ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createSetOperationNode($3, $5, SET_UNION_OP, $1, loc);
}
| ID EQUALS ID SET_DIFFERENCE ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createSetOperationNode($3, $5, SET_DIFFERENCE_OP, $1, loc);
}
| ID EQUALS ID SET_INTERSECTION ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createSetOperationNode($3, $5, SET_INTERSECTION_OP, $1, loc);
};

condition: EMPTY LPAREN ID RPAREN {
    SourceLocation loc = {yylineno, 0};
    $$ = createEmptyConditionNode($3, loc);
}
| URL_EXISTS LPAREN ID COMMA STRING RPAREN {
    SourceLocation loc = {yylineno, 0};
    $$ = createUrlExistsConditionNode($3, $5, loc);
}
| NOT_EMPTY LPAREN ID RPAREN {
    SourceLocation loc = {yylineno, 0};
    $$ = createNotEmptyConditionNode($3, loc);
};

list_of_queries: LBRACKET query_list RBRACKET {
    $$ = $2;
}
| query {
    SourceLocation loc = {yylineno, 0};
    $$ = createQueryListNode($1, NULL, loc);
}
| ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createQueryListNode(createIDReferenceQueryNode($1, loc), NULL, loc);
};

query: LT terms GT {
    SourceLocation loc = {yylineno, 0};
    $$ = createQueryNode($2, loc);
}
| LT GT {  
    SourceLocation loc = {yylineno, 0};
    $$ = createQueryNode(NULL, loc);
};

query_list: query {
    SourceLocation loc = {yylineno, 0};
    $$ = createQueryListNode($1, NULL, loc);
}
| ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createQueryListNode(createIDReferenceQueryNode($1, loc), NULL, loc);
}
| query_list COMMA query {
    ASTNode *tail = $1;
    while (tail->query_list.more_queries != NULL)
        tail = tail->query_list.more_queries;
    SourceLocation loc = {yylineno, 0};
    tail->query_list.more_queries = createQueryListNode($3, NULL, loc);
    $$ = $1;
}
| query_list COMMA ID {
    ASTNode *tail = $1;
    while (tail->query_list.more_queries != NULL)
        tail = tail->query_list.more_queries;
    SourceLocation loc = {yylineno, 0};
    tail->query_list.more_queries = createQueryListNode(createIDReferenceQueryNode($3, loc), NULL, loc);
    $$ = $1;
};

terms: term {
    SourceLocation loc = {yylineno, 0};
    $$ = createTermsNode($1, NULL, loc);
}
| terms term {
    SourceLocation loc = {yylineno, 0};
    $$ = createBinaryOpNode(JUXTAPOSITION_OP, $1, $2, loc);
}
| terms OR term {
    SourceLocation loc = {yylineno, 0};
    $$ = createBinaryOpNode(OR_OP, $1, $3, loc);
}
| terms PLUS term {
    SourceLocation loc = {yylineno, 0};
    $$ = createBinaryOpNode(PLUS_OP, $1, $3, loc);
}
| terms MINUS term {
    SourceLocation loc = {yylineno, 0};
    $$ = createBinaryOpNode(MINUS_OP, $1, $3, loc);
}
| terms POW term {
    SourceLocation loc = {yylineno, 0};
    $$ = createBinaryOpNode(POW_OP, $1, $3, loc);
};

term: ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createTermNode($1, NULL, NULL, loc);
}
| directive {
    $$ = $1;
}
| PLUS term %prec UMINUS {
    SourceLocation loc = {yylineno, 0};
    $$ = createUnaryOpNode(PLUS_OP, $2, loc);
}
| MINUS term %prec UMINUS {
    SourceLocation loc = {yylineno, 0};
    $$ = createUnaryOpNode(MINUS_OP, $2, loc);
}
| LPAREN terms RPAREN {
    $$ = $2;
};

directive: ID COLON ID {
    SourceLocation loc = {yylineno, 0};
    $$ = createDirectiveNode($1, $3, loc);
};

%%

void yyerror(const char *s) {
    report_syntax_error(s, yylineno, 0);
    syntax_error = 1;
}