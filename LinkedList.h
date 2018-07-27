#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>
#include <initializer_list>

namespace DLL {
    template <typename T> class LinkedList{
        private:
            struct ListNode{
                std::unique_ptr<ListNode> next; //2 uniq_ptr can't point to one another.
                ListNode* prev = nullptr; //weakptr needs to be cast back to a shared_ptr to check its state.
                T data{}; //Initialize empty;

                ListNode(const T& element){
                    this->data = element;
                }
            };
        public:
            std::unique_ptr<ListNode> head;
            ListNode* tail = nullptr;

            LinkedList(std::initializer_list<T> elements){
                for(auto element : elements){
                    this->append(element);
                }
            }
            LinkedList(){}
            ~LinkedList(){}

            void fill(std::initializer_list<T> elements){ // appends new elements at the end of the list
                for(auto element : elements){
                    this->append(element);
                }
            }
            void append(const T& element){
                ListNode* curr = nullptr;
                if (head.get() == nullptr){ //If list is empty.
                    head = std::make_unique<ListNode>(element);
                }
                else if(head.get() -> next.get() == nullptr){ //If list has one element
                     head.get() -> next = std::make_unique<ListNode>(element);
                     curr = head.get() -> next.get(); //Sets raw pointer to the first element.
                     curr -> prev = head.get();
                     tail = curr;
                }
                else{
                    tail -> next = std::make_unique<ListNode>(element);
                    curr = tail -> next.get(); //Sets raw pointer to the last element.
                    curr -> prev = tail;
                    tail = curr;// The new last element is the tail.
                }
            }

            void remove(const T& element);
            
            void print() {
                ListNode* curr = head.get(); //Start from the start of the list.
                std::cout << "[ ";
                while (curr != nullptr) {
                    std::cout << curr -> data << " ";
                    curr = curr -> next.get();
                }
                std::cout << "]" << std::endl;
            }

            void reverse_print(){
                ListNode* curr = tail; //Start from the end of the list.
                std::cout << "[ ";
                while (curr != nullptr) {
                    std::cout << curr -> data << " ";
                    curr = curr -> prev;
                }
                std::cout << "]" << std::endl;
            }
    };
}

#endif
