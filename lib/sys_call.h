/**
 * @file sys_call.h
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 操作系统控制台和一些文本信息相关的函数
 * @version 0.1
 * @date 2024-12-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SYS_CALL_H
#define SYS_CALL_H

#ifdef SYS_CALL_EXPORTS
#define SYS_CALL_API __declspec(dllexport)
#else
#define SYS_CALL_API __declspec(dllimport)
#endif

#include <stdlib.h>

/**
 * @brief 清屏
 * 
 */
void clearScreen()
{
    system("clear");
}

/**
 * @brief 欢迎界面
 * 
 */
void welcome(int first_start)
{
    if (first_start==0)
    {
            printf("欢迎使用.....\n");
    }
    
    printf(">");
    //todo...
}
void help(char func_name){
    printf("帮助功能");
    //todo...
}
void bye(){
    printf("bye ...");
}
#endif // SYS_CALL_H
