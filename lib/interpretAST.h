/**
 * @file interpretAST.h
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 真*调用区域
 * @version 0.1
 * @date 2024-12-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ast_tech.h"
/**
 * @brief 解释AST并调用相应的函数
 *
 * @param node
 */
void interpretAST(ASTNode *node)
{
    if (node == NULL)
        return;

    if (node->type == AST_COMMAND)
    {
        if (strcmp(node->value, "print") == 0)
        {
            if (node->right != NULL && node->right->type == AST_ARGUMENT)
            {
                printf("%s\n", node->right->value);
            }
            else
            {
                printf("Error: Missing argument for 'print' command\n");
            }
        }
        else if (strcmp(node->value, "add") == 0)
        {
            if (node->right != NULL && node->right->type == AST_ARGUMENT)
            {
                ASTNode *arg1 = node->right;
                ASTNode *arg2 = arg1->right;
                if (arg2 != NULL && arg2->type == AST_ARGUMENT)
                {
                    int num1 = atoi(arg1->value);
                    int num2 = atoi(arg2->value);
                    printf("Sum: %d\n", num1 + num2);
                    //wdawdawd
                }
                else
                {
                    printf("Error: Missing second argument for 'add' command\n");
                }
            }
            else
            {
                printf("Error: Missing arguments for 'add' command\n");
            }
        }
        else if (strcmp(node->value, "multiply") == 0)
        {
            if (node->right != NULL && node->right->type == AST_ARGUMENT)
            {
                ASTNode *arg1 = node->right;
                ASTNode *arg2 = arg1->right;
                if (arg2 != NULL && arg2->type == AST_ARGUMENT)
                {
                    int num1 = atoi(arg1->value);
                    int num2 = atoi(arg2->value);
                    printf("Product: %d\n", num1 * num2);
                }
                else
                {
                    printf("Error: Missing second argument for 'multiply' command\n");
                }
            }
            else
            {
                printf("Error: Missing arguments for 'multiply' command\n");
            }
        }
        else if (strcmp(node->value, "echo") == 0)
        {
            if (node->right != NULL && node->right->type == AST_ARGUMENT)
            {
                printf("Echo: %s\n", node->right->value);
            }
            else
            {
                printf("Error: Missing argument for 'echo' command\n");
            }
        }
        else if (strcmp(node->value, "clear") == 0)
        {
            system("cls"); // For Windows
            // system("clear"); // For Unix/Linux
        }
        else if (strcmp(node->value, "quit") == 0)
        {
            bye();
            exit(0);
        }
        else if (strcmp(node->value, "exit") == 0)
        {
            bye();
            exit(0);
        }
        else
        {
            printf("Error: Unknown command '%s'\n", node->value);
        }
    }

    interpretAST(node->right);
}
void interpretAST(ASTNode *node);
