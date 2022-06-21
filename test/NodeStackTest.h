#include "../lib/StackNode.h"

void nodeStackTest() {
    LinkStack *topLinker = (LinkStack *) malloc(sizeof(LinkStack));
    InitNodeStack(topLinker);
    printf("current nodeStackLength: %d\n", getNodeStackLength(topLinker));
    for (int i = 1; i <= 5; ++i) {
        nodeStackPush(topLinker, i);// 往栈里填充元素
    }
    printf("after push data, the nodeStackLength: %d\n", getNodeStackLength(topLinker));// 填充元素后链栈的长度
    printf("========================\n");

    NodeStackData payLoad;
    getStackTop(topLinker, &payLoad);
    printf("the topLinker element data value: %d\n", payLoad);
    printf("========================\n");

    for (int i = 0; i < 3; ++i) {
        NodeStackData tmpPayLoad;
        nodeStackPop(topLinker, &tmpPayLoad);
        printf("removed node value: %d\n", tmpPayLoad);
    }
    printf("after remove nodes, the nodeStackLength: %d\n", getNodeStackLength(topLinker));
}
