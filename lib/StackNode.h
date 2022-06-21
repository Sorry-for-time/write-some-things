#include "../core/extends-tree.h"

typedef int NodeStackData;                  /* 定义链栈节点的数据类型 */
typedef struct StackNode *StackNodePointer; /* 定义链栈节点的的指针 */
typedef struct StackNode {                  /* 定义链栈节点 */
    NodeStackData data;                     /* 数据域 */
    StackNodePointer next;                  /* 指向域 */
} StackNode;
typedef struct {          /* 定义栈顶描述 */
    StackNodePointer top; /* 定义栈顶指针 */
} LinkStack;

/**
 * @details 初始化一个空栈
 * @param headPointer 栈顶描述指针
 */
void InitNodeStack(LinkStack *headPointer) {
    headPointer->top = NULL; /* 初始化栈, 设置栈顶为空 */
}

/**
 * @details 获取链栈的元素个数
 * @param linkStack 栈顶描述指针
 * @return { int }
 */
int getNodeStackLength(LinkStack *linkStack) {
    LinkStack *current = (LinkStack *) malloc(sizeof(LinkStack));
    current->top = linkStack->top;
    int count = 0;
    while (current->top != NULL) {
        current->top = current->top->next;
        ++count;
    }
    free(current);
    return count;
}

/**
 * @details 判断当前栈是否为空栈
 * @param topLiner 栈定描述指针
 * @return { bool }
 */
bool isNodeStackEmpty(LinkStack *topLiner) {
    return topLiner->top == NULL;
}

/**
 * @details 取得栈顶元素值
 * @param topLinker 栈顶描述指针
 * @param payLoad 用于承接栈顶节点数据的载体
 * @return { bool }
 */
bool getStackTop(LinkStack *topLinker, NodeStackData *payLoad) {
    if (!isNodeStackEmpty(topLinker)) {
        *payLoad = topLinker->top->data;
        return true;
    }
    return false;
}

/**
 * @details 往栈中插入新的数据
 * @param topPointer 栈顶描述指针
 * @param data 插入的数据
 * @return { bool }
 */
bool nodeStackPush(LinkStack *topPointer, NodeStackData data) {
    StackNodePointer insertedNode = (StackNodePointer) malloc(sizeof(StackNode));
    if (insertedNode) {
        insertedNode->data = data;
        insertedNode->next = topPointer->top;
        topPointer->top = insertedNode;
        return true;
    }
    return false;
}

/**
 * @details 移除栈顶元素
 * @param topLinker 栈顶描述指针
 * @param payload 用于承接被移除元素数据域值的载体
 * @return { bool }
 */
bool nodeStackPop(LinkStack *topLinker, NodeStackData *payload) {
    if (!isNodeStackEmpty(topLinker)) {
        StackNodePointer waitRemove = topLinker->top;
        *payload = waitRemove->data;
        topLinker->top = waitRemove->next;
        free(waitRemove);
        return true;
    }
    return false;
}
