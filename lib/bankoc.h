/**
 * @file bankoc.h
 * @author your name (icecream8086@outlook.com)
 * @brief 金融操作
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BANKOC_H
#define BANKOC_H

#ifdef BANKOC_H
#define BANKOC_API __declspec(dllexport)
#else
#define BANKOC_API __declspec(dllimport)
#endif

#include ".\ref.h"
#include <stdio.h>
#include <math.h>

/**
 * @brief 创建货币
 * 
 * @param yuan 
 * @param cents 
 * @return struct Money 
 */
struct Money createMoney(int yuan, int cents) {
    struct Money m;
    m.cents = (long long)yuan * 100 + cents;
    return m;
}

/**
 * @brief 格式化输出货币信息
 * 
 * @param m 
 */
void printMoney(struct Money m) {
    printf("¥%lld.%02lld\n", m.cents / 100, m.cents % 100);
}

/**
 * @brief 货币加法
 * 
 * @param m1 
 * @param m2 
 * @return struct Money 
 */
struct Money addMoney(struct Money m1, struct Money m2) {
    struct Money result;
    result.cents = m1.cents + m2.cents;
    return result;
}

/**
 * @brief 货币减法
 * 
 * @param m1 
 * @param m2 
 * @return struct Money 
 */
struct Money subtractMoney(struct Money m1, struct Money m2) {
    struct Money result;
    result.cents = m1.cents - m2.cents;
    return result;
}

/**
 * @brief 货币乘法
 * 
 * @param m 
 * @param factor 
 * @return struct Money 
 */
struct Money multiplyMoney(struct Money m, double factor) {
    struct Money result;
    result.cents = (long long)round(m.cents * factor);
    return result;
}

/**
 * @brief 货币除法
 * 
 * @param m 
 * @param divisor 
 * @param remainder 
 * @return struct Money 
 */
struct Money divideMoney(struct Money m, double divisor, int* remainder) {
    struct Money result;
    double temp_result = m.cents / divisor;
    result.cents = (long long)floor(temp_result);
    *remainder = (int)round((temp_result - result.cents) * divisor);
    return result;
}

#endif // REF_H