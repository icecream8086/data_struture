#include "data_structure\stack\sequence_stack.h"
#include "data_structure\stack\struct.h"
#include <stdio.h>
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}


void infix_to_postfix(const char* infix, char* postfix) {
     sequence_stack S;
    init_stack(&S);
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char token = infix[i];
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&S, token);
        } else if (token == ')') {
            char top_token;
            pop(&S, &top_token);
            while (top_token != '(') {
                postfix[j++] = top_token;
                pop(&S, &top_token);
            }
        } else {
            char top_token;
            while (!is_empty(&S) && precedence(get_top(&S, &top_token), token)) {
                pop(&S, &top_token);
                postfix[j++] = top_token;
            }
            push(&S, token);
        }
    }
    while (!is_empty(&S)) {
        char top_token;
        pop(&S, &top_token);
        postfix[j++] = top_token;
    }
    postfix[j] = '\0';
}


int main(){
      const char* infix = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[100];
    infix_to_postfix(infix, postfix);
    printf("后缀表达式: %s\n", postfix);
    return 0;  
}
