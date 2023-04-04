#include <iostream>
#include "TreeNode.h"
using namespace std;
int main() {
    TreeNode<int>* root = new TreeNode<int>(1);


    TreeNode<int>* child1 = new TreeNode<int>(2);
    root->add_node(child1);
    TreeNode<int>* child2 = new TreeNode<int>(3);
    root->add_node(child2);


    TreeNode<int>* grandchild1 = new TreeNode<int>(4);
    child1->insert(child1, 0, grandchild1);

    child1->sort([](const int& a, const int& b) { return a > b; });


    cout << "Child count: " << root->count(root) << endl;
    TreeNode<int>* node2 = root->find([](const int& a, const int& b) { return a == b; }, 2);
    if (node2 != nullptr) {
        cout << "Found node with value 2" << endl;
    }


    return 0;

}