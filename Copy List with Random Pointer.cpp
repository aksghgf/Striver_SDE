Problem Link: https://www.codingninjas.com/codestudio/problems/copy-list-with-random-pointer_8230734?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
void insertAtTail(LinkedListNode<int>* &head, LinkedListNode<int>* &tail, int data) {
    LinkedListNode<int>* newNode = new LinkedListNode<int>(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}


LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{

    //cpoying linked list
    LinkedListNode<int>* cloneHead = NULL;
    LinkedListNode<int>* cloneTail = NULL;

    LinkedListNode<int>* temp = head;

    while (temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // Map Approach
    // map<LinkedListNode<int>*, LinkedListNode<int>*> originalToClone;
    // LinkedListNode<int>* originalNode = head;
    // LinkedListNode<int>* cloneNode = cloneHead;

    // while (originalNode != NULL) {
    //     originalToClone[originalNode] = cloneNode;
    //     originalNode = originalNode->next;
    //     cloneNode = cloneNode->next;
    // }


    // cloneNode = cloneHead;
    // originalNode = head;
    // while (cloneNode != NULL) {
    //     cloneNode->random = originalToClone[originalNode->random];
    //     cloneNode = cloneNode->next;
    //     originalNode = originalNode->next;
    // }

    // return cloneHead;

    //changing Pointer approach
    LinkedListNode<int>* originalNode = head;
    LinkedListNode<int>* cloneNode = cloneHead; 
    while (originalNode != NULL) {
        LinkedListNode<int>* nxt = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = nxt;
        nxt = cloneNode->next;
        if (originalNode != NULL)
            cloneNode->next = originalNode->next;
        cloneNode = nxt;
    }

    temp = head;

    while (temp != NULL) {
        if (temp->next != NULL)
        temp->next->random = temp->random;
        temp = temp->next->next;
    }

    // reverting changes
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL) {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        if (originalNode != NULL)
        cloneNode->next = originalNode->next;
        cloneNode = cloneNode->next;

    }

    return cloneHead;


    


}
