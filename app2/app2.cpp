#include <stdio.h>
#include <iostream>
#include "libB/data_structure_lib.hpp"
#include "gtest/gtest.h"


class DoubleLinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        // DoubleLinkedList instance for each test
        list->AddNode(9);
        list->AddNode(18);
        list->AddNodefromFront(7);
        list->AddNode(12);
        list->AddNode(29);
        list->AddNodefromFront(19);
        list->InsertAtIndex(1, 13);
        list->InsertinNode(12, 20);
        list->replaceNode(12, 6);
        list->print();
    }
    // variable of Double linked list declared below
    DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
};

// // Test case for InsertAtIndex function
TEST_F(DoubleLinkedListTest, InsertAtIndexTest) {
    list->InsertAtIndex(2, 17);
    bool condition = (list->NodeSize() == 9) ? true : false;
    ASSERT_TRUE(condition); 
}


// Test case for deleteAtIndex function
TEST_F(DoubleLinkedListTest, deleteAtIndexTest) {
    list->deleteAtIndex(1);
    ASSERT_NE(list->NodeSize(), 6); 
    }

// // Test case for replace function
TEST_F(DoubleLinkedListTest, replaceNodeTest) {
    list->replaceNode(6, 14);
    ASSERT_EQ(list->NodeSize(), 8);
}

// // Test case for print function
TEST_F(DoubleLinkedListTest, PrintTest) {
    testing::internal::CaptureStdout(); 
    list->print();
    std::string output = testing::internal::GetCapturedStdout(); 
    ASSERT_EQ(output, "13->19->7->9->18->6->20->29->\n"); 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
