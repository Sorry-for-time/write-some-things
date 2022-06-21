#include "../core/extends-tree.h"

typedef int NodeQueueData;           /* 定义链队列节点存储的数据类型 */
typedef struct QueueNode *NodeUsage; /* 定义节点指针 */
typedef struct QueueNode {           /* 定义链队列节点结构 */
    NodeQueueData dataItem;
    NodeUsage next;
} QueueNode;
typedef struct Queue { /* 定义链队列结构体 */
    NodeUsage front;   /* 队首指针 */
    NodeUsage rear;    /* 队尾指针 */
} Queue, *QueueLink;

/**
 * @details 初始化一个链队列
 * @return { QueueLink }
 */
QueueLink initialQueue() {
    QueueLink back = (QueueLink) malloc(sizeof(Queue));
    if (back) {
        back->front = NULL;
        back->rear = NULL;
        return back;
    }
    return NULL;
}

/**
 * @details 判断当前链队列是否为空队列
 * @param queue 链队列实例指针
 * @return { bool }
 */
bool isNodeQueueEmpty(QueueLink queue) {
    return queue->front == NULL;
}

/**
 * @details 往链队列队尾插入新的元素
 * @param queue 链队列实例指针
 * @param data 插入队尾的数据
 * @return { bool }
 */
bool insertIntoNodeQueue(QueueLink queue, NodeQueueData data) {
    NodeUsage insertedNode = (NodeUsage) malloc(sizeof(QueueNode));
    if (insertedNode) {
        insertedNode->dataItem = data;
        insertedNode->next = NULL;
        if (queue->rear != NULL) {
            queue->rear->next = insertedNode;
            queue->rear = insertedNode;
        } else {
            queue->front = insertedNode;
            queue->rear = insertedNode;
        }
        return true;
    }
    return false;
}

/**
 * @details 删除队首的元素并将其节点的数据域的值赋予载体
 * @param queue 链队列实例指针
 * @param payload 用于承接队首节点数据域的值
 * @return { bool }
 */
bool deleteFromNodeQueue(QueueLink queue, NodeQueueData *payload) {
    if (!isNodeQueueEmpty(queue)) {
        NodeUsage current = queue->front;
        *payload = current->dataItem;
        queue->front = current->next;
        if (current == queue->rear) {
            queue->rear = NULL;
        }
        free(current);
        return true;
    }
    return false;
}

/**
 * @details 从头指针位置遍历链队列
 * @param queueLink 链队列实例指针
 * @param executor 迭代执行函数
 */
void nodeQueueEach(QueueLink queueLink, void (*executor)(NodeUsage receive)) {
    NodeUsage currentNode = queueLink->front;
    while (currentNode) {
        executor(currentNode);
        currentNode = currentNode->next;
    }
}
