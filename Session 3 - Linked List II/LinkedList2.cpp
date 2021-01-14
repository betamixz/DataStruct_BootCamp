#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int value;  
    Node *prev, *next;
} *head, *tail;

Node *createNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void pushHead(Node *index, int value)
{
    Node *temp = createNode(value);

    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        head->prev = temp;
        temp->next = head;  
        head = temp;
    }
    
}

void pushTail (Node *index, int value)
{
    Node *temp = createNode(value);

    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void popHead ()
{
    if(!head)
    {
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *candidateHead = head->next;
        head->next = candidateHead->prev = NULL;
        free(head);
        head = candidateHead;   
    }
    
}

void popTail ()
{
    if(!head)
    {
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *candidateTail = tail->next;
        candidateTail->next = candidateTail->prev = NULL;
        free(tail);
        tail = candidateHead;   
    }
    
}

void pushMid (int value)
{
    if (!head) // Empty Linked List
    {
        Node *temp = createNode(value);
        head = tail = temp;
    }
    else if(value < head->value) // Insert at front
    {
        pushHead (value);
    }
    else if (value > tail->value) // Insert at back
    {
        pushTail (value);
    }
    else // Insert in mid
    {
        // 9 (head) >< 10 >< 13 >< 15 (tail)>
        Node *curr = head;
        Node *temp = head;

        while (curr->value < value)
        {
            curr = curr->next;
            temp->prev = curr->prev;
            temp->next = curr;
            curr->prev = temp;
            temp->prev->next = temp;
        }
    }
    
}

void popMid()
{
    if(!head)
    {
        return;
    }
    else if (value == head->value)
    {
        popHead();
    }
    else if (value == tail->value)
    {
        popTail();
    }
    else
    {
        Node *curr = head;

        while (curr->value != value)
        {
            curr = curr->next;
        }
        

        while (curr && curr->value != value)  
        {
            curr = curr->next;
        }         

        if (!curr)
        {
            puts("There is no target in the linked list.");
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = curr->next = NULL;
        free(curr);
        curr = NULL;
    }
}

int main()
{



    return 0;
}