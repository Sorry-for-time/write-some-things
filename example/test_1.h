#include <stdio.h>

/**
 * @details 往数组中指定的位置插入数据
 * @brief 尾插法
 * @param arr 数组
 * @param element 待插入元素
 * @param index 指定下标
 * @param arrLength 数组长度
 */
void arrayInsert(int *arr, int element, int index, int arrLength) {
    for (; arrLength >= index; --arrLength) {
        arr[arrLength] = arr[arrLength - 1];
    }
    arr[index - 1] = element;
}

void executeTest() {
    int arr[7] = {1, 2, 3, 5, 6, 7};
    for (int i = 0; i < 7; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    arrayInsert(arr, 4, 4, 7);
    for (int i = 0; i < 7; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}