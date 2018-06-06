#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cstddef>
#include <iostream>
// List.hpp

template <typename T> class List;
template <typename T> struct ListNode
    {
        T value = T();
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
    };

template <typename T>
class ListIterator {
    public:
        using Self = ListIterator <T>;
        using value_type =T;
        using pointer = T*;
        using reference = T&;
        using difference_type = ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;

        ListIterator() : node{nullptr} {} 
        ListIterator(ListNode<T>* n) : node{n} {}  
        reference operator*() const {
            return node->value; //
        } 
        pointer operator->() const {
            return *this; //FRAGE. *node
        } 
        Self& operator++() {
            node = node->next;
            return *this; //FRAGE: Referenz? Pointer?
        } 

        Self operator++(int) {
            Self temp = *this;
            ++(*this);
            return temp;
        } // not implemented yet
        bool operator==(Self const& x) const {
            return node == x.get_node(); //Wir vergleichen, ob die Node, auf den beide zeigen, die gleiche Adresse hat
        }
        bool operator!=(Self const& x) const {
            return node != x.get_node() ; //
        }

        Self next () const {
            if (node)
                return ListIterator(node->next);
            else
                return ListIterator(nullptr);
    }

        ListNode<T>* get_node() const{
            return node;
        }

    private:
    // The Node the iterator is pointing to 
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

        // Aufgabe 4.2
        List() :
            size_{0}, first_{nullptr}, last_{nullptr} {}
        ~List() {
            clear();
        }
        
        bool empty() const {
            return size_ == 0;
        }
        
        std::size_t size() const {
            return size_;
        }

        // Aufgabe 4.3
        void push_front(T const& wert) {
            ListNode<T>* node = new ListNode<T>{wert, nullptr, nullptr}; //wenn wir keinen Konstruktor initialisieren, dann gibt es meist einen        
            if (empty() == true) {
                first_ = node;
                last_ = node;
            } else {
                node->next = first_;
                first_->prev = node;
                first_ = node;
            }
            ++size_;
        }

        void push_back(T const& wert) {
            ListNode<T>* node = new ListNode<T>{wert, nullptr, nullptr};
            if (empty() == true) {
                first_ = node;
                last_ = node;
            } else {
                node->prev = last_;
                last_->next = node;
                last_ = node;
            }
            ++size_;
        }

        void pop_front() {
            if (empty() == true) {
                std::cout<< "The list is empty, no element to delete \n";
            } else if ( size() == 1) {
                first_ = nullptr;
                last_ = first_;
                --size_;
            } else {
                first_ = first_->next;
                first_->prev = nullptr;
                --size_; //DELETE einfuegen, Adrian fragen
            }
        }


        void pop_back() {
            if (empty() == true) {
                std::cout<< "The list is empty, no element to delete \n";
            } else if ( size() == 1) {
                first_ = nullptr;
                last_ = first_;
                --size_;
            } else {
                last_ = last_->prev;
                last_->next = nullptr;
                --size_; //DELETE einfuegen, Adrian fragen
            }
        }

        T front() const{
            return first_->value;
        }

        T back() const{
            return last_->value;
        }

        //Aufgabe 3.4

        void clear() {
            if(empty()==true) {
                std::cout<< "The list is already empty \n";
            } else {
                while (first_ != nullptr && last_ != nullptr) {
                    pop_back();
                }
            }
        } //FRAGE: Destruktor mit clear???

        //Aufgabe 4.6
        
        ListIterator<T> begin() {
           return ListIterator<T>(first_);
        }

        ListIterator<T> end() {
            return ListIterator<T>();
        }

        private:
        std::size_t size_;
        ListNode <T>* first_;
        ListNode <T>* last_;
        };

template <typename T>
bool operator==(List<T> const& xs, List<T> const& ys) {
    //bool result = true;
    ListIterator<T> start_X = xs.begin();
    ListIterator<T> start_Y = ys.begin();
    if (xs.size() != ys.size()) {
        return false;
    } else {
        for (int i = 0; i < xs.size(); ++i) {
            if (*start_X != *start_Y) {
                return false;
            } else {
                ++start_X;
                ++start_Y;
            }    
        }
        return true;
    }
    
}

template <typename T>
bool operator!=(List<T> const& xs, List<T> const& ys) {
 return !(xs == ys);
}


#endif // #define BUW_LIST_HPP


