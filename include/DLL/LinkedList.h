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

                ListNode() = default;
                ListNode(const T& element) : data(element){}
            };
        public:
            std::unique_ptr<ListNode> head;
            ListNode* tail = nullptr;

            LinkedList(std::initializer_list<T> elements){
                for(auto element : elements){
                    this->append(element);
                }
            }
            LinkedList() = default;
            ~LinkedList() noexcept { //Custom iterative destructor to minimize the stack space during object destruction
                while(head) head = std::move(head->next);
            }
            //Non-copyable.
            LinkedList(const LinkedList&) = delete; //Delete copy constructor.
            LinkedList& operator=(const LinkedList& other) = delete; //Delete copy assignment operator.

            LinkedList(LinkedList&& other) = default; //Move constructor
            LinkedList& operator=(LinkedList&& other) = default; //Move assignment operator

            void fill(std::initializer_list<T> elements){ // appends new elements at the end of the list.
                for(auto element : elements){
                    append(element);
                }
            }

            bool empty(){
                if (head){ //If head != nullptr then
                    return false; //list is not empty
                }else{
                    return true;
                }
            }

            int length(){
                ListNode* curr = nullptr;
                int count = 0;
                if (empty()){
                    return count; //length = 0;
                }
               //If list has one or more elements
                curr = head.get();
                while(curr){
                    ++count;
                    curr = curr -> next.get(); //Traverse the next element
                }
                return count; //return the length
            }

            int search(const T& element){
                ListNode* curr = nullptr;
                if (empty()){
                    return -1;
                }
               //If list has one or more elements
                curr = head.get();
                while(curr){
                    if(curr -> data == element){
                        return 1; //Element found in list
                    }
                    curr = curr -> next.get(); //Traverse the next element
                }
                return 0; //Element not found in list
            }

            void append(const T& element){
                ListNode* curr = nullptr;
                if (empty()){
                    head = std::make_unique<ListNode>(element);
                }
                else if(!head -> next.get()){ //If list has one element.
                     head -> next = std::make_unique<ListNode>(element);
                     curr = head -> next.get(); //Sets raw pointer to the first element.
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

            int remove(const T& element){
                ListNode* curr = nullptr;
                if (empty()){
                    return -1; //Error: Can't remove from empty list.
                }
                //List has one or more elements.
                curr = head.get();
                while(curr){
                    if(curr -> data == element){ //Found element.
                        if(!curr -> prev){ //it's head
                            head = std::move(curr -> next); //Head now points to the next element.
                            if (head) {
                                head->prev = nullptr;
                            }
                        //New head's previous element points to nothing, making it a true head element.
                        }
                        else if(!curr -> next.get()){ //it's tail.
                            tail = curr -> prev; //Reference the previous element.
                            tail -> next.reset(); //Destroy the old tail element.
                            if(head.get() == tail){
                                tail = nullptr; //tail and head should not be the same.
                            } //List contains one element.
                        }
                        else{//it's intermediate.
                            //The next node should point to the previous one
                            curr -> next -> prev = curr -> prev;
                            curr -> prev -> next = std::move(curr -> next);
                            //The prev node now points to the next one of current.
                        }
                        return 1; //Element found in list.
                    }
                    curr = curr -> next.get(); //Traverse the next element.
                }
                return 0; //Element not found in list.
            }
            
            void print() {
                ListNode* curr = head.get(); //Start from the start of the list.
                std::cout << "[ ";
                while(curr){
                    std::cout << curr -> data << " ";
                    curr = curr -> next.get();
                }
                std::cout << "]" << std::endl;
            }

            void reverse_print(){
                ListNode* curr = tail; //Start from the end of the list.
                std::cout << "[ ";
                while(curr){
                    std::cout << curr -> data << " ";
                    curr = curr -> prev;
                }
                std::cout << "]" << std::endl;
            }
    };
}

#endif
