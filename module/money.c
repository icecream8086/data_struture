/**
 * @file money.c
 * @author your name (icecream8086@outlook.com)
 * @brief 测试用例，货币
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <math.h>

struct Money {
    long long cents;
};

// 创建货币实例（例如10.75元表示为1075分）
struct Money createMoney(int yuan, int cents) {
    struct Money m;
    m.cents = (long long)yuan * 100 + cents;
    return m;
}

// 打印货币信息
void printMoney(struct Money m) {
    printf("¥%lld.%02lld\n", m.cents / 100, m.cents % 100);
}

// 货币相加
struct Money addMoney(struct Money m1, struct Money m2) {
    struct Money result;
    result.cents = m1.cents + m2.cents;
    return result;
}

// 货币相减
struct Money subtractMoney(struct Money m1, struct Money m2) {
    struct Money result;
    result.cents = m1.cents - m2.cents;
    return result;
}

// 货币乘法
struct Money multiplyMoney(struct Money m, double factor) {
    struct Money result;
    result.cents = (long long)round(m.cents * factor);
    return result;
}

// 货币除法
struct Money divideMoney(struct Money m, double divisor, int* remainder) {
    struct Money result;
    double temp_result = m.cents / divisor;
    result.cents = (long long)floor(temp_result);
    *remainder = (int)round((temp_result - result.cents) * divisor);
    return result;
}

int main() {
    struct Money money1 = createMoney(10, 75); // 10.75元
    struct Money money2 = createMoney(5, 50);  // 5.50元

    struct Money sum = addMoney(money1, money2);
    struct Money difference = subtractMoney(money1, money2);
    struct Money product = multiplyMoney(money1, 1.5); // 乘以1.5

    int remainder;
    struct Money quotient = divideMoney(money1, 3.8, &remainder);  // 除以3.8

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

    return 0;
}
