#include "../lib/SeqStack.h"

// 栈执行器函数
void eachStack(DataType seqData) {
    printf("current stack value: %d \n", seqData);
}

// 顺序表实现栈测试
void seqStackTest() {
    StackLink stackLink = initialStack();// 初始化栈
    for (int i = 1; i <= 3; ++i) {       // 循环填充元素
        push(stackLink, i);
    }
    printf("the stack element size: %d\n", stackLength(stackLink));// 取得当前栈元素个数
    stackEachExecutor(stackLink, eachStack);                       // 遍历栈元素
    DataType stackData;
    pop(stackLink, &stackData);
    push(stackLink, 23333);
    getTopFrame(stackLink, &stackData);
    printf("the current top frame stackData value: %d\n", stackData);
    clearStack(stackLink);// 清空栈元素
    printf("after cleared element size: %d\n", stackLength(stackLink));
    destroyStack(stackLink);
}
