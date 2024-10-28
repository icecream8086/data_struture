#include"struct.h"
#define bool int
//  顺序栈实现

/**
 * @brief 初始化栈
 * 
 * @param S 
 */
void init_stack(sequence_stack *S)
{
    S->top = -1;   // 初始化栈顶指针
}

/**
 * @brief 入栈
 * 
 * @param S 
 * @param x 
 * @return true 
 * @return false 
 */
bool push(sequence_stack *S, int x)
{
    if (S->top == MAX_SIZE - 1) // 栈满
    {
        return 0;
    }
    //先进位后赋值，不影响栈顶指针
    S->top++; // 栈顶指针加1
    S->data[S->top] = x; // 将新元素入栈
    return 1;
}

/**
 * @brief 出栈
 * 
 * @param S 
 * @param x 
 * @return true 
 * @return false 
 */
bool pop(sequence_stack *S, int *x)
{
    if (S->top == -1) // 栈空
    {
        return 0;
    }
    *x = S->data[S->top]; // 将栈顶元素出栈
    S->top--; // 栈顶指针减1
    return 1;
}

/**
 * @brief Get the top object
 * 
 * @param S 
 * @param x 
 * @return true 
 * @return false 
 */
bool get_top(sequence_stack *S, int *x)
{
    if (S->top == -1) // 栈空
    {
        return 0;
    }
    *x = S->data[S->top]; // 返回栈顶元素
    return 1;
}

/**
 * @brief 判断栈是否为空
 * 
 * @param S 
 * @return true 
 * @return false 
 */
bool is_empty(sequence_stack *S)
{
    return S->top == -1;
}