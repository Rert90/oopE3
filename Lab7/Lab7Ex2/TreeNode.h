#include <iostream>

template <typename T>
class TreeNode {
public:
    TreeNode(const T& value): value(value), childCount(0), firstChild(nullptr) {}


    void add_node(TreeNode* child) {
        child->nextSibling = firstChild;
        firstChild = child;
        childCount++;
    }

    TreeNode* get_node(TreeNode* parent=nullptr) {
        if (parent == nullptr) {
            return this;
        }
        for (TreeNode* child = firstChild; child != nullptr; child = child->nextSibling) {
            TreeNode* node = child->get_node(parent);
            if (node != nullptr) {
                return node;
            }
        }
        return nullptr;
    }


    void delete_node() {
        while (firstChild != nullptr) {
            TreeNode* child = firstChild;
            firstChild = firstChild->nextSibling;
            if (child != nullptr) {
                child->delete_node();
            }
        }
        delete this;
    }


    TreeNode* find(bool (*compare)(const T& a, const T& b), const T& val) {
        if (compare(val, this->value)) {
            return this;
        }
        for (TreeNode* child = firstChild; child != nullptr; child = child->nextSibling) {
            TreeNode* node = child->find(compare, val);
            if (node != nullptr) {
                return node;
            }
        }
        return nullptr;
    }


    void insert(TreeNode* parent, int index, TreeNode* node) {
        if (parent == nullptr) {
            if (index == 0) {
                node->nextSibling = firstChild;
                firstChild = node;
                childCount++;
            }
        } else {
            if (index == 0) {
                node->nextSibling = parent->firstChild;
                parent->firstChild = node;
                parent->childCount++;
            } else {
                TreeNode* prev = parent->firstChild;
                for (int i = 1; i < index && prev != nullptr; i++) {
                    prev = prev->nextSibling;
                }
                if (prev != nullptr) {
                    node->nextSibling = prev->nextSibling;
                    prev->nextSibling = node;
                    parent->childCount++;
                }
            }
        }
    }


    void sort(bool (*compare)(const T& a, const T& b)=nullptr) {
        if (childCount > 1) {
            for (TreeNode* i = firstChild; i != nullptr; i = i->nextSibling) {
                for (TreeNode* j = i->nextSibling; j != nullptr; j = j->nextSibling) {
                    if (compare == nullptr) {
                        if (j->value < i->value) {
                            T temp = i->value;
                            i->value = j->value;
                            j->value = temp;
                        }
                    } else {
                        if (compare(j->value, i->value)) {
                            T temp = i->value;
                            i->value = j->value;
                            j->value = temp;
                        }
                    }
                }
            }
        }
        for (TreeNode* child = firstChild; child != nullptr; child = child->nextSibling) {
            child->sort(compare);
        }
    }

    int count(TreeNode* parent=nullptr) {
        if (parent == nullptr) {
            int totalCount = 1;
            for (TreeNode* child = firstChild; child != nullptr; child = child->nextSibling) {
                totalCount += child->count(this);
            }
            return totalCount;
        } else {
            int totalCount = 1;
            for (TreeNode* child = parent->firstChild; child != nullptr; child = child->nextSibling) {
                totalCount += child->count(child);
            }
            return totalCount;
        }
    }
private:
    T value;
    int childCount;
    TreeNode* firstChild;
    TreeNode* nextSibling;
};

