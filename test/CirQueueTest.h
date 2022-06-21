#include "../lib/CirQueue.h"

void cirQueueTest() {
    CirQueuePointer cirQueuePointer = initialCirQueue();
    for (int i = 1; i <= 5; ++i) {
        enterQueue(cirQueuePointer, i);
    }
    CirQueueDataType payload;
    getQueueFront(cirQueuePointer, &payload);
    printf("current front value: %d\n", payload);
    getQueueRear(cirQueuePointer, &payload);
    printf("current rear value: %d\n", payload);
    printf("=======================\n");

    for (int i = 0; i < 4; ++i) {
        deleteQueue(cirQueuePointer, &payload);
        printf("the removed value:%d \n", payload);
    }
    for (int i = 6; i <= 8; ++i) {
        enterQueue(cirQueuePointer, i);
    }
    getQueueRear(cirQueuePointer, &payload);
    printf("current rear value: %d\n", payload);
    getQueueFront(cirQueuePointer, &payload);
    printf("current front value: %d\n", payload);
    printf("=======================\n");

    printf("current queue element size: %d\n", getCirQueueSize(cirQueuePointer));
}
