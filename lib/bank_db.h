/**
 * @file bank_db.h
 * @author icecream8086
 * @brief 模拟数据库
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef BANK_DB_H
#define BANK_DB_H

#ifdef BANK_DB_EXPORTS
#define BANK_DB_API __declspec(dllexport)
#else
#define BANK_DB_API __declspec(dllimport)
#endif

#include ".\ref.h"
#include ".\f_io.h"

// Function prototypes
void saveUsersToFile(const struct UserArray* arr, const char* filename);

void initUserArray(struct UserArray* arr) {
    arr->size = 0;
    arr->capacity = 10;
    arr->users = (struct User*)malloc(arr->capacity * sizeof(struct User));
}

void resizeUserArray(struct UserArray* arr) {
    arr->capacity *= 2;
    arr->users = (struct User*)realloc(arr->users, arr->capacity * sizeof(struct User));
}

void addUser(struct UserArray* arr, struct User user) {
    if (arr->size == arr->capacity) {
        resizeUserArray(arr);
    }
    arr->users[arr->size++] = user;
    saveUsersToFile(arr, "users.csv"); // Save changes to file
}

struct User* findUser(struct UserArray* arr, const char* account) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].account, account) == 0) {
            return &arr->users[i];
        }
    }
    return NULL;
}

void removeUser(struct UserArray* arr, const char* account) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].account, account) == 0) {
            for (size_t j = i; j < arr->size - 1; j++) {
                arr->users[j] = arr->users[j + 1];
            }
            arr->size--;
            saveUsersToFile(arr, "users.csv"); // Save changes to file
            return;
        }
    }
}

void updateUser(struct UserArray* arr, struct User user) {
    struct User* existingUser = findUser(arr, user.account);
    if (existingUser) {
        *existingUser = user;
        saveUsersToFile(arr, "users.csv"); // Save changes to file
    }
}

void printUser(const struct User* user) {
    printf("Name: %s\n", user->name);
    printf("Account: %s\n", user->account);
    printf("Money: %lld cents\n", user->money.cents);
}

void printAllUsers(const struct UserArray* arr) {
    for (size_t i = 0; i < arr->size; i++) {
        printUser(&arr->users[i]);
        printf("----\n");
    }
}

#endif // BANK_DB_H
