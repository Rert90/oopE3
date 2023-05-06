#ifndef LAB9_H
#define LAB9_H

template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;
    };

    Node* head;
    int size;

public:
    Map() {
        head = nullptr;
        size = 0;
    }

    void Set(const K& key, const V& value) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {  // Key does not exist, insert new node
            Node* newNode = new Node{key, value, nullptr};
            if (prev == nullptr) head = newNode;
            else prev->next = newNode;
            size++;
        } else {  // Key exists, update value
            curr->value = value;
        }
    }

    bool Get(const K& key, V& value) const {
        Node* curr = head;
        while (curr != nullptr && curr->key != key) {
            curr = curr->next;
        }

        if (curr == nullptr) return false;  // Key does not exist
        value = curr->value;
        return true;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    bool Delete(const K& key) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return false;  // Key does not exist

        if (prev == nullptr) head = curr->next;     // Deleted node is head node
        else prev->next = curr->next;

        delete curr;
        size--;
        return true;
    }

    bool Includes(const Map<K,V>& map) const {
        Node* curr = head;
        while (curr != nullptr) {
            if (map.Get(curr->key, curr->value) == false) return false;
            curr = curr->next;
        }
        return true;
    }

    V& operator[](const K& key) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {  // Key does not exist, insert new node
            Node* newNode = new Node{key, V(), nullptr};
            if (prev == nullptr) head = newNode;
            else prev->next = newNode;
            size++;
            return newNode->value;
        } else {  // Key exists, return reference to value
            return curr->value;
        }
    }

public:
    struct MapNode {
        const K& key;
        const V& value;
        int index;
    };

    class Iterator {
    private:
        Node* curr;
        int index;

    public:
        Iterator(Node* head, int start) : curr(head), index(start) {}

        bool operator!=(const Iterator& other) const {
            return curr != other.curr;
        }

        bool operator==(const Iterator& other) const {
            return curr == other.curr;
        }

        Iterator& operator++() {
            curr = curr->next;
            index++;
            return *this;
        }

        MapNode operator*() const {
            return {curr->key, curr->value, index};
        }
    };

    Iterator begin() {
        return Iterator{head, 0};
    }

    Iterator end() {
        return Iterator{nullptr, size};
    }
};

#endif LAB9_H