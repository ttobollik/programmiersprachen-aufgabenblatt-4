#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cstddef>
#include <iostream>
#include <initializer_list>
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
            return node == x.get_node_pointer(); //Wir vergleichen, ob die Node, auf den beide zeigen, die gleiche Adresse hat
        }
        bool operator!=(Self const& x) const {
            return node != x.get_node_pointer() ; //
        }

        Self next () const {
            if (node)
                return ListIterator(node->next);
            else
                return ListIterator(nullptr);
    }

        ListNode<T>* get_node_pointer() const{
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

        //Aufgabe 4.8
        List(List const& oldList) : 
            size_{0}, first_{nullptr}, last_{nullptr} {
                for(auto i = oldList.begin(); i != oldList.end(); ++i) {
                    push_back(*i); // weiß, dass es um diese Liste geht!
                }
            } 

        //Aufgabe 4.13
        List(List<T>&& rhs) :
            size_(rhs.size()), //warum runde Klammern?
            first_(rhs.first_),
            last_(rhs.last_) {
                rhs.size_= 0;
                rhs.first_ = nullptr;
                rhs.last_ = nullptr;
            }

        //Aufgabe 4.14
        List(std::initializer_list<T> const& init) : 
        size_{0},
        first_{nullptr},
        last_{nullptr}
        {
            for(auto i = init.begin(); i != init.end(); ++i) {
                    push_back(*i);
            }
        }

        //Aufgabe 4.12
        List<T>& operator=(List<T> xs) {
            clear();
            for(auto i = xs.begin(); i != xs.end(); ++i) {
                    push_back(*i);
            }
            return *this;
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
                delete first_;
                first_ = nullptr;
                last_ = first_;
                --size_;
            } else {
                auto temp = first_->next;
                delete first_;
                first_ = temp;
                first_->prev = nullptr;
                --size_;
            }
        }


        void pop_back() {
            if (empty() == true) {
                std::cout<< "The list is empty, no element to delete \n";
            } else if ( size() == 1) {
                delete first_;
                first_ = nullptr;
                last_ = first_;
                --size_;
            } else {
                auto temp = last_->prev;
                delete last_;
                temp->next = nullptr;
                last_ = temp;
                --size_; 
            }
        }

        T front() const{
            return first_->value;
        }

        T back() const{
            return last_->value;
        }

        //Aufgabe 4.4

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
        
        ListIterator<T> begin() const { //muss const sein, da ich es const in anderen Funktionen zurückgebe
           return ListIterator<T>(first_); //nicht const zurückgeben, da ich es ja ändern möchte!
        }

        ListIterator<T> end() const{
            return ListIterator<T>();
        }

        //Aufgabe 4.9 

        void insert(ListIterator<T> pos, T const& object) {
        if (pos.get_node_pointer()->prev != nullptr) {
            ListNode<T>* new_node = new ListNode<T>{object, pos.get_node_pointer()->prev, pos.get_node_pointer()};
            pos.get_node_pointer()->prev->next = new_node;
            pos.get_node_pointer()->prev = new_node;
        } else {
            push_front(object);
        }
         ++size_;
        }

        //Aufgabe 4.10
        void reverse() {
            ListNode<T>* current = new ListNode<T>;
            current = first_;
            ListNode<T>* temp = new ListNode<T>();
            while(current != nullptr) {
                temp = current->next;
                current->next = current->prev;
                current->prev = temp; //denn temp == current->next
                    if (temp == nullptr) {
                        last_ = first_;
                        first_ = current;
                    } 
                current = temp; //denn temp == current->next
            }
           
        }


        private:
        std::size_t size_;
        ListNode <T>* first_;
        ListNode <T>* last_;
        };

//Aufgabe 4.7
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

template <typename T>
List<T> reverse(List<T>const& xs) {
    List<T> new_list(xs);
    new_list.reverse();
    return new_list;
}

#endif // #define BUW_LIST_HPP


