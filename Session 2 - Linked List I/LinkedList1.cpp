#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Carrick 100 -> Livia 90 -> Valencia 86
*/

struct Node
{
    char name[255];
    int score;
    Node *next; // Menunjuk ke node selanjutnya
} *head, *tail; // Global Variable Head and Tail;
// Head : First Node
// Tail : Last Node

Node *createNode(const char *name, int score)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score; 
    newNode->next = NULL; // NULL so that no garbage value
    return newNode;
}

void pushHead(const char *name, int score)
{
    Node *temp = createNode(name,score); // Buat dlu nodenya

    if (!head)// if no head, 
    {
        head = tail = temp; // Then node will become head and tail
    }
    else // if there is existing head
    {
        temp->next = head; // node->next = old head
        head = temp; // Node will become new head
    }    
}

void pushTail(const char *name, int score)
{
    Node *temp = createNode(name,score); // Buat dlu nodenya

    if (!head)// if no head, 
    {
        head = tail = temp; // Then node will become head and tail
    }
    else // if there is existing head
    {
        tail->next = temp; // node->next = old tail
        tail = temp; // Node will become new tail
    }    
}

void popHead()
{
    if (!head) // If no Head
    {
        return; // return immediately
    }
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        Node *temp = head->next;
        head->next = NULL;
        free(head);
        head = temp;
    } 
}

void popTail()
{
    if (!head) // If no Head
    {
        return; // return immediately
    }
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        free(head);
        tail = temp;
    } 
}

void printList()
{
    // base case
    if (!head)
    {
        return;
    }

    Node *curr = head;  

    // for (Node *curr = head; curr != NULL; curr = curr->next)
    // {

    // }

    while (curr)
    {
        if (curr == head)
        {
            printf(" (head) ");
        } else if(curr == tail)
        {
            printf(" (tail) ");
        }
        printf("%s %d -> ", curr->name, curr->score);
        curr = curr->next;
    }
    puts("NULL");
}

int main()
{
    pushHead("Carrick", 100);
    pushTail("Bryan", 85);
    pushTail("Valencia", 95);
    printList();

    return 0;
}