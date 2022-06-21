cmake_minimum_required(VERSION 3.21)
project(write-some-things)

set(CMAKE_C_STANDARD 11)

add_executable(write-some-things main.c lib/SeqList1.h example/test_1.h lib/SeqList2.h core/extends-tree.h lib/SeqStack.h test/SeqStackTest.h test/SeqList2Test.h test/SeqList1Test.h lib/CirQueue.h lib/StackNode.h test/NodeStackTest.h test/CirQueueTest.h lib/NodeQueue.h test/NodeQueueTest.h lib/BinaryTree.h test/BinaryTreeTest.h)

