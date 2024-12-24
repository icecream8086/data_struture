/**
 * @file ast_tech.h
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 利用AST的命令行接口，运行层
 * @version 0.1
 * @date 2024-12-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef AST_TECH_H
#define AST_TECH_H

#ifdef AST_TECH_EXPORTS
#define AST_TECH_API __declspec(dllexport)
#else
#define AST_TECH_API __declspec(dllimport)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys_call.h"
/**
 * @brief 定义AST节点类型
 *
 */
typedef enum
{
    AST_COMMAND,
    AST_ARGUMENT
} ASTNodeType;

/**
 * @brief 定义AST节点结构
 *
 */
typedef struct ASTNode
{
    ASTNodeType type;
    char value[100];
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

/**
 * @brief 创建新的AST节点
 *
 * @param type
 * @param value
 * @return ASTNode*
 */
ASTNode *createASTNode(ASTNodeType type, const char *value)
{
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    strncpy(node->value, value, 100);
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief 解析用户输入命令
 *
 * @param input
 * @return ASTNode*
 */
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


/**
 * @brief 释放AST节点
 *
 * @param node
 */
void freeAST(ASTNode *node)
{
    if (node == NULL)
        return;
    freeAST(node->left);
    freeAST(node->right);
    free(node);
}

#endif // AST_TECH_H
