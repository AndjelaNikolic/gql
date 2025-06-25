#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_ID      "\033[32m"

ASTNode *createProgramNode(ASTNode *declarations, ASTNode *commands) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = PROGRAM_NODE;
    node->program.declarations = declarations;
    node->program.commands = commands;
    return node;
}

ASTNode *createDeclarationsNode(ASTNode *declaration, ASTNode *more_decls) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = DECLARATIONS_NODE;
    node->declarations.declaration = declaration;
    node->declarations.more_decls = more_decls;
    return node;
}

ASTNode *createQueryDeclarationNode(char *name, ASTNode *query) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = QUERY_DECL_NODE;
    node->query_decl.query_name = strdup(name);
    node->query_decl.query = query;
    return node;
}

ASTNode *createQueryListDeclarationNode(char *name, ASTNode *query_list) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = QUERY_LIST_DECL_NODE;
    node->query_decl.query_name = strdup(name);
    node->query_decl.query = query_list;
    return node;
}

ASTNode *createResultOfQueryNode(char *name) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = RESULT_OF_QUERY_NODE;
    node->result_of_query.result_name = strdup(name);
    return node;
}

ASTNode *createCommandsNode(ASTNode *command, ASTNode *more_cmds) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = COMMANDS_NODE;
    node->commands.command = command;
    node->commands.more_cmds = more_cmds;
    return node;
}

ASTNode *createExecCommandNode(char *query_name) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = EXEC_COMMAND_NODE;
    node->exec_command.exec_name = strdup(query_name);
    return node;
}

ASTNode *createIfCommandNode(ASTNode *condition, ASTNode *commands) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = IF_COMMAND_NODE;
    node->if_command.condition = condition;
    node->if_command.if_commands = commands;
    return node;
}

ASTNode *createForCommandNode(char *iterator, ASTNode *query_list, ASTNode *commands) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = FOR_COMMAND_NODE;
    node->for_command.iterator = strdup(iterator);
    node->for_command.query_list = query_list;
    node->for_command.for_commands = commands;
    return node;
}

ASTNode *createAssignCommandNode(char *target, char *source) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = ASSIGN_COMMAND_NODE;
    node->assign_command.assign_target = strdup(target);
    node->assign_command.assign_source = createExecCommandNode(source);
    return node;
}

ASTNode *createSetOperationNode(char *left, char *right, OperatorType op, char *target) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = SET_OPERATION_NODE;
    node->set_operation.set_left = strdup(left);
    node->set_operation.set_right = strdup(right);
    node->set_operation.set_op = op;
    node->set_operation.set_target = strdup(target);
    return node;
}

ASTNode *createQueryNode(ASTNode *terms) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = QUERY_NODE;
    node->query.terms = terms;
    return node;
}

ASTNode *createTermsNode(ASTNode *term, ASTNode *more_terms) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = TERMS_NODE;
    node->terms.term = term;
    node->terms.more_terms = more_terms;
    return node;
}

ASTNode *createTermNode(char *word, ASTNode *directive, ASTNode *op_term) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = TERM_NODE;
    node->term.term_word = word ? strdup(word) : NULL;
    node->term.term_directive = directive;
    node->term.term_op = op_term;
    return node;
}

ASTNode *createDirectiveNode(char *key, char *value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = DIRECTIVE_NODE;
    node->directive.dir_key = strdup(key);
    node->directive.dir_value = strdup(value);
    return node;
}

ASTNode *createUnaryOpNode(OperatorType op, ASTNode *term) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = UNARY_OP_NODE;
    node->unary_op.unary_op = op;
    node->unary_op.operand = term;
    return node;
}

ASTNode *createBinaryOpNode(OperatorType op, ASTNode *left, ASTNode *right) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = BINARY_OP_NODE;
    node->binary_op.binary_op = op;
    node->binary_op.left = left;
    node->binary_op.right = right;
    return node;
}

ASTNode *createEmptyConditionNode(char *id) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = CONDITION_NODE;
    node->condition.cond_type = EMPTY_COND;
    node->condition.cond_id = strdup(id);
    return node;
}

ASTNode *createUrlExistsConditionNode(char *id, char *url) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = CONDITION_NODE;
    node->condition.cond_type = URL_EXISTS_COND;
    node->condition.cond_id = strdup(id);
    node->condition.cond_url = strdup(url);
    return node;
}

ASTNode *createNotEmptyConditionNode(char *id) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = CONDITION_NODE;
    node->condition.cond_type = NOT_EMPTY_COND;
    node->condition.cond_id = strdup(id);
    return node;
}

ASTNode *createQueryListNode(ASTNode *query, ASTNode *more_queries) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = QUERY_LIST_NODE;
    node->query_list.query_item = query;
    node->query_list.more_queries = more_queries;
    return node;
}

ASTNode *createIDReferenceQueryNode(char *name) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = QUERY_REF_NODE;
    node->query_ref.query_ref = strdup(name);
    return node;
}

