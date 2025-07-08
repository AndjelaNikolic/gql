#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

typedef struct {
    int line;
    int column;
} SourceLocation;

typedef enum {
    PROGRAM_NODE,
    DECLARATIONS_NODE,
    QUERY_DECL_NODE,
    QUERY_LIST_DECL_NODE,
    RESULT_OF_QUERY_NODE,
    COMMANDS_NODE,
    EXEC_COMMAND_NODE,
    IF_COMMAND_NODE,
    FOR_COMMAND_NODE,
    ASSIGN_COMMAND_NODE,
    SET_OPERATION_NODE,
    QUERY_NODE,
    TERMS_NODE,
    TERM_NODE,
    DIRECTIVE_NODE,
    UNARY_OP_NODE,
    BINARY_OP_NODE,
    CONDITION_NODE,
    QUERY_LIST_NODE
} ASTNodeType;

typedef enum {
    PLUS_OP,
    MINUS_OP,
    MULT_OP,
    OR_OP,
    POW_OP,
    JUXTAPOSITION_OP,
    SET_UNION_OP,
    SET_DIFFERENCE_OP,
    SET_INTERSECTION_OP
} OperatorType;

typedef enum {
    EMPTY_COND,
    URL_EXISTS_COND,
    NOT_EMPTY_COND
} ConditionType;

typedef struct ASTNode {
    ASTNodeType type;
    SourceLocation location;
    struct ASTNode *next;
    
    union {
        struct {
            struct ASTNode *declarations;
            struct ASTNode *commands;
        } program;
        
        struct {
            struct ASTNode *declaration;
            struct ASTNode *more_decls;
        } declarations;
        
        struct {
            char *query_name;
            struct ASTNode *query;
        } query_decl;
        
        struct {
            char *result_name;
        } result_of_query;
        
        struct {
            struct ASTNode *command;
            struct ASTNode *more_cmds;
        } commands;
        
        struct {
            char *exec_name;
        } exec_command;
        
        struct {
            struct ASTNode *condition;
            struct ASTNode *if_commands;
        } if_command;
        
        struct {
            char *iterator;
            struct ASTNode *query_list;
            struct ASTNode *for_commands;
        } for_command;
        
        struct {
            char *assign_target;
            struct ASTNode *assign_source;
        } assign_command;
        
        struct {
            char *set_left;
            char *set_right;
            OperatorType set_op;
            char *set_target;
        } set_operation;
        
        struct {
            struct ASTNode *terms;
        } query;
        
        struct {
            struct ASTNode *term;
            struct ASTNode *more_terms;
        } terms;
        
        struct {
            char *term_word;
            struct ASTNode *term_directive;
            struct ASTNode *term_op;
        } term;
        
        struct {
            char *dir_key;
            char *dir_value;
        } directive;
        
        struct {
            OperatorType unary_op;
            struct ASTNode *operand;
        } unary_op;
        
        struct {
            OperatorType binary_op;
            struct ASTNode *left;
            struct ASTNode *right;
        } binary_op;
        
        struct {
            ConditionType cond_type;
            char *cond_id;
            char *cond_url;
        } condition;
        
        struct {
            struct ASTNode *query_item;
            struct ASTNode *more_queries;
        } query_list;
    };
} ASTNode;

ASTNode *createProgramNode(ASTNode *declarations, ASTNode *commands, SourceLocation loc);
ASTNode *createDeclarationsNode(ASTNode *declaration, ASTNode *more_decls, SourceLocation loc);
ASTNode *createQueryDeclarationNode(char *name, ASTNode *query, SourceLocation loc);
ASTNode *createQueryListDeclarationNode(char *name, ASTNode *query_list, SourceLocation loc);
ASTNode *createResultOfQueryNode(char *name, SourceLocation loc);
ASTNode *createCommandsNode(ASTNode *command, ASTNode *more_cmds, SourceLocation loc);
ASTNode *createExecCommandNode(char *query_name, SourceLocation loc);
ASTNode *createIfCommandNode(ASTNode *condition, ASTNode *commands, SourceLocation loc);
ASTNode *createForCommandNode(char *iterator, ASTNode *query_list, ASTNode *commands, SourceLocation loc);
ASTNode *createAssignCommandNode(char *target, char *source, SourceLocation loc);
ASTNode *createSetOperationNode(char *left, char *right, OperatorType op, char *target, SourceLocation loc);
ASTNode *createQueryNode(ASTNode *terms, SourceLocation loc);
ASTNode *createTermsNode(ASTNode *term, ASTNode *more_terms, SourceLocation loc);
ASTNode *createTermNode(char *word, ASTNode *directive, ASTNode *op_term, SourceLocation loc);
ASTNode *createDirectiveNode(char *key, char *value, SourceLocation loc);
ASTNode *createUnaryOpNode(OperatorType op, ASTNode *term, SourceLocation loc);
ASTNode *createBinaryOpNode(OperatorType op, ASTNode *left, ASTNode *right, SourceLocation loc);
ASTNode *createEmptyConditionNode(char *id, SourceLocation loc);
ASTNode *createUrlExistsConditionNode(char *id, char *url, SourceLocation loc);
ASTNode *createNotEmptyConditionNode(char *id, SourceLocation loc);
ASTNode *createQueryListNode(ASTNode *query, ASTNode *more_queries, SourceLocation loc);
ASTNode *createIDReferenceQueryNode(char *name, SourceLocation loc);

void printAST(ASTNode *node, int level, int isLast, int *levels);
void freeAST(ASTNode *node);
char *my_strdup(const char *s);

#endif