#include <stdio.h>
#include <stdlib.h>
#define ENDKEY 0

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // 找到目标值，返回索引
        }
    }
    return -1;  // 未找到目标值，返回-1
}

int binarySearch(int arr[], int l, int r, int target) {
    while (l <= r) {
        int m = l + (r - l) / 2;  // 计算中间索引，防止溢出
        if (arr[m] == target) {
            return m;  // 找到目标值，返回索引
        } else if (arr[m] < target) {
            l = m + 1;  // 更新左边界
        } else {
            r = m - 1;  // 更新右边界
        }
    }
    return -1;  // 如果未找到，返回-1
}


int main() {
    int arr[100]; // 假设数组最大长度为100
    int n, target, choice;
    // 输入数组长度和元素
    printf("请输入数组中的元素个数：");
    scanf("%d", &n);
    printf("请输入%d个元素：", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
        // 输入要查找的目标值
    printf("请输入要查找的目标值：");
    scanf("%d", &target);
    // 选择查找方式
    printf("请选择查找方法：\n1. 顺序查找\n2. 折半查找\n");
    scanf("%d", &choice);
    if (choice == 1) {
        int index = sequentialSearch(arr, n, target);
        if (index != -1) {
            printf("值 %d 找到在数组的位置：%d\n", target, index + 1);
        } else {
            printf("值 %d 未找到\n", target);
        }
    } else if (choice == 2) {
        // 先对数组进行排序
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;  // 交换
                }
            }
        }
        int index = binarySearch(arr, 0, n - 1, target);
        if (index != -1) {
            printf("值 %d 找到在数组的位置：%d\n", target, index + 1);
        } else {
            printf("值 %d 未找到\n", target);
        }
    } else {
        printf("无效的选择\n");
    }

}