ASTNode *createQueryRefNode(char *name) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = QUERY_REF_NODE;
    node->query_ref.query_ref = strdup(name);
    return node;
}

void printPrefix(int level, int isLast, int *levels) {
    for (int i = 0; i < level; ++i) {
        if (i == level - 1) {
            printf(isLast ? "    " : "│   ");
        } else {
            printf(levels[i] ? "    " : "│   ");
        }
    }
    printf(isLast ? "└── " : "├── ");
}

void printPrefix(int level, int isLast, int *levels) {
    for (int i = 0; i < level; ++i) {
        if (i == level - 1) {
            printf(isLast ? "    " : "│   ");
        } else {
            printf(levels[i] ? "    " : "│   ");
        }
    }
    printf(isLast ? "└── " : "├── ");
}

void printAST(ASTNode *node, int level, int isLast, int *levels) {
    if (!node) return;

    printPrefix(level, isLast, levels);

    switch (node->type) {
        case PROGRAM_NODE:
            printf("Program\n");
            levels[level] = isLast;
            printAST(node->program.declarations, level + 1, 0, levels);
            printAST(node->program.commands, level + 1, 1, levels);
            break;

        case DECLARATIONS_NODE:
            printf("Declarations\n");
            levels[level] = isLast;
            printAST(node->declarations.declaration, level + 1, 
                   node->declarations.more_decls == NULL, levels);
            if (node->declarations.more_decls) {
                printAST(node->declarations.more_decls, level + 1, 1, levels);
            }
            break;

        case QUERY_DECL_NODE:
            printf("QueryDeclaration \"%s\"\n", node->query_decl.query_name);
            levels[level] = isLast;
            printAST(node->query_decl.query, level + 1, 1, levels);
            break;

        case QUERY_LIST_DECL_NODE:
            printf("QueryListDeclaration \"%s\"\n", node->query_decl.query_name);
            levels[level] = isLast;
            printAST(node->query_decl.query, level + 1, 1, levels);
            break;

        case RESULT_OF_QUERY_NODE:
            printf("ResultOfQueryDeclaration \"%s\"\n", node->result_of_query.result_name);
            break;

        case COMMANDS_NODE:
            printf("Commands\n");
            levels[level] = isLast;
            printAST(node->commands.command, level + 1, 
                   node->commands.more_cmds == NULL, levels);
            if (node->commands.more_cmds) {
                printAST(node->commands.more_cmds, level + 1, 1, levels);
            }
            break;

        case EXEC_COMMAND_NODE:
            printf("ExecCommand (QueryName: \"%s\")\n", node->exec_command.exec_name);
            break;

        case IF_COMMAND_NODE:
            printf("IfCommand\n");
            levels[level] = isLast;
            printAST(node->if_command.condition, level + 1, 0, levels);
            printAST(node->if_command.if_commands, level + 1, 1, levels);
            break;

        case FOR_COMMAND_NODE:
            printf("ForCommand (iterator: %s)\n", node->for_command.iterator);
            levels[level] = isLast;
            printPrefix(level + 1, 0, levels);
            printf("Iterable\n");
            printAST(node->for_command.query_list, level + 2, 1, levels);
            printPrefix(level + 1, 1, levels);
            printf("Body\n");
            printAST(node->for_command.for_commands, level + 2, 1, levels);
            break;

        case ASSIGN_COMMAND_NODE:
            printf("AssignCommand\n");
            levels[level] = isLast;
            printPrefix(level + 1, 0, levels);
            printf("Target: \"%s\"\n", node->assign_command.assign_target);
            printPrefix(level + 1, 1, levels);
            printAST(node->assign_command.assign_source, level + 2, 1, levels);
            break;

        case SET_OPERATION_NODE:
            printf("SetOperation (%s ", node->set_operation.set_left);
            switch (node->set_operation.set_op) {
                case SET_UNION_OP: printf("++"); break;
                case SET_DIFFERENCE_OP: printf("--"); break;
                case SET_INTERSECTION_OP: printf("**"); break;
            }
            printf(" %s)\n", node->set_operation.set_right);
            break;

        case QUERY_NODE:
            printf("Query\n");
            levels[level] = isLast;
            printAST(node->query.terms, level + 1, 1, levels);
            break;

        case TERMS_NODE:
            if (node->terms.term) {
                printAST(node->terms.term, level, 
                       node->terms.more_terms == NULL, levels);
            }
            if (node->terms.more_terms) {
                printAST(node->terms.more_terms, level, 1, levels);
            }
            break;

        case TERM_NODE:
            if (node->term.term_word) {
                printf("Term \"%s\"\n", node->term.term_word);
            } else if (node->term.term_directive) {
                printf("Directive (%s:%s)\n",
                       node->term.term_directive->directive.dir_key,
                       node->term.term_directive->directive.dir_value);
            }
            if (node->term.term_op) {
                levels[level] = isLast;
                printAST(node->term.term_op, level + 1, 1, levels);
            }
            break;

        case DIRECTIVE_NODE:
            printf("Directive (%s:%s)\n",
                   node->directive.dir_key,
                   node->directive.dir_value);
            break;

        case UNARY_OP_NODE:
            switch (node->unary_op.unary_op) {
                case PLUS_OP: printf("Plus"); break;
                case MINUS_OP: printf("Minus"); break;
                default: printf("UnaryOp"); break;
            }
            printf("\n");
            levels[level] = isLast;
            printAST(node->unary_op.operand, level + 1, 1, levels);
            break;

        case BINARY_OP_NODE:
            switch (node->binary_op.binary_op) {
                case JUXTAPOSITION_OP: printf("Juxtaposition\n"); break;
                case OR_OP: printf("Or\n"); break;
                case PLUS_OP: printf("Plus\n"); break;
                case MINUS_OP: printf("Minus\n"); break;
                default: printf("BinaryOp\n"); break;
            }
            levels[level] = isLast;
            printAST(node->binary_op.left, level + 1, 0, levels);
            printAST(node->binary_op.right, level + 1, 1, levels);
            break;

        case CONDITION_NODE:
            switch (node->condition.cond_type) {
                case EMPTY_COND: printf("Condition: Empty \"%s\"\n", node->condition.cond_id); break;
                case NOT_EMPTY_COND: printf("Condition: NotEmpty \"%s\"\n", node->condition.cond_id); break;
                case URL_EXISTS_COND: 
                    printf("Condition: UrlExists \"%s\" -> %s\n",
                           node->condition.cond_id,
                           node->condition.cond_url);
                    break;
                default: printf("Condition: Unknown\n"); break;
            }
            break;

        case QUERY_LIST_NODE:
            if (node->query_list.query_item) {
                printAST(node->query_list.query_item, level, 
                       node->query_list.more_queries == NULL, levels);
            }
            if (node->query_list.more_queries) {
                printAST(node->query_list.more_queries, level, 1, levels);
            }
            break;

        case QUERY_REF_NODE:
            printf("QueryReference \"%s\"\n", node->query_ref.query_ref);
            break;

        default:
            printf("Unknown node type\n");
            break;
    }
}

