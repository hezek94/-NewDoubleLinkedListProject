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
