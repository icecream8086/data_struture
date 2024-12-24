// main.c
#include <stdio.h>
#include "bank.h"

int main() {
    loadAccounts();

    int choice;
    
    do {
        displayMainMenu();
        
        printf("请选择操作（1-5）: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                openAccount();
                break;
            case 2:
                queryAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("感谢使用，再见！\n");
                break;
            default:
                printf("无效选择，请重新输入。\n");
                break;
        }
        
    } while (choice != 5);

    return 0;
}

