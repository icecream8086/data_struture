// bank.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// 从文件加载账户信息
void loadAccounts() {
    FILE *file = fopen(ACCOUNT_FILE, "r");
    if (file) {
        while (fscanf(file, "%d %s %f", &accounts[accountCount].accountNumber,
                      accounts[accountCount].name, &accounts[accountCount].balance) != EOF) {
            accountCount++;
        }
        fclose(file);
    }
}

// 保存账户信息到文件
void saveAccounts() {
    FILE *file = fopen(ACCOUNT_FILE, "w");
    for (int i = 0; i < accountCount; i++) {
        fprintf(file, "%d %s %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    fclose(file);
}

// 开户
void openAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("账户已满，无法开户。\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // 简单的账户编号生成方式
    printf("请输入姓名: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    saveAccounts(); // 保存到文件
    printf("开户成功！您的账户号码是：%d\n", newAccount.accountNumber);
}

// 查询账户
void queryAccount() {
    int accountNumber;
    printf("请输入账户号码: ");
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        Account acc = accounts[accountNumber - 1];
        printf("账户号码: %d, 姓名: %s, 余额: %.2f\n", acc.accountNumber, acc.name, acc.balance);
    } else {
        printf("未找到该账户。\n");
    }
}

// 存款
void deposit() {
    int accountNumber;
    float amount;

    printf("请输入账户号码: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber > 0 && accountNumber <= accountCount) {
        printf("请输入存款金额: ");
        scanf("%f", &amount);
        
        if (amount > 0) {
            accounts[accountNumber - 1].balance += amount;
            saveAccounts(); // 保存到文件
            printf("存款成功！当前余额: %.2f\n", accounts[accountNumber - 1].balance);
        } else {
            printf("存款金额必须大于零。\n");
        }
    } else {
        printf("未找到该账户。\n");
    }
}

// 取款
void withdraw() {
    int accountNumber;
    float amount;

    printf("请输入账户号码: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber > 0 && accountNumber <= accountCount) {
        printf("请输入取款金额: ");
        scanf("%f", &amount);
        
        if (amount > 0 && amount <= accounts[accountNumber - 1].balance) {
            accounts[accountNumber - 1].balance -= amount;
            saveAccounts(); // 保存到文件
            printf("取款成功！当前余额: %.2f\n", accounts[accountNumber - 1].balance);
        } else if (amount > accounts[accountNumber - 1].balance) {
            printf("余额不足。\n");
        } else {
            printf("取款金额必须大于零。\n");
        }
    } else {
        printf("未找到该账户。\n");
    }
}

// 主界面输出
void displayMainMenu() {
    printf("\n欢迎使用银行账户管理系统\n");
    printf("1. 开户\n");
    printf("2. 查询账户\n");
    printf("3. 存款\n");
    printf("4. 取款\n");
    printf("5. 退出\n");
}

