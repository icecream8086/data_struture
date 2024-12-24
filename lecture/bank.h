// bank.h
#ifndef BANK_H
#define BANK_H

#define MAX_ACCOUNTS 100
#define ACCOUNT_FILE "account.txt"

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

void openAccount();
void queryAccount();
void deposit();
void withdraw();
void displayMainMenu();

#endif // BANK_H
