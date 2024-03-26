#include<iostream>
#include "libA/math_lib.hpp"
#include "libB/data_structure_lib.hpp"
#include "gtest/gtest.h"

class DoubleLinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create an instance of DoubleLinkedList for each test
        list.AddNode(6);
        list.AddNode(8);
        list.AddNode(12);
        list.AddNode(18);
        list.AddNode(14);
        list.AddNode(19);
    }

    // Declare variables
    DoubleLinkedList<int> list;
};

// Test case for AddNode function
TEST_F(DoubleLinkedListTest, AddNodeTest) {
    list.AddNode(20);
    ASSERT_EQ(list.NodeSize(), 7); 
}

// Test case for InsertinNode function
TEST_F(DoubleLinkedListTest, InsertinNodeTest) {
    list.InsertinNode(12, 20);
    
    ASSERT_EQ(list.NodeSize(), 7); 
}
// Test case for deleteAtNode function
TEST_F(DoubleLinkedListTest, deleteAtNodeTest) {
    list.deleteAtNode(10);
    ASSERT_EQ(list.NodeSize(), 6); 
    list.deleteAtIndex(1);
    ASSERT_EQ(list.NodeSize(), 5); 
}

// Test case for SwapNode function
TEST_F(DoubleLinkedListTest, SwapNodeTest) {
    list.replaceNode(6, 14);
    ASSERT_EQ(list.NodeSize(), 6);
}

// // Test case for print function
TEST_F(DoubleLinkedListTest, PrintTest) {
    testing::internal::CaptureStdout(); 
    list.print();
    std::string output = testing::internal::GetCapturedStdout(); 
    ASSERT_EQ(output, "6->8->12->18->14->19->\n"); 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
