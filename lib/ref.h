/**
 * @file ref.h
 * @author your name (icecream8086@outlook.com)
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

struct Money {
    long long cents;
};

struct User {
    char name[50];
    char account[50];
    struct Money money;
};

#endif // REF_H