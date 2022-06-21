#include "../core/extends-tree.h"
#define STACK_LENGTH 5

/*
 * 顺序存储结构栈实现
 * */

typedef int DataType;               /* 定义数据类型 */
typedef struct SeqStack *StackLink; /* 定义栈结构的指针 */
typedef struct SeqStack {           /* 定义栈结构体 */
    DataType buffer[STACK_LENGTH];  /* 栈空间 */
    int top;                        /* 栈顶位置 */
} SeqStack;

/**
 * @details 初始化一个空栈
 * @return 初始化成功返回栈实例指针, 否则返回NULL
 */
StackLink initialStack() {
    StackLink seqStack = (StackLink) malloc(sizeof(SeqStack));
    if (seqStack) {
        seqStack->top = -1;
        return seqStack;
    }
    return NULL;
}

/**
 * @details 返回栈的元素个数
 * @param link 栈实例指针
 * @return { int }
 */
int stackLength(StackLink link) {
    return link->top + 1;
}

/**
 * @details 清空栈
 * @param link 栈实例指针
 */
void clearStack(StackLink link) {
    link->top = -1;
}

/**
 * @details 判断栈是否为空栈
 * @param stackLink
 * @return { bool }
 */
bool isStackEmpty(StackLink stackLink) {
    return stackLink->top == -1;
}

/**
 * @details 判断栈是否为满栈
 * @param stackLink
 * @return { bool }
 */
bool isStackFull(StackLink stackLink) {
    return stackLink->top == STACK_LENGTH - 1;
}

/**
 * @details 向栈顶插入元素
 * @param stackLink 栈指针
 * @param data 插入的数据
 * @return { bool }
 */
bool push(StackLink stackLink, DataType data) {
    // 满栈的去情况禁止插入新数据
    if (isStackFull(stackLink)) {
        return false;
    }
    stackLink->buffer[++stackLink->top] = data; /* 先改变记录长度再填入元素 */
    return true;
}

/**
 * @details 弹出栈顶元素
 * @param link 栈指针
 * @param payLoad 用于接受弹出元素值的载体
 * @return { bool }
 */
bool pop(StackLink link, DataType *payLoad) {
    if (isStackEmpty(link)) {
        return false;
    }
    *payLoad = link->buffer[link->top--]; /* 先取元素再减记录长度 */
    return true;
}

/**
 * @details 取得栈顶元素
 * @param link 栈实例指针
 * @param payLoad 用于记录栈顶值的载体
 * @return { bool }
 */
bool getTopFrame(StackLink link, DataType *payLoad) {
    if (isStackEmpty(link)) {
        return false;
    }
    *payLoad = link->buffer[link->top];
    return true;
}

/**
 * @details 销毁栈实例, 释放所内存空间
 * @param link 栈实例指针
 */
void destroyStack(StackLink link) {
    if (link) {
        free(link);
    }
}

/**
 * @details 遍历栈元素
 * @param stackLink 栈实例指针
 * @param eachExecutor 用于执行遍历数据的函数
 */
void stackEachExecutor(StackLink stackLink, void (*eachExecutor)(DataType data)) {
    for (int i = 0; i <= stackLink->top; ++i) {
        eachExecutor(stackLink->buffer[i]);
    }
}
