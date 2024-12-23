/**
 * @file ref.h
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 结构体定义
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef REF_H
#define REF_H

#ifdef EXPORTING_REF_H
#define REF_H_API __declspec(dllexport)
#else
#define REF_H_API __declspec(dllimport)
#endif
/**
 * @brief 货币单位-一分钱
 * 尽管只保留两位,尽可能通过 long long避免溢出带来的影响
 */
struct Money {
    long long cents;
};

struct User {
    char name[50];
    char account[50];
    struct Money money;
};

struct UserArray {
    struct User* users;
    size_t size;
    size_t capacity;
};

#endif // REF_H