/**
 * @file bankoc.h
 * @author icecream8086 (icecream8086@outlook.com)
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

#include "./ref.h"
#include <stdio.h>
#include <math.h>
/**
 * @brief 创建货币
 * 
 * @param yuan 
 * @param cents 
 * @return struct Money 
 */
struct Money createMoney(int yuan, int cents);

/**
 * @brief 格式化输出货币信息
 * 
 * @param m 
 */
void printMoney(struct Money m);

/**
 * @brief 货币加法
 * 
 * @param m1 
 * @param m2 
 * @return struct Money 
 */
struct Money addMoney(struct Money m1, struct Money m2);
int transferMoney(struct User *from, struct User *to, struct Money amount, struct UserArray* updatedUsers) ;

/**
 * @brief 货币减法
 * 
 * @param m1 
 * @param m2 
 * @return struct Money 
 */
struct Money subtractMoney(struct Money m1, struct Money m2);

/**
 * @brief 货币乘法
 * 
 * @param m 
 * @param factor 
 * @return struct Money 
 */
struct Money multiplyMoney(struct Money m, double factor);

/**
 * @brief 货币除法
 * 
 * @param m 
 * @param divisor 
 * @param remainder 
 * @return struct Money 
 */
struct Money divideMoney(struct Money m, double divisor, int* remainder);


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

int transferMoney(struct User *from, struct User *to, struct Money amount, struct UserArray* updatedUsers) {
    // 检查余额是否足够
    if (from->money.cents < amount.cents)
    {
        printf("余额不足，无法完成转账。\n");
        return 0;
    }

    // 执行转账
    from->money.cents -= amount.cents;
    to->money.cents += amount.cents;

    printf("成功转账 ¥%lld.%02lld 从 %s 到 %s\n", amount.cents / 100, amount.cents % 100, from->name, to->name);

    // 更新用户数组
    for (size_t i = 0; i < updatedUsers->size; i++) {
        if (strcmp(updatedUsers->users[i].account, from->account) == 0) {
            updatedUsers->users[i].money = from->money;
        }
        if (strcmp(updatedUsers->users[i].account, to->account) == 0) {
            updatedUsers->users[i].money = to->money;
        }
    }

    return 1;
}


#endif // REF_H