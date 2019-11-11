#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {

        
        DoublyLinkedListNode * toInsert = new DoublyLinkedListNode(data);

        if(head == nullptr)
        {
            head = toInsert;

        }
        if(data < head->data)
        {
            toInsert->next = head;
            toInsert->prev = nullptr;
            head->prev = toInsert;
            
            head = toInsert;
        }
        else{
        DoublyLinkedListNode * headRef = head;
        while(headRef->next != nullptr &&   headRef->next->data < toInsert->data)
            headRef=headRef->next;

            toInsert->prev = headRef;
            toInsert->next = headRef->next;
            
           if(headRef->next != nullptr)
            {
                headRef->next->prev = toInsert;
            }
            headRef->next = toInsert;
        
        
        }
        return head;

}

int main()