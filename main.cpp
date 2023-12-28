#include <iostream>

template<typename T> class List {
private:
    struct Node {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;

        Node(const T& elem, Node* prevNode, Node* nextNode): element(elem), prev(prevNode), next(nextNode) {}
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

    void PopBack() {
        if (last != nullptr) {
            Node* temp = last;
            last = last->prev;

            if (last != nullptr) {
                last->next = nullptr; // удаление
            } else {
                first = nullptr;
            }

            delete temp;
            elementsCount--;
        }
    }

    void PopFront() {
        if (first != nullptr) {
            Node* temp = first;
            first = first->next;

            if (first != nullptr) {
                first->prev = nullptr;
            } else {
                last = nullptr;
            }

            delete temp;
            elementsCount--;
        }
    }

    size_t Size() const {
        return elementsCount;
    }

   void Clear() {
        Node* current = first;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        first = last = nullptr;
        elementsCount = 0;
    }
};

int main() {
    List<int> myIntList;

    myIntList.PushBack(10);
    myIntList.PushBack(20);
    myIntList.PushFront(5);

    std::cout << "Size of the list: " << myIntList.Size() << std::endl;


    myIntList.PopBack();
    myIntList.PopFront();


    std::cout << "Size after popping elements: " << myIntList.Size() << std::endl;

    myIntList.Clear();


    std::cout << "Size after clearing the list: " << myIntList.Size() << std::endl;

    return 0;
}