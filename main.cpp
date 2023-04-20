#include <iostream>

#include "include/SegmentTree.h"

int main(int, char**) {
    std::cout << "Hello, from Segment Tree!\n";

    int elementSize = 5;

    std::vector<int> v(elementSize);
    for (int i = 1; i <= elementSize; i++) {
        v[i] = i + 1;
    }

    SegmentTree tree;
    tree.build(v);
    cout<<tree.query(2,4)<<endl;
    tree.updateData(2,11);
    cout<<tree.query(2,4)<<endl;

}
