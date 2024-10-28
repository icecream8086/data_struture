#include "data_structure\stack\sequence_stack.h"
#include "data_structure\stack\struct.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence_table(char opearte_code) {
    switch (opearte_code) {
        //优先级表，数字越大优先级越高，-1表示不合法，0表示最低优先级
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
    }
    return -1;
}

void infix_to_postfix(const char *infix, char *postfix) {
    sequence_stack S;
    init_stack(&S);
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        // C 库函数 isdigit () 用于检查字符是否是十进制数字，返回非零值或零
        if (isdigit(ch) || isalpha(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&S, ch);
        } else if (ch == ')') {
            char temp;
            while (!is_empty(&S) && (temp = peek(&S)) != '(') {
                pop(&S, &temp);
                postfix[j++] = temp;
            }
            pop(&S, &temp); // 弹出左括号
        } else {
            // 如果栈不为空且栈顶元素的优先级大于等于当前运算符的优先级
            while (!is_empty(&S) && precedence_table(peek(&S)) >= precedence_table(ch)) {
                // 弹出栈顶元素
                char temp;
                pop(&S, &temp);
                postfix[j++] = temp;
            }
            push(&S, ch);
        }
    }
    while (!is_empty(&S)) {
        char temp;
        pop(&S, &temp);
        postfix[j++] = temp;
    }
    postfix[j] = '\0';
}

int main() {
    //UNIT TEST
    // char infix[MAX_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[MAX_SIZE];
    char infix[MAX_SIZE] = "";
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("后缀表达式: %s\n", postfix);
    return 0;
}