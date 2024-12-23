/**
 * @file bank_db.h
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 模拟数据库
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BANK_DB_H
#define BANK_DB_H

#ifdef BANK_DB_EXPORTS
#define BANK_DB_API __declspec(dllexport)
#else
#define BANK_DB_API __declspec(dllimport)
#endif

//code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ref.h"

void initUserArray(struct UserArray* arr);
void resizeUserArray(struct UserArray* arr);
void addUser(struct UserArray* arr, struct User user);
struct User* findUser(struct UserArray* arr, const char* account);
void removeUser(struct UserArray* arr, const char* account);
void updateUser(struct UserArray* arr, struct User user);
void printUser(const struct User* user);
void printAllUsers(const struct UserArray* arr);
void loadUsersFromFile(struct UserArray* arr, const char* filename);
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
            return;
        }
    }
}

void updateUser(struct UserArray* arr, struct User user) {
    struct User* existingUser = findUser(arr, user.account);
    if (existingUser) {
        *existingUser = user;
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

// 动态扩容的结构体数组