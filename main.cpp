#include <iostream>

template<typename T> class List {
private:
    struct Node {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    Node* first = nullptr;
    Node* last = nullptr;

    int elementsCount = 0;

public:
    void PushBack(const T& elem) {
        Node* node = new Node(elem, last, nullptr);

        if (last != nullptr) {
            last->next = node;
        } else {
            first = node;
        }

        last = node;
        ++elementsCount;
    }

    void PushFront(const T& elem) {
        Node* node = new Node(elem, first, nullptr);

        if (first != nullptr) {
            first->prev = node;
        } else {
            last = node;
        }

        first = node;
        ++elementsCount;
    }

    size_t Size() const {
        return elementsCount;
    }
};

int main() {
    return 0;
}
