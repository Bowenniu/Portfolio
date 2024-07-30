// Write a C function to detect and remove duplicates from an unsorted linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

LNode* createNode(int data) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    if (newNode == NULL) {
        printf("Error! Unable to create a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteDuplicates(LNode *L) { // needs two pointers, p and q and check the elements step by step. 
    if (L == NULL || L->next == NULL) // p can not be NULL, and q which follows can not be NULL, either.
        return;

    LNode *p = L->next, *q, *prev;
    while (p != NULL) {
        prev = p;
        q = p->next;
        while (q != NULL) {
            if (p->data == q->data) { // when p == q, that means there is an element duplicated, so remove q instead of p, since we have to make sure
                                      // p is not NULL.
                prev->next = q->next;
                free(q); // release q since it has same element with p.
                q = prev->next; 
            } else {
                prev = q; 
                q = q->next;
            }
        }
        p = p->next;
    }
}

LNode* LinkedList(int arr[], int n) { // simply create a linked list...
    LNode* head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        LNode *newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

void printLinkedList(LNode* head) { //print the original unsorted, element duplicated linked list
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() { //test function with an arr randomly created.
    int arr[] = {4, 1, 1, 5, 3, 6, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    LNode *head = LinkedList(arr, n);
    printf("Original Linked List is: ");

    printLinkedList(head);
    deleteDuplicates(head);
    
    printf("Removing duplicated elements from Linked List is: ");
    printLinkedList(head);

    //finally, release the memory..
    LNode* current = head;
    while (current!= NULL) {
        LNode* temp = current;
        current = current -> next;
        free(temp);
    }

    return 0;
}
