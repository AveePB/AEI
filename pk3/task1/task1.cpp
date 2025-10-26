#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>

// Szablon klasy CustomQueue oparty na jednokierunkowej liście
template<typename T>
class CustomQueue {
private:
    struct Node {
        T value;       // przechowywana wartość
        Node* next;    // wskaźnik na następny element
        Node(const T& v) : value(v), next(nullptr) {}
        Node(T&& v) : value(std::move(v)), next(nullptr) {}
    };

    Node* head;        // początek kolejki
    Node* tail;        // koniec kolejki
    std::size_t count; // liczba elementów

    // Usuwa wszystkie elementy z pamięci
    void destroy_all() noexcept {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur->next;
            delete cur;
            cur = tmp;
        }
        head = tail = nullptr;
        count = 0;
    }

public:
    // 1) Konstruktor domyślny
    CustomQueue() noexcept : head(nullptr), tail(nullptr), count(0) {}

    // 2) Konstruktor kopiujący (głębokie kopiowanie)
    CustomQueue(const CustomQueue& other) : head(nullptr), tail(nullptr), count(0) {
        Node* cur = other.head;
        while (cur) {
            push_back(cur->value);
            cur = cur->next;
        }
    }

    // 3) Konstruktor przenoszący (bez dodatkowej alokacji)
    CustomQueue(CustomQueue&& other) noexcept
        : head(other.head), tail(other.tail), count(other.count)
    {
        other.head = other.tail = nullptr;
        other.count = 0;
    }

    // 4) Destruktor
    ~CustomQueue() {
        destroy_all();
    }

    // Wymiana zawartości dwóch kolejek
    void swap(CustomQueue& other) noexcept {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(count, other.count);
    }

    // 5) Operator przypisania kopiujący (copy-and-swap)
    CustomQueue& operator=(const CustomQueue& rhs) {
        if (this == &rhs) return *this;
        CustomQueue tmp(rhs);
        swap(tmp);
        return *this;
    }

    // 6) Operator przeniesienia
    CustomQueue& operator=(CustomQueue&& rhs) noexcept {
        if (this == &rhs) return *this;
        destroy_all();
        head = rhs.head;
        tail = rhs.tail;
        count = rhs.count;
        rhs.head = rhs.tail = nullptr;
        rhs.count = 0;
        return *this;
    }

    // Dodaje nowy element na końcu kolejki
    void push_back(const T& value) {
        Node* node = new Node(value);
        if (!tail) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        ++count;
    }

    // Zwraca pierwszy element w kolejce
    T& front() {
        if (!head) throw std::runtime_error("front() na pustej kolejce");
        return head->value;
    }
    const T& front() const {
        if (!head) throw std::runtime_error("front() na pustej kolejce");
        return head->value;
    }

    // Usuwa pierwszy element z kolejki
    void pop() {
        if (!head) return;
        Node* old = head;
        head = head->next;
        delete old;
        --count;
        if (!head) tail = nullptr;
    }

    // Czyści całą kolejkę
    void clear() noexcept {
        destroy_all();
    }

    // Zwraca informację o stanie kolejki
    bool empty() const noexcept { return head == nullptr; }
    std::size_t size() const noexcept { return count; }
};

void testInt() {
    std::cout << "=== Test: int ===\n";
    CustomQueue<int> qi;
    qi.push_back(1);
    qi.push_back(2);
    qi.push_back(3);
    std::cout << "pierwszy element: " << qi.front() << " | rozmiar: " << qi.size() << "\n";
    qi.pop();
    std::cout << "po pop(), pierwszy: " << qi.front() << " | rozmiar: " << qi.size() << "\n";

    CustomQueue<int> qi_copy = qi;
    std::cout << "kopiowana kolejka - pierwszy: " << qi_copy.front() << " | rozmiar: " << qi_copy.size() << "\n";
}

void testDouble() {
    std::cout << "\n=== Test: double ===\n";
    CustomQueue<double> qd;
    qd.push_back(3.14);
    qd.push_back(2.718);
    std::cout << "pierwszy element: " << qd.front() << " | rozmiar: " << qd.size() << "\n";

    CustomQueue<double> qd_moved = std::move(qd);
    std::cout << "po przeniesieniu - pierwszy: " << qd_moved.front() << " | rozmiar: " << qd_moved.size() << "\n";
    std::cout << "oryginał po przeniesieniu pusty: " << std::boolalpha << qd.empty() << "\n";
}

void testString() {
    std::cout << "\n=== Test: std::string ===\n";
    CustomQueue<std::string> qs;
    qs.push_back(std::string("Ala"));
    qs.push_back("ma");
    qs.push_back("kota");
    std::cout << "pierwszy element: " << qs.front() << " | rozmiar: " << qs.size() << "\n";
    qs.pop();
    std::cout << "po pop(), pierwszy: " << qs.front() << " | rozmiar: " << qs.size() << "\n";

    qs.clear();
    std::cout << "po clear(), czy pusta: " << std::boolalpha << qs.empty() << "\n";
}

// === Program testowy ===
int main() {
    testInt();
    testDouble();
    testString();
    return 0;
}
