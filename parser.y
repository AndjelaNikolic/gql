%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylex();
extern void yyerror(const char *s);
extern FILE *yyin;
extern char *yytext;
extern int yylineno;

ASTNode *root;

#if defined(_MSC_VER) || defined(__MINGW32__)
char *strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *d = malloc(len);
    if (d) memcpy(d, s, len);
    return d;
}
#endif

%}

%union {
    char *str;
    struct ASTNode *ast;
}

%token QUERY RESULT_OF_QUERY EXEC IF FOR IN EMPTY URL_EXISTS NOT_EMPTY
%token BEGIN_KW END_KW
%token SET_UNION SET_DIFFERENCE SET_INTERSECTION
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
%nonassoc UMINUS

%start program

%%

program: declarations commands {
    $$ = createProgramNode($1, $2);
    root = $$;
    printf("\nParsiranje uspjesno!\n");
};

declarations: declaration {
    $$ = createDeclarationsNode($1, NULL);
}
| declarations declaration {
    ASTNode *new_node = createDeclarationsNode($2, NULL);
    $1->declarations.more_decls = new_node;
    $$ = $1;
};

declaration: QUERY ID EQUALS query SEMICOLON {
    $$ = createQueryDeclarationNode($2, $4);
}
| QUERY ID EQUALS list_of_queries SEMICOLON {
    $$ = createQueryListDeclarationNode($2, $4);
}
| RESULT_OF_QUERY ID SEMICOLON {
    $$ = createResultOfQueryNode($2);
};

commands: command {
    $$ = createCommandsNode($1, NULL);
}
| commands command {
    ASTNode *new_node = createCommandsNode($2, NULL);
    $1->commands.more_cmds = new_node;
    $$ = $1;
};

command: EXEC ID SEMICOLON {
    $$ = createExecCommandNode($2);
}
| IF condition BEGIN_KW commands END_KW {
    $$ = createIfCommandNode($2, $4);
}
| FOR ID IN list_of_queries BEGIN_KW commands END_KW {
    $$ = createForCommandNode($2, $4, $6);
}
| assign_command SEMICOLON {
    $$ = $1;
};

assign_command: ID MINUS_EQ EXEC ID {
    $$ = createAssignCommandNode($1, $4);
}
| ID EQUALS EXEC ID {
    $$ = createAssignCommandNode($1, $4);
}
| ID EQUALS ID SET_UNION ID {
    $$ = createSetOperationNode($3, $5, SET_UNION_OP, $1);
}
| ID EQUALS ID SET_DIFFERENCE ID {
    $$ = createSetOperationNode($3, $5, SET_DIFFERENCE_OP, $1);
}
| ID EQUALS ID SET_INTERSECTION ID {
    $$ = createSetOperationNode($3, $5, SET_INTERSECTION_OP, $1);
};

condition: EMPTY LPAREN ID RPAREN {
    $$ = createEmptyConditionNode($3);
}
| URL_EXISTS LPAREN ID COMMA STRING RPAREN {
    $$ = createUrlExistsConditionNode($3, $5);
}
| NOT_EMPTY LPAREN ID RPAREN {
    $$ = createNotEmptyConditionNode($3);
};

list_of_queries: LBRACKET query_list RBRACKET {
    $$ = $2;
}
| query {
    $$ = createQueryListNode($1, NULL);
}
| ID {
    $$ = createQueryListNode(createQueryRefNode($1), NULL);
};

query: LT terms GT {
    $$ = createQueryNode($2);
};

query_list: query {
    $$ = createQueryListNode($1, NULL);
}
| ID {
    $$ = createQueryListNode(createQueryRefNode($1), NULL);
}
| query_list COMMA query {
    ASTNode *new_node = createQueryListNode($3, NULL);
    $1->query_list.more_queries = new_node;
    $$ = $1;
}
| query_list COMMA ID {
    ASTNode *new_node = createQueryListNode(createQueryRefNode($3), NULL);
    $1->query_list.more_queries = new_node;
    $$ = $1;
};

terms: term {
    $$ = $1;
}
| terms term {
    $$ = createBinaryOpNode(JUXTAPOSITION_OP, $1, $2);
}
| terms OR term {
    $$ = createBinaryOpNode(OR_OP, $1, $3);
}
| terms PLUS term {
    $$ = createBinaryOpNode(PLUS_OP, $1, $3);
}
| terms MINUS term {
    $$ = createBinaryOpNode(MINUS_OP, $1, $3);
};

term: ID {
    $$ = createTermNode($1, NULL, NULL);
}
| directive {
    $$ = createTermNode(NULL, $1, NULL);
}
| PLUS term %prec UMINUS {
    $$ = createUnaryOpNode(PLUS_OP, $2);
}
| MINUS term %prec UMINUS {
    $$ = createUnaryOpNode(MINUS_OP, $2);
};

directive: ID COLON ID {
    $$ = createDirectiveNode($1, $3);
};

%%

void yyerror(const char *s) {
    fprintf(stderr, "\033[31mParser error at line %d near '%s': %s\033[0m\n", yylineno, yytext, s);
    exit(1);
}