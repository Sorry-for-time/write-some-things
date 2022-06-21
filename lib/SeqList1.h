#include "../core/extends-tree.h"
#define LIST_SIZE 10

typedef int SeqList1Data;
typedef struct SeqList {
    SeqList1Data list[LIST_SIZE];
    int length;
} SeqList;
typedef SeqList *ListLink;

/**
 * @brief 初始化线性表
 * @param listLink 线性表结构指针
 */
void InitList(ListLink listLink) {
    listLink->length = 0;
}

/**
 * @brief 返回线性表内元素的个数
 * @param listLink 线性表结构体实例指针
 * @return { int }
 */
int LengthList(ListLink listLink) {
    return listLink->length;
}

/**
 * @brief 取表元
 * @param listLink 线性表结构体实例指针
 * @param loc 下标
 * @return { int }
 */
SeqList1Data GetList(ListLink listLink, int loc) {
    if (listLink->length == 0 || loc < 1 || loc > listLink->length) {
        printf("元素不存在\n");
        errno;
    }
    return listLink->list[loc - 1];
}

/**
 * @brief 插入操作
 * @param listLink 线性表结构体指针
 * @param data 插入的数据
 * @param loc 指定的下标
 * @return { 1 | 0 }
 */
int InsertList(ListLink listLink, SeqList1Data data, int loc) {
    // 防止非法条件, 要注意边界条件设定, 插入位置可以从1开始, 也可以接在最后(即可以为length+1
    if (listLink->length >= LIST_SIZE + 1 || loc < 1 || loc > LIST_SIZE || loc > listLink->length + 1) {
        printf("insert fail! loc --> %d\n", loc);
        return 0;
    }
    // 使用尾插法
    // 方法1
    /*for (int i = listLink->length; i >= loc; --i) {
        listLink->list[i] = listLink->list[i - 1];
    }*/
    // 循环的终止条件取决于实际条件 即--> 要确保能取到(loc-1)位置上的元素
    // 方法2
    for (int i = listLink->length - 1; i >= loc - 1; --i) {
        // 后一个元素等于前一个元素
        listLink->list[i + 1] = listLink->list[i];
    }
    listLink->list[loc - 1] = data;
    listLink->length++;
    return 1;
}

/**
 * @brief 删除操作
 * @param listLink 线性表结构体指针
 * @param loc 指定下标
 * @return { 1 | 0 }
 */
int DeleteList(ListLink listLink, int loc) {
    // 边界判断, 允许在非空表情况下loc=1, 但不允许小于1
    if (loc > listLink->length || loc < 1) {
        printf("delete fail loc --> %d\n", loc);
        return 0;
    }

    // 方法1
    /*for (int i = loc; i <= listLink->length - 1; ++i) {
        listLink[i - 1] = listLink[i];
    }*/

    // 方法2
    for (int i = loc - 1; i < listLink->length - 1; ++i) {
        listLink->list[i] = listLink->list[i + 1];
    }
    listLink->length--;

    return 1;
}

/**
 * @brief 根据值查找元素所在的下标
 * @param listLink 线性表结构体指针
 * @param data 插入的数据
 * @return { int }
 */
int LocateList(ListLink listLink, SeqList1Data data) {
    int i = 1;
    while (i <= listLink->length && listLink->list[i] != data) {
        i++;
    }
    // 找到的情况
    if (listLink->list[i - 1] == data) { return i; }
    // 没找到返回-1
    return -1;
}
