/**
 * @file f_io.h
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 文件IO模块
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
//todo... csv格式文件io操作,提供抽象层

/**
 * @file F_IO.h
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 模拟数据库
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

//code
#include ".\ref.h"

/**
 * @brief 从文件加载用户数据
 * 
 * @param arr 
 * @param filename 
 */
void loadUsersFromFile(struct UserArray* arr, const char* filename) {
    FILE* file = fopen(filename, "a+"); // 使用 "a+" 模式
    if (!file) {
        printf("无法打开文件: %s\n", filename);
        return;
    }
    char line[128];
    // 从头开始读取
    rewind(file);
    while (fgets(line, sizeof(line), file)) {
        struct User user;
        sscanf(line, "%49[^,],%49[^,],%lld", user.name, user.account, &user.cents);
        addUser(arr, user);
    }
    fclose(file);
}


/**
 * @brief 保存用户数据到文件
 * 
 * @param arr 
 * @param filename 
 */
void saveUsersToFile(const struct UserArray* arr, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("无法创建文件: %s\n", filename);
        return;
    }
    for (size_t i = 0; i < arr->size; i++) {
        if (fprintf(file, "%s,%s,%lld\n", arr->users[i].name, arr->users[i].account, arr->users[i].cents) < 0) {
            printf("无法写入用户: %s\n", arr->users[i].name);
        } else {
            printf("Wrote user: %s, %s, %lld\n", arr->users[i].name, arr->users[i].account, arr->users[i].cents); // Debug statement
        }
    }
    fclose(file);
}


/**
 * @brief 根据名字查找用户
 * 
 * @param arr 
 * @param name 
 * @return struct User* 
 */
struct User* findUserByName(const struct UserArray* arr, const char* name) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].name, name) == 0) {
            return &arr->users[i];
        }
    }
    return NULL;
}

/**
 * @brief 根据名字删除用户
 * 
 * @param arr 
 * @param name 
 */
void deleteUserByName(struct UserArray* arr, const char* name) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].name, name) == 0) {
            // 将最后一个用户移到当前的位置
            arr->users[i] = arr->users[--arr->size];
            return;
        }
    }
}


/**
 * @brief 根据账户查找用户
 * 
 * @param arr 
 * @param account 
 * @return struct User* 
 */
struct User* findUserByAccount(const struct UserArray* arr, const char* account) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].account, account) == 0) {
            return &arr->users[i];
        }
    }
    return NULL;
}

/**
 * @brief 根据账户删除用户
 * 
 * @param arr 
 * @param account 
 */
void deleteUserByAccount(struct UserArray* arr, const char* account) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].account, account) == 0) {
            // 将最后一个用户移到当前的位置
            arr->users[i] = arr->users[--arr->size];
            return;
        }
    }
}


#endif // F_IO_H

// 动态扩容的结构体数组