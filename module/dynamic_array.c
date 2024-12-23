/**
 * @file dynamic_array.c
 * @author icecream8086 (icecream8086@outlook.com)
 * @brief 动态数组参考
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void initUserArray(struct UserArray* arr) {
    arr->size = 0;
    arr->capacity = 10;
    arr->users = (struct User*)malloc(arr->capacity * sizeof(struct User));
}

void resizeUserArray(struct UserArray* arr) {
    arr->capacity *= 2;
    arr->users = (struct User*)realloc(arr->users, arr->capacity * sizeof(struct User));
}

void addUser(struct UserArray* arr, struct User user) {
    if (arr->size == arr->capacity) {
        resizeUserArray(arr);
    }
    arr->users[arr->size++] = user;
}

struct User* findUser(struct UserArray* arr, const char* account) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].account, account) == 0) {
            return &arr->users[i];
        }
    }
    return NULL;
}

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

void updateUser(struct UserArray* arr, struct User user) {
    struct User* existingUser = findUser(arr, user.account);
    if (existingUser) {
        *existingUser = user;
    }
}

void printUser(const struct User* user) {
    printf("Name: %s\n", user->name);
    printf("Account: %s\n", user->account);
    printf("Money: %lld cents\n", user->money.cents);
}

void printAllUsers(const struct UserArray* arr) {
    for (size_t i = 0; i < arr->size; i++) {
        printUser(&arr->users[i]);
        printf("----\n");
    }
}

int main() {
    struct UserArray users;
    initUserArray(&users);

    struct User user1 = {"Alice", "alice123", {10050}};
    struct User user2 = {"Bob", "bob456", {20075}};

    addUser(&users, user1);
    addUser(&users, user2);

    printAllUsers(&users);

    struct User* foundUser = findUser(&users, "alice123");
    if (foundUser) {
        printf("Found user:\n");
        printUser(foundUser);
    }

    struct User userUpdated = {"Alice", "alice123", {50000}};
    updateUser(&users, userUpdated);

    printAllUsers(&users);

    removeUser(&users, "bob456");
    printAllUsers(&users);

    free(users.users);

    return 0;
}
