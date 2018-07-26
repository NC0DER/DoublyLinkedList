#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace DLL {
    template <typename T> class LinkedList{
        private:
            struct ListNode{
                std::unique_ptr<ListNode> next; //2 uniq_ptr can't point to one another.
                ListNode* prev = nullptr; //weakptr needs to be cast back to a shared_ptr to check its state.
                T data{}; //Initialize empty;

                ~ListNode(){
                    prev = nullptr; //next ptr will cleanup by its own.
                }
            };
        public:
            std::unique_ptr<ListNode> head;
            std::unique_ptr<ListNode> tail;

            LinkedList(){}
            ~LinkedList(){}

            void append(const T& element){
                if(head -> next.get() == nullptr){ //If list is empty.
                    ListNode* last = head.get(); //Sets raw pointer to the first element.
                }
                else{
                    ListNode* last = tail.get(); //Sets raw pointer to the last element.
                }
                last -> next = std::make_unique<ListNode>(element);
                last -> data = element;
                last -> next.get() -> prev = last;
            }
            void remove(const T& element);
            void print();
    };
}

#endif
