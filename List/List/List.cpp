#include <iostream>
using namespace std; 

template<typename T>
class Node {
public:
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    T data;
    Node(T data) {
        this->data = data; 
    }
};
template<typename T>
class List {
    int count;
    Node<T>* head;
    Node<T>* tail;
public:

    List() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void push_back(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            tail = head; 
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            newNode->prev = tail; 
            tail->next = newNode; 
            tail = newNode; 
        }
        count++;
    }

    void push_front(T data) {
        Node<T>* buf = new Node<T>(data);
        if (head == nullptr) {
            head = buf;
            tail = head;
        }
        else {
            buf->next = head;
            tail->prev = buf;
            head = buf;
        }
        count++;
    }

    int size() {
        return count;
    }

    T front() {
        return head->data;
    }

    T back() {
        return tail->data;
    }

    void show() {
        Node<T>* buf = head;
        while (buf != nullptr) {
            cout << buf->data << " ";
            buf = buf->next;
        }
        cout << std::endl;
    }

    void insert(int position, T data) {
        Node<T>* newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            tail = head;
        }
        else if (position == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            Node<T>* buf = head;
            for (int i = 0; i < position - 1 && buf->next != nullptr; i++) {
                buf = buf->next;
            }
            newNode->next = buf->next;
            newNode->prev = buf;
            if (buf->next != nullptr) {
                buf->next->prev = newNode;
            }
            buf->next = newNode;
            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }

        count++;
    }

    void pop_back() {
        if (head == nullptr) return;
        if (tail == head) {
            delete head;
            tail = nullptr;
            head = nullptr;
        }
        else {
            Node<T>* buf = tail->prev;
            buf->next = nullptr;
            delete tail;
            tail = buf;
        }
        count--;
    }

    void pop_front() {
        if (head == nullptr) return;
        head = head->next;
        head->prev = nullptr;
        count--;
    }

    void remove(const T& data) {
        if (head == nullptr) {
            return;
        }

        if (head->data == data) {
            Node<T>* removeNode = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete removeNode;
            count--;
            return;
        }

        Node<T>* currNode = head->next;
        while (currNode != nullptr && currNode->data != data) {
            currNode = currNode->next;
        }

        if (currNode != nullptr) {
            if (currNode->prev != nullptr) {
                currNode->prev->next = currNode->next;
            }
            if (currNode->next != nullptr) {
                currNode->next->prev = currNode->prev;
            }
            if (currNode == tail) {
                tail = currNode->prev;
            }
            delete currNode;
            count--;
        }
    }

};

    int main()
    {
        setlocale(LC_ALL, "rus");
        List<int> list;
        list.show();
        list.push_front(2);
        list.push_front(4);
        list.push_front(6);
        list.push_front(12);
        list.push_front(234);
        list.push_front(98);
        list.show();
        std::cout << std::endl;
        list.push_back(9);
        list.show();
        cout << endl << list.front();
        cout << endl<<list.back();
        
        list.insert(10, 1);
        list.insert(12, 1);
        list.insert(17, 1);
        list.show();
        std::cout << std::endl;
        list.pop_back();
        list.show();
        std::cout << std::endl;
        list.pop_front();
        list.show();
        std::cout << std::endl;
        list.remove(4);
        list.show();
        std::cout << std::endl;
        list.remove(1);
        list.show();
        std::cout << std::endl;
        list.remove(2);
        list.show();
        std::cout << std::endl;
        list.remove(0);
        list.show();
        std::cout << std::endl;
        list.remove(0);
        list.show();
        std::cout << std::endl;
        list.remove(0);
        list.show();
        std::cout << std::endl;
        list.remove(0);
        list.show();
        std::cout << std::endl;
        list.remove(0);
        list.show();
        std::cout << std::endl;
    }
