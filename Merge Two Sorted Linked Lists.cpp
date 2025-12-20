Problem Link: https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_8230729?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{

    if (first == NULL) return second;
    if (second == NULL) return first;

    Node<int>* dummyHead = new Node<int>(-1);
    Node<int>* temp = dummyHead;

    while (first && second) {
        if (first->data < second->data) {
            temp->next = first;
            temp = first;
            first = first->next;
        }
        else {
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }

    if (first ){
        temp->next = first;
    }

    if (second) {
        temp->next = second;
    } 

    dummyHead = dummyHead->next;
    return dummyHead;

}
