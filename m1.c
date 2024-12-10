#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;        

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)  
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int size;

    // 读取数组大小
    printf("请输入数组的大小: ");
    scanf("%d", &size);

    int arr[size];

    // 读取数组元素
    printf("请输入数组的元素: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;

    // 读取目标值
    printf("请输入目标值: ");
    scanf("%d", &target);

    //     使用 sizeof(arr) / sizeof(arr[0]) 计算数组的元素个数是非常常见且有效的方法，特别是在需要数组长度的情况下，比如在函数中传递数组时。
    // 这种方法的优势在于它不依赖于数组的具体大小，使得代码更具可移植性和可维护性

    int result = binarySearch(arr, size, target);

    if (result != -1)
    {
        printf("元素 %d 在索引 %d 处\n", target, result);
    }
    else
    {
        printf("元素 %d 未找到\n", target);
    }

    return 0;
}
