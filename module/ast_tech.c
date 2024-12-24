#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义AST节点类型
typedef enum
{
    AST_COMMAND,
    AST_ARGUMENT
} ASTNodeType;

// 定义AST节点结构
typedef struct ASTNode
{
    ASTNodeType type;
    char value[100];
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

// 创建新的AST节点
ASTNode *createASTNode(ASTNodeType type, const char *value)
{
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    strncpy(node->value, value, 100);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 解析用户输入命令
ASTNode *parseCommand(const char *input)
{
    ASTNode *root = NULL;
    ASTNode *current = NULL;

    char *token = strtok(strdup(input), " ");
    while (token != NULL)
    {
        ASTNode *newNode = createASTNode(root == NULL ? AST_COMMAND : AST_ARGUMENT, token);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            current->right = newNode;
        }
        current = newNode;
        token = strtok(NULL, " ");
    }

    return root;
}

// 解释AST并调用相应的函数
// 解释AST并调用相应的函数
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
        else
        {
            printf("Error: Unknown command '%s'\n", node->value);
        }
    }

    interpretAST(node->right);
}

// 释放AST节点
void freeAST(ASTNode *node)
{
    if (node == NULL)
        return;
    freeAST(node->left);
    freeAST(node->right);
    free(node);
}

int main()
{
    while (1)
    {
        char input[1000];

        printf("Enter a command (e.g., 'print Hello' or 'add 3 5'): ");
        fgets(input, 1000, stdin);
        input[strcspn(input, "\n")] = '\0'; // 移除换行符

        ASTNode *ast = parseCommand(input);
        interpretAST(ast);
        freeAST(ast);
    }

    return 0;
}

