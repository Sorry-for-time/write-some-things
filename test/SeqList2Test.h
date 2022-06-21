#include "../lib/SeqList2.h"

/**
 * @details 迭代执行的函数
 * @param data 表元
 */
void eachFn(Node *node) {
    printf("current node value: %d\n", node->data);
}
// 带头单链表测试用例
void seqList2Test() {
    NodeList header = initialList();// 初始化链表
    printf("current nodeList length: %d\n", getListLength(header));
    printf("=======================\n");
    for (int i = 1; i <= 5; ++i) {
        Node *tmp = (NodeList) malloc(sizeof(Node));
        tmp->data = i,
        tmp->next = NULL;
        insertToList(header, tmp, i);
    }
    ListEach(header, eachFn);// 遍历当前链表
    printf("current nodeList length: %d\n", getListLength(header));
    printf("=======================\n");
    // 删除元素
    for (int i = 1; i <= 3; ++i) {
        deleteListByIndex(header, 1);
    }
    ListEach(header, eachFn);// 遍历链表
    printf("=======================\n");
    printf("value: %d matched index: %d\n", 4, getIndexByValue(header, 4));

    printf("=======================\n");
    SeqList2Data pay = 0;
    getValueByIndex(header, 2, &pay);
    printf("the index %d mapped value -> %d\n", 2, pay);
    printf("after deleted: current nodeList length: %d\n", getListLength(header));
}
