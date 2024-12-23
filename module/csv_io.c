#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义一个结构体表示一个用户
struct User {
    char name[50];
    char account[50];
    long long cents;
};

// 定义一个结构体表示用户数组
struct UserArray {
    struct User* users;
    size_t size;
    size_t capacity;
};

// 初始化用户数组
void initUserArray(struct UserArray* arr) {
    arr->size = 0;
    arr->capacity = 10;
    arr->users = (struct User*)malloc(arr->capacity * sizeof(struct User));
}

// 调整用户数组大小
void resizeUserArray(struct UserArray* arr) {
    arr->capacity *= 2;
    arr->users = (struct User*)realloc(arr->users, arr->capacity * sizeof(struct User));
}

// 添加用户到数组
void addUser(struct UserArray* arr, struct User user) {
    if (arr->size == arr->capacity) {
        resizeUserArray(arr);
    }
    arr->users[arr->size++] = user;
    printf("Added user: %s, %s, %lld\n", user.name, user.account, user.cents); // Debug statement
}

// 从文件加载用户数据
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

// 保存用户数据到文件
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

// 打印所有用户信息
void printUsers(const struct UserArray* arr) {
    for (size_t i = 0; i < arr->size; i++) {
        printf("Name: %s, Account: %s, Cents: %lld\n", arr->users[i].name, arr->users[i].account, arr->users[i].cents);
    }
}

// 根据名字查找用户
struct User* findUserByName(const struct UserArray* arr, const char* name) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].name, name) == 0) {
            return &arr->users[i];
        }
    }
    return NULL;
}

// 根据名字删除用户
void deleteUserByName(struct UserArray* arr, const char* name) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->users[i].name, name) == 0) {
            // 将最后一个用户移到当前的位置
            arr->users[i] = arr->users[--arr->size];
            return;
        }
    }
}

int main() {
    struct UserArray users;
    initUserArray(&users);

    // 从文件加载用户数据
    loadUsersFromFile(&users, "users.csv");

    // 打印所有用户
    printf("Users loaded from file:\n");
    printUsers(&users);

    // 添加一个新用户
    struct User newUser = {"Alice", "alice123", 5000};
    addUser(&users, newUser);

    // 打印所有用户
    printf("Users after adding Alice:\n");
    printUsers(&users);

    // 查找一个用户
    struct User* foundUser = findUserByName(&users, "Alice");
    if (foundUser) {
        printf("Found user: Name: %s, Account: %s, Cents: %lld\n", foundUser->name, foundUser->account, foundUser->cents);
    }

    // 删除一个用户
    // deleteUserByName(&users, "Alice");

    // 打印所有用户
    printf("Users after deleting Alice:\n");
    printUsers(&users);

    // 保存用户数据到文件
    saveUsersToFile(&users, "users.csv");

    // 释放内存
    free(users.users);

    return 0;
}
