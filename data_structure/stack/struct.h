#ifndef STACK_H
#define STACK_H
// 为了将结构体和类型定义作为宏导入导出，可以使用条件编译来确保头文件只被包含一次，并且可以通过定义导出宏来控制导出

#ifdef EXPORTING_STACK_H
#define STACK_H_API __declspec(dllexport)
#else
#define STACK_H_API __declspec(dllimport)
#endif

#define MAX_SIZE 10

/**
 * @brief 顺序栈
 * 
 */
//max_size 为地址偏移量，从0开始
typedef struct {
    char data[MAX_SIZE];
    int top;
} sequence_stack;


typedef struct stack_node{
    int data;
    struct link_node *next;
}*li_stack;

#endif // STACK_H