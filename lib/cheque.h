/**
 * @file cheque.h
 * @author icecream8086 (icecream8086@out.com)
 * @brief 用户控制，数据检查等函数
 * @version 0.1
 * @date 2024-12-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CHEQUE_H
#define CHEQUE_H

#ifdef CHEQUE_EXPORTS
#define CHEQUE_API __declspec(dllexport)
#else
#define CHEQUE_API __declspec(dllimport)
#endif
/**
 * @brief 根据用户名获取用户指针
 * 
 * @param users 用户数组
 * @param username 用户名
 * @return struct User* 指向用户的指针，如果用户不存在则返回 NULL
 */
struct User* getUserByName(struct UserArray* users, const char* username) {
    for (size_t i = 0; i < users->size; i++) {
        if (strcmp(users->users[i].name, username) == 0) {
            return &(users->users[i]);
        }
    }
    return NULL; // 用户名不存在时返回 NULL
}
struct User* getUserByName(struct UserArray* users, const char* username) ;

/**
 * @brief 基于账户名的转账函数
 * 
 * @param users 用户数组
 * @param fromAccount 转出账户名
 * @param toAccount 转入账户名
 * @param amount 转账金额
 * @return int 成功返回1，失败返回0
 */
int transferMoneyByAccount(struct UserArray* users, const char* fromAccount, const char* toAccount, struct Money amount) {
    struct User* from = NULL;
    struct User* to = NULL;

    // 查找转出账户和转入账户
    for (size_t i = 0; i < users->size; i++) {
        if (strcmp(users->users[i].account, fromAccount) == 0) {
            from = &users->users[i];
        }
        if (strcmp(users->users[i].account, toAccount) == 0) {
            to = &users->users[i];
        }
    }

    // 检查账户是否存在
    if (!from || !to) {
        printf("找不到账户: %s 或 %s\n", fromAccount, toAccount);
        return 0;
    }

    // 调用已有的转账函数
    return transferMoney(from, to, amount, users);
}
int transferMoneyByAccount(struct UserArray* users, const char* fromAccount, const char* toAccount, struct Money amount) ;

#endif // CHEQUE_H
