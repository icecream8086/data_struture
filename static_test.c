#include <stdio.h>
#include "./lib/bank_db.h"
#include "./lib/ref.h"
int main(int argc, char const *argv[])
{
    struct UserArray users;
    initUserArray(&users);
        struct User user1 = {"Alice", "alice123", {10050}};
    struct User user2 = {"Bob", "bob456", {20075}};

    addUser(&users, user1);
    addUser(&users, user2);

    printAllUsers(&users);
}
