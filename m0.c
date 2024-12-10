#include <stdio.h>
//for i
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 3};
    int target = 7;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("元素 %d 在索引 %d 处\n", target, result);
    } else {
        printf("元素 %d 未找到\n", target);
    }

    return 0;
}
