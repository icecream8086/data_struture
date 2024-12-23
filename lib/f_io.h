/**
 * @file f_io.h
 * @author
 * @brief 文件IO模块
 * @version 0.1
 * @date 2024-12-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef F_IO_H
#define F_IO_H

#ifdef F_IO_EXPORTS
#define F_IO_API __declspec(dllexport)
#else
#define F_IO_API __declspec(dllimport)
#endif

#define bool int
#include "ref.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void loadUsersFromFile(struct UserArray *arr, const char *filename);
void saveUsersToFile(const struct UserArray *arr, const char *filename);
struct User *findUserByName(const struct UserArray *arr, const char *name);
void deleteUserByName(struct UserArray *arr, const char *name);
struct User *findUserByAccount(const struct UserArray *arr, const char *account);
void deleteUserByAccount(struct UserArray *arr, const char *account);
bool isDuplicate(const char *account, const char **existingAccounts, size_t existingCount);

void loadUsersFromFile(struct UserArray *arr, const char *filename)
{
    FILE *file = fopen(filename, "a+"); // 使用 "a+" 模式
    if (!file)
    {
        printf("无法打开文件: %s\n", filename);
        return;
    }
    char line[128];
    // 从头开始读取
    rewind(file);
    while (fgets(line, sizeof(line), file))
    {
        struct User user;
        sscanf(line, "%49[^,],%49[^,],%lld", user.name, user.account, &user.money.cents);
        addUser(arr, user);
    }
    fclose(file);
}

/**
 * @brief 是否重复
 *
 * @param account
 * @param existingAccounts
 * @param existingCount
 * @return true
 * @return false
 */
bool isDuplicate(const char *account, const char **existingAccounts, size_t existingCount)
{
    for (size_t i = 0; i < existingCount; ++i)
    {
        if (strcmp(account, existingAccounts[i]) == 0)
        {
            return true;
        }
    }
    return false;
}
/**
 * @brief 保存用户数据到文件
 *
 * @param arr 用户数组指针
 * @param filename 文件名
 */

void saveUsersToFile(const struct UserArray *arr, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("无法创建文件: %s\n", filename);
        return;
    }

    const char **existingAccounts = malloc(arr->size * sizeof(char *));
    size_t existingCount = 0;

    for (size_t i = 0; i < arr->size; i++)
    {
        if (!isDuplicate(arr->users[i].account, existingAccounts, existingCount))
        {
            if (fprintf(file, "%s,%s,%lld\n", arr->users[i].name, arr->users[i].account, arr->users[i].money.cents) < 0)
            {
                printf("无法写入用户: %s\n", arr->users[i].name);
            }
            else
            {
                printf("Wrote user: %s, %s, %lld\n", arr->users[i].name, arr->users[i].account, arr->users[i].money.cents); // Debug statement
                existingAccounts[existingCount++] = arr->users[i].account;
            }
        }
        else
        {
            // printf("跳过重复用户: %s\n", arr->users[i].account);
        }
    }

    free(existingAccounts);
    fclose(file);
}

/**
 * @brief 根据名字查找用户
 *
 * @param arr 用户数组指针
 * @param name 用户名
 * @return struct User* 用户结构体指针
 */
struct User *findUserByName(const struct UserArray *arr, const char *name)
{
    for (size_t i = 0; i < arr->size; i++)
    {
        if (strcmp(arr->users[i].name, name) == 0)
        {
            return &arr->users[i];
        }
    }
    return NULL;
}

/**
 * @brief 根据名字删除用户
 *
 * @param arr 用户数组指针
 * @param name 用户名
 */
void deleteUserByName(struct UserArray *arr, const char *name)
{
    for (size_t i = 0; i < arr->size; i++)
    {
        if (strcmp(arr->users[i].name, name) == 0)
        {
            // 将最后一个用户移到当前的位置
            arr->users[i] = arr->users[--arr->size];
            return;
        }
    }
}

/**
 * @brief 根据账户查找用户
 *
 * @param arr 用户数组指针
 * @param account 用户账户
 * @return struct User* 用户结构体指针
 */
struct User *findUserByAccount(const struct UserArray *arr, const char *account)
{
    for (size_t i = 0; i < arr->size; i++)
    {
        if (strcmp(arr->users[i].account, account) == 0)
        {
            return &arr->users[i];
        }
    }
    return NULL;
}

/**
 * @brief 根据账户删除用户
 *
 * @param arr 用户数组指针
 * @param account 用户账户
 */
void deleteUserByAccount(struct UserArray *arr, const char *account)
{
    for (size_t i = 0; i < arr->size; i++)
    {
        if (strcmp(arr->users[i].account, account) == 0)
        {
            // 将最后一个用户移到当前的位置
            arr->users[i] = arr->users[--arr->size];
            return;
        }
    }
}

#endif // F_IO_H
