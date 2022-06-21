#include "../core/extends-tree.h"

// @brief 带头节点的单链表
// @version v0.01

/**
 * @details 定义数据类型
 */
typedef int SeqList2Data;      /* 定义节点数据域的数据类型 */
typedef struct Node *NodeList; /* 定义节点指针 */

/**
 * @details 节点数据结构
 */
typedef struct Node {
    SeqList2Data data; /* 数据域 */
    struct Node *next; /* 指针域 */
} Node;
typedef void eachReturnType; /* 定义迭代执行器返回的数据类型 */

/**
 * @details 初始化链表
 * @return { NodeList | NULL}
 */
NodeList initialList() {
    NodeList head = (NodeList) malloc(sizeof(Node));
    if (head) {
        head->next = NULL; /* 将指向域置空 */
        return head;
    }
    return NULL;
}

/**
 * @details 返回链表元素个数
 * @param list 链表指针
 * @return { int }
 */
int getListLength(NodeList list) {
    int i = 0;
    NodeList current = list->next;
    while (current) {
        ++i;
        current = current->next;
    }
    return i;
}

/**
 * @details 根据指定下标将元素插入链表
 * @param head 单链表头指针
 * @param aNode 新节点的指针
 * @param loc 指定下标
 * @return { bool }
 */
bool insertToList(NodeList head, Node *aNode, int loc) {
    int count = 0;   // 计数器, 用于记录下标
    Node *tmp = head;// 临时变量, 用于记录交换数据
    while (tmp) {
        if (++count == loc) {
            aNode->next = tmp->next;
            tmp->next = aNode;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

/**
 * @details 根据下标删除指定位置的元素
 * @param head 头指针
 * @param loc 指定下标
 * @return { bool }
 */
bool deleteListByIndex(NodeList head, int loc) {
    if (loc < 1 || !head->next) {
        return false;
    }
    Node *currentNode = head; /* 记录状态 */
    int count = 0;            /* 计数器 */
    while (currentNode) {     /* 进行迭代 */
        if (++count == loc) {
            Node *tmp = currentNode->next;     /* 记录要删除的节点 */
            if (tmp->next) {                   /* 判断要删除节点是否指针域不为空 */
                currentNode->next = tmp->next; /* 更新当前节点的指针域, 指向为要删除节点的指针域所指节点 */
                free(tmp);                     /* 移除标记节点, 释放内存空间 */
            } else {                           /* 要删除节点指针域为空的情况, 即被删除节点为尾节点 */
                currentNode->next = NULL;      /* 当前节点指针域更新, 标记为空 */
                free(tmp);                     /* 移除尾节点, 释放内存空间 */
            }
            return true; /* 终止遍历, 返沪成功标识 */
        }
        currentNode = currentNode->next; /* 更新当前节点, 进行节点后移 */
    }
    return false;
}

/**
 * @details 单链表遍历
 * @param head 单链表头指针
 * @param eachExecutor 迭代执行函数
 */
void ListEach(NodeList head, eachReturnType (*eachExecutor)(Node *node)) {
    NodeList tmp = head->next;
    while (tmp) {
        eachExecutor(tmp); /* 执行迭代函数 */
        tmp = tmp->next;   /* 指针后移 */
    }
}

/**
 * @details 根据给定的值查找单链表中元素首次出现的位置
 * @param head 单链表头指针
 * @param matchedData 进行查找的值
 * @return { int }
 */
int getIndexByValue(NodeList head, SeqList2Data matchedData) {
    int index = 0;
    NodeList tmp = head->next;
    while (tmp) {
        ++index;
        if (tmp->data == matchedData) {
            return index;
        }
        tmp = tmp->next;
    }
    return -1;
}

/**
 * @details 根据指定下标将对应元素值赋予载体
 * @param head 单链表头指针
 * @param loc 取值的指定位置
 * @param payload 载体
 */
void getValueByIndex(NodeList head, int loc, SeqList2Data *payload) {
    // 阻止非法下标和空头节点的情况
    if (loc < 1 || !head->next) {
        return;
    }
    NodeList tmp = head;
    int count = 0;
    while (tmp) {
        tmp = tmp->next;
        if (++count == loc) {
            *payload = tmp->data;
            return;// 匹配成功, 终止循环
        }
    }
}
