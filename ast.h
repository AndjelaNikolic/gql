#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER) || defined(__MINGW32__)
char *strdup(const char *s);
#endif

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
    QUERY_LIST_NODE,
    QUERY_REF_NODE
} ASTNodeType;

typedef enum {
    PLUS_OP,
    MINUS_OP,
    MULT_OP,
    OR_OP,
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
        
        struct {
            char *query_ref;
        } query_ref;
    };
} ASTNode;

ASTNode *createProgramNode(ASTNode *declarations, ASTNode *commands);
ASTNode *createDeclarationsNode(ASTNode *declaration, ASTNode *more_decls);
ASTNode *createQueryDeclarationNode(char *name, ASTNode *query);
ASTNode *createQueryListDeclarationNode(char *name, ASTNode *query_list);
ASTNode *createResultOfQueryNode(char *name);
ASTNode *createCommandsNode(ASTNode *command, ASTNode *more_cmds);
ASTNode *createExecCommandNode(char *query_name);
ASTNode *createIfCommandNode(ASTNode *condition, ASTNode *commands);
ASTNode *createForCommandNode(char *iterator, ASTNode *query_list, ASTNode *commands);
ASTNode *createAssignCommandNode(char *target, char *source);
ASTNode *createSetOperationNode(char *left, char *right, OperatorType op, char *target);
ASTNode *createQueryNode(ASTNode *terms);
ASTNode *createTermsNode(ASTNode *term, ASTNode *more_terms);
ASTNode *createTermNode(char *word, ASTNode *directive, ASTNode *op_term);
ASTNode *createDirectiveNode(char *key, char *value);
ASTNode *createUnaryOpNode(OperatorType op, ASTNode *term);
ASTNode *createBinaryOpNode(OperatorType op, ASTNode *left, ASTNode *right);
ASTNode *createEmptyConditionNode(char *id);
ASTNode *createUrlExistsConditionNode(char *id, char *url);
ASTNode *createNotEmptyConditionNode(char *id);
ASTNode *createQueryListNode(ASTNode *query, ASTNode *more_queries);
ASTNode *createIDReferenceQueryNode(char *name);
ASTNode *createQueryRefNode(char *name);

void printAST(ASTNode *node, int level, int isLast, int *levels);
void freeAST(ASTNode *node);

#endif