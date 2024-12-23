#include <stdio.h>
#include "./lib/bank_db.h"
#include "./lib/bankoc.h"
#include "./lib/ref.h"
#include "./lib/f_io.h"
/// @brief 测试文件,用于测试最小货币账户状态迁移是否有效
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char const *argv[])
{
    // money
    struct Money money1 = createMoney(10, 75); // 10.75元
    struct Money money2 = createMoney(5, 50);  // 5.50元
    struct Money sum = addMoney(money1, money2);
    struct Money difference = subtractMoney(money1, money2);
    struct Money product = multiplyMoney(money1, 1.5); // 乘以1.5
    int remainder;
    struct Money quotient = divideMoney(money1, 3.8, &remainder); // 除以3.8

    printf("money1: ");
    printMoney(money1);

    printf("money2: ");
    printMoney(money2);

    printf("Sum: ");
    printMoney(sum);

    printf("Difference: ");
    printMoney(difference);

    printf("Product (money1 * 1.5): ");
    printMoney(product);

    printf("Quotient (money1 / 3.8): ");
    printMoney(quotient);
    printf("Remainder: %d cents\n", remainder);
    // user test
    struct UserArray users;
    initUserArray(&users);
    struct User user1 = {"Alice", "alice123", money1};
    struct User user2 = {"Bob", "bob456", money2};
    addUser(&users, user1);
    addUser(&users, user2);
    
    printAllUsers(&users);

    //file test
    
    // 从文件加载用户数据
    loadUsersFromFile(&users, "users.csv");
    // 打印所有用户
    printf("Users loaded from file:\n");
    
    // 添加一个新用户
    struct User newUser = {"ACAWCAW", "alawDAe123", 5000};
    addUser(&users, newUser);

    
    printAllUsers(&users);

    // 查找一个用户
    struct User* foundUser = findUserByName(&users, "ACAWCAW");
    if (foundUser) {
        printf("Found user: Name: %s, Account: %s, Cents: %lld\n", foundUser->name, foundUser->account, foundUser->money.cents);
    }

    // 打印所有用户
    printf("Users after deleting Alice:\n");
    printAllUsers(&users);
    printf("Users after deleting Alice:\n");

    // 保存用户数据到文件(带去重)
    saveUsersToFile(&users, "users.csv");

    // 释放内存
    free(users.users);

    
    
}
