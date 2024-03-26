The file structure is as follows:

- `data-structure.hpp` can be found at `/project2-master/libs/libB`. It contains both the declaration and definition of all the functions implemented.

After building this project, three apps were used in testing the Double linked list functionalities.

1. The first app is `app`, which contains `main.cpp`. It can be found at `/project2-master/main.cpp`.

The test code is as follows:

```cpp
#include<iostream>
#include "libB/data_structure_lib.hpp"

int main() {
    DoubleLinkedList<int> Listmy;
    Listmy.AddNode(6);
    Listmy.AddNode(8);
    Listmy.AddNode(12);
    std::cout << "when three node are added to the empty list using AddNode() function" << std::endl;
    Listmy.print();
    std::cout << "Size: " << Listmy.NodeSize() << std::endl;
    Listmy.AddNodefromFront(18);
    Listmy.AddNode(14);
    Listmy.AddNode(19);
    std::cout << "when 18 is added to be the first node and two more node are added using AddNode() function" << std::endl;
    Listmy.print();
    std::cout << "Size: " << Listmy.NodeSize() << std::endl;
    Listmy.InsertAtIndex(1, 13);
    Listmy.InsertAtIndex(3, 21);
    std::cout << "when 13 is inserted at first node and 21 at the third node" << std::endl;
    Listmy.print();
    std::cout << "Size: " << Listmy.NodeSize() << std::endl;
    Listmy.InsertinNode(8, 4);
    Listmy.InsertinNode(14, 15);
    std::cout << "when 4 is inserted in front 8 and 15 in front 14 " << std::endl;
    Listmy.print();
    std::cout << "Size: " << Listmy.NodeSize() << std::endl;
    Listmy.replaceNode(12, 3);
    std::cout << "when node 12 is repalaced with node 3 " << std::endl;
    Listmy.print();
    Listmy.deleteAtIndex(4);
    std::cout << "when node at index 4  " << std::endl;
    Listmy.print();
    Listmy.deleteAtIndex(1);
    std::cout << "when index 1 are been deleted " << std::endl;
    Listmy.print();
    std::cout << "Size: " << Listmy.NodeSize() << std::endl;
    Listmy.deleteAtNode(19);
    std::cout << "when node 19 is been deleted " << std::endl;
    Listmy.print();
    Listmy.deleteAtNode(15);
    std::cout << "when 15 is been deleted " << std::endl;
    Listmy.print();
    std::cout << "Size: " << Listmy.NodeSize() << std::endl;
    return 0;
}
```
* theThe second app, called `app1`, can be found at `/project2-master/app1/app1.cpp`. Below is the code:

```cpp
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

// Test case for print function
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
```

* The third app, named `app2`, can be found at `/project2-master/app2/app2.cpp`. Below is the code:

```cpp
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

// Test case for InsertAtIndex function
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

// Test case for replace function
TEST_F(DoubleLinkedListTest, replaceNodeTest) {
    list->replaceNode(6, 14);
    ASSERT_EQ(list->NodeSize(), 8);
}

// Test case for print function
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

```
* To replicate the test, follow these steps:

1. Delete the existing `build` folder if it exists.

2. Create a new folder named `build`. If you are using Visual Studio Code, open the terminal and navigate to the project directory. Then, create the directory using the command: `$ mkdir build`.

3. Change directory to the newly created `build` folder: `$ cd build`.

4. Run CMake to generate the build files: `$ cmake ..`.

5. Build the project using the generated build files: `$ make all`.

6. After building successfully, execute the following commands based on the app you want to run:
   - For the first app, use: `$ ./bin/app`.
   - For the second app, use: `$ ./bin/app1`.
   - For the third app, use: `$ ./bin/app2`.

Make sure to execute these commands in the terminal and ensure that you are in the `build` directory before running them.
