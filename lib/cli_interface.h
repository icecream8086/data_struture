/**
 * @file cli_interface.h
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 输入输出
 * @version 0.1
 * @date 2024-12-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef CLI_INTERFACE_H
#define CLI_INTERFACE_H

#ifdef CLI_INTERFACE_EXPORTS
#define CLI_INTERFACE_API __declspec(dllexport)
#else
#define CLI_INTERFACE_API __declspec(dllimport)
#endif

#include <stdlib.h>
#include "ast_tech.h"
#include "sys_call.h"
#include "interpretAST.h"

/**
 * @brief 主窗体
 * 
 */
void main_dialog()
{
    int first_start=0;
    while (1)
    {
        char input[1000];
        welcome(first_start);
        fgets(input, 1000, stdin);
        input[strcspn(input, "\n")] = '\0'; // 移除换行符

        ASTNode *ast = parseCommand(input);
        interpretAST(ast);
        freeAST(ast);
        first_start=1;
    }
}
void main_dialog();

#endif // CLI_INTERFACE_H
