#include "../core/extends-tree.h"
#define SEQUENCE_SIZE 7

/* 定义一个顺序存储结构的循环队列 */

typedef int CirQueueDataType;             /* 定义队列存储的数据类型 */
typedef struct CirQueue *CirQueuePointer; /* 循环队列指针 */
typedef struct CirQueue {                 /* 定义循环队列结构 */
    /**
     * 需要花费一位空间用于记录容量信息
     * 即使用索引0处位置存放使用容量信息
     */
    CirQueueDataType buffer[SEQUENCE_SIZE];
    int count; /* 记录容量 */
    int front; /* 首指针 */
    int rear;  /* 尾指针 */
} CirQueue;

/**
 * @details 初始化一个空循环队列
 * @return 返回循环队列实例指针, 如果初始化失败则返回NULL
 */
CirQueuePointer initialCirQueue() {
    CirQueuePointer link = (CirQueuePointer) malloc(sizeof(CirQueue));
    if (link != NULL) {
        link->count = link->rear = link->front = 0;
        return link;
    }
    return NULL;
}

/**
 * @details 判断队列是否为空队列
 * @param cirQueuePointer 队列实例指针
 * @return 为空返回true, 否则返回false
 */
bool isCirQueueEmpty(CirQueuePointer cirQueuePointer) {
    return cirQueuePointer->count == 0;
}

/**
 * @details 判断队列是否已满
 * @param cirQueuePointer 队列实例指针
 * @return { bool }
 */
bool isCirQueueFull(CirQueuePointer cirQueuePointer) {
    return cirQueuePointer->count == SEQUENCE_SIZE;
}

/**
 * @details 返回循环队列里的元素个数
 * @cite (rear-front+queue_size)%queue_size
 * @param pointer 循环队列实例指针
 * @return { int }
 */
int getCirQueueSize(CirQueuePointer pointer) {
    return (pointer->rear - pointer->front + SEQUENCE_SIZE) % SEQUENCE_SIZE;
}

/**
 * @details 取得队首元素
 * @param pointer 循环队列实例指针
 * @param payload 用于承载队首数据的载体
 * @return { bool }
 */
bool getQueueFront(CirQueuePointer pointer, CirQueueDataType *payload) {
    if (!isCirQueueEmpty(pointer)) {
        *payload = pointer->buffer[pointer->front];
        return true;
    }
    return false;
}

/**
 * @details 取得队尾元素
 * @param pointer 循环队列实例指针
 * @param payload 用于承接队尾数据的载体
 * @return { bool }
 */
bool getQueueRear(CirQueuePointer pointer, CirQueueDataType *payload) {
    if (!isCirQueueEmpty(pointer)) {
        *payload = pointer->buffer[abs((pointer->rear - 1) % SEQUENCE_SIZE)];
        return true;
    }
    return false;
}

/**
 * @details 循环队列入队
 * @param pointer 循环队列实例指针
 * @param data 插入的数据
 * @return { bool }
 */
bool enterQueue(CirQueuePointer pointer, CirQueueDataType data) {
    if (!isCirQueueFull(pointer)) {
        pointer->buffer[pointer->rear] = data;
        pointer->count++;
        pointer->rear = (pointer->rear + 1) % SEQUENCE_SIZE;
        return true;
    }
    return false;
}

/**
 * @details 循环队列出队
 * @param pointer 循环队列实例指针
 * @param payload 用于承载出队的数据
 * @return { bool }
 */
bool deleteQueue(CirQueuePointer pointer, CirQueueDataType *payload) {
    if (!isCirQueueEmpty(pointer)) {
        *payload = pointer->buffer[pointer->front];
        pointer->count--;
        pointer->front = (pointer->front + 1) % (SEQUENCE_SIZE);
        return true;
    }
    return false;
}
