#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>

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

            LinkedList(){}
            ~LinkedList(){}

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
                ListNode* curr = head.get();
                std::cout << "[ ";
                while (curr != nullptr) {
                    std::cout << curr->data << " ";
                    curr = curr->next.get();
                }
                std::cout << "]" << std::endl;
            }
            
    };
}

#endif