void freeAST(ASTNode *node) {
    if (!node) return;
    
    switch (node->type) {
        case PROGRAM_NODE:
            freeAST(node->program.declarations);
            freeAST(node->program.commands);
            break;
            
        case DECLARATIONS_NODE:
            freeAST(node->declarations.declaration);
            freeAST(node->declarations.more_decls);
            break;
            
        case QUERY_DECL_NODE:
            free(node->query_decl.query_name);
            freeAST(node->query_decl.query);
            break;
            
        case QUERY_LIST_DECL_NODE:
            free(node->query_decl.query_name);
            freeAST(node->query_decl.query);
            break;
            
        case RESULT_OF_QUERY_NODE:
            free(node->result_of_query.result_name);
            break;
            
        case COMMANDS_NODE:
            freeAST(node->commands.command);
            freeAST(node->commands.more_cmds);
            break;
            
        case EXEC_COMMAND_NODE:
            free(node->exec_command.exec_name);
            break;
            
        case IF_COMMAND_NODE:
            freeAST(node->if_command.condition);
            freeAST(node->if_command.if_commands);
            break;
            
        case FOR_COMMAND_NODE:
            free(node->for_command.iterator);
            freeAST(node->for_command.query_list);
            freeAST(node->for_command.for_commands);
            break;
            
        case ASSIGN_COMMAND_NODE:
            free(node->assign_command.assign_target);
            freeAST(node->assign_command.assign_source);
            break;
            
        case SET_OPERATION_NODE:
            free(node->set_operation.set_left);
            free(node->set_operation.set_right);
            free(node->set_operation.set_target);
            break;
            
        case QUERY_NODE:
            freeAST(node->query.terms);
            break;
            
        case TERMS_NODE:
            freeAST(node->terms.term);
            freeAST(node->terms.more_terms);
            break;
            
        case TERM_NODE:
            if (node->term.term_word) free(node->term.term_word);
            freeAST(node->term.term_directive);
            freeAST(node->term.term_op);
            break;
            
        case DIRECTIVE_NODE:
            free(node->directive.dir_key);
            free(node->directive.dir_value);
            break;
            
        case UNARY_OP_NODE:
            freeAST(node->unary_op.operand);
            break;
            
        case BINARY_OP_NODE:
            freeAST(node->binary_op.left);
            freeAST(node->binary_op.right);
            break;
            
        case CONDITION_NODE:
            free(node->condition.cond_id);
            if (node->condition.cond_type == URL_EXISTS_COND) {
                free(node->condition.cond_url);
            }
            break;
            
        case QUERY_LIST_NODE:
            freeAST(node->query_list.query_item);
            freeAST(node->query_list.more_queries);
            break;
            
        case QUERY_REF_NODE:
            free(node->query_ref.query_ref);
            break;
    }
    
    free(node);
}