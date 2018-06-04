#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cstddef>
// List.hpp

template <typename T> class List;
template <typename T> struct ListNode
    {
        T value = T();
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
    };

template <typename T> class ListIterator
    {
        public:
        // Standartkonstruktor
        // copy-Konstruktor
        private:
        ListNode <T>* node;
    };

template <typename T>
class ListConstIterator
    {
    public:
    // not implemented yet
    // do not forget about the initialiser lists!
    private:
    ListNode <T>* node;
    };


template <typename T> class List
    {
        public:

        using value_type = T;
        using pointer = T*;
        using const_ponter  = T const *;
        using reference =  T&;
        using const_reference = T const&;
        using iterator = ListIterator <T>;
        using const_iterator = ListConstIterator <T>;

        // Default Constructor
        List() :
            size_{0}, first{nullptr}, last_{nullptr} {}
        
        bool empty() const {
            return size_ == 0;
        }
        
        std::size_t size() const {
            return size_;
        }

        void push_front(T const& wert) {
            ListNode <T>* new_node;
            new_node.value = wert;
            if (empty() == true) {
                first = last_ = wert;
            } else {
                first.prev = new_node;
                new_node.next = first;
                first = new_node;
                first.prev = nullptr;
            }
        }

        private:
        std::size_t size_;
        ListNode <T>* first;
        ListNode <T>* last_;
        };

#endif // #define BUW_LIST_HPP


