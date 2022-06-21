#include "../lib/NodeQueue.h"

/**
 * @details 迭代测试函数
 * @param receive 节点实例指针
 */
void nodeQueueFn(NodeUsage receive) {
    printf("current receive node dataItem value: %d\n", receive->dataItem);
}

void nodeQueueTest() {
    QueueLink queue = initialQueue();
    for (int i = 1; i <= 100; i++) {
        insertIntoNodeQueue(queue, i);
    }

    nodeQueueEach(queue, nodeQueueFn);
    printf("===========================\n");

    NodeQueueData payload;
    while (!isNodeQueueEmpty(queue)) {
        deleteFromNodeQueue(queue, &payload);
        printf("the removed node value: %d\n", payload);
    }
}
