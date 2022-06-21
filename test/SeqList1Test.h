#include "../lib/SeqList1.h"

// 顺序列表测试用例
void seqList1Test() {
    SeqList seqList;
    ListLink listLink = &seqList;
    InitList(listLink);
    printf("memory used: %llf mb\n", (sizeof seqList) / 4.0 / 1024);
    printf("memory used: %lld byte\n", sizeof(*listLink));
    printf("==================\n");
    InsertList(listLink, 2313123, 8);
    printf("==========================\n");
    for (int i = 1; i <= 20; ++i) {
        InsertList(listLink, 233, i);
    }
    for (int i = 1; i <= 20; ++i) {
        DeleteList(listLink, 1);
    }
}
