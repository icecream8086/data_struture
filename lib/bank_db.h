/**
 * @file bank_db.h
 * @author 
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ref.h"

/**
 * @brief 初始化用户数组
 * 
 * @param arr 用户数组指针
 */
void initUserArray(struct UserArray* arr);

/**
 * @brief 调整用户数组大小
 * 
 * @param arr 用户数组指针
 */
void resizeUserArray(struct UserArray* arr);

/**
 * @brief 向用户数组中添加用户
 * 
 * @param arr 用户数组指针
 * @param user 用户结构体
 */
void addUser(struct UserArray* arr, struct User user);

/**
 * @brief 根据账户查找用户
 * 
 * @param arr 用户数组指针
 * @param account 用户账户
 * @return struct User* 用户结构体指针
 */
struct User* findUser(struct UserArray* arr, const char* account);

/**
 * @brief 根据账户移除用户
 * 
 * @param arr 用户数组指针
 * @param account 用户账户
 */
void removeUser(struct UserArray* arr, const char* account);

/**
 * @brief 更新用户信息
 * 
 * @param arr 用户数组指针
 * @param user 用户结构体
 */
void updateUser(struct UserArray* arr, struct User user);

/**
 * @brief 输出用户信息
 * 
 * @param user 用户结构体指针
 */
void printUser(const struct User* user);

/**
 * @brief 输出所有用户信息
 * 
 * @param arr 用户数组指针
 */
void printAllUsers(const struct UserArray* arr);

/**
 * @brief 从文件加载用户数据
 * 
 * @param arr 用户数组指针
 * @param filename 文件名
 */
void loadUsersFromFile(struct UserArray* arr, const char* filename);

/**
 * @brief 保存用户数据到文件
 * 
 * @param arr 用户数组指针
 * @param filename 文件名
 */
void saveUsersToFile(const struct UserArray* arr, const char* filename);

/**
 * @brief 检查是否有重复的账户。如果没有重复的账户，则将用户数据保存到 CSV 文件中
 * 
 * @param arr 用户数组指针
 * @param filename 文件名
 */
void saveUsersToCSVWithUniqueCheck(const struct UserArray* arr, const char* filename);

/**
 * @brief 初始化用户数组
 * 
 * @param arr 用户数组指针
 */
void initUserArray(struct UserArray* arr) {
    arr->size = 0;
    arr->capacity = 10;
    arr->users = (struct User*)malloc(arr->capacity * sizeof(struct User));
}

/**
 * @brief 调整用户数组大小
 * 
 * @param arr 用户数组指针
 */
void resizeUserArray(struct UserArray* arr) {
    arr->capacity *= 2;
    arr->users = (struct User*)realloc(arr->users, arr->capacity * sizeof(struct User));
}

/**
 * @brief 向用户数组中添加用户
 * 
 * @param arr 用户数组指针
 * @param user 用户结构体
 */
void addUser(struct UserArray* arr, struct User user) {
    if (arr->size == arr->capacity) {
        resizeUserArray(arr);
    }
    arr->users[arr->size++] = user;
}

/**
 * @brief 根据账户查找用户
 * 
 * @param arr 用户数组指针
 * @param account 用户账户
 * @return struct User* 用户结构体指针
 */
struct User* findUser(struct UserArray* arr, const char* account) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].account, account) == 0) {
            return &arr->users[i];
        }
    }
    return NULL;
}

/**
 * @brief 根据账户移除用户
 * 
 * @param arr 用户数组指针
 * @param account 用户账户
 */
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

/**
 * @brief 更新用户信息
 * 
 * @param arr 用户数组指针
 * @param user 用户结构体
 */
void updateUser(struct UserArray* arr, struct User user) {
    struct User* existingUser = findUser(arr, user.account);
    if (existingUser) {
        *existingUser = user;
    }
}

/**
 * @brief 输出用户信息
 * 
 * @param user 用户结构体指针
 */
void printUser(const struct User* user) {
    printf("Name: %s\n", user->name);
    printf("Account: %s\n", user->account);
    printf("Money: %lld cents\n", user->money.cents);
}



/**
 * @brief 输出所有用户信息
 * 
 * @param arr 用户数组指针
 */

void printAllUsers(const struct UserArray* arr) {
    for (size_t i = 0; i < arr->size; i++) {
        printUser(&arr->users[i]);
        printf("----\n");
    }
}
/**
 * @brief 检查是否有重复的账户。如果没有重复的账户，则将用户数据保存到 CSV 文件中
 * 
 * @param arr 用户数组指针
 * @param filename 文件名
 */
void saveUsersToCSVWithUniqueCheck(const struct UserArray* arr, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("无法创建文件: %s\n", filename);
        return;
    }

    for (size_t i = 0; i < arr->size; i++) {
        struct User* user = findUser((struct UserArray*)arr, arr->users[i].account);
        if (user != NULL) {
            printf("用户账户已存在: %s\n", arr->users[i].account);
            continue;
        }
        if (fprintf(file, "%s,%s,%lld\n", arr->users[i].name, arr->users[i].account, arr->users[i].money.cents) < 0) {
            printf("无法写入用户: %s\n", arr->users[i].name);
        }
    }

    fclose(file);
}

#endif // BANK_DB_H
