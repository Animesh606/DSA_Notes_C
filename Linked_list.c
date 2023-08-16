#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *ptr;
} node;

void traversal(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->ptr;
    }
    printf("\n");
}

void insertNode(node **head, int data, int position)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (position == 0)
    {
        newNode->ptr = *head;
        *head = newNode;
    }
    else
    {
        node *p = *head;
        int i = 0;
        while (i != position - 1)
        {
            p = p->ptr;
            i++;
        }
        newNode->ptr = p->ptr;
        p->ptr = newNode;
    }
}

void deleteNode(node **head, int position)
{
    if (position == 0)
    {
        node *delEliment = *head;
        *head = (*head)->ptr;
        free(delEliment);
    }
    else
    {
        node *p = *head;
        int i = 0;
        while (i != position - 1)
        {
            p = p->ptr;
            i++;
        }
        node *delEliment = p->ptr;
        p->ptr = (p->ptr)->ptr;
        free(delEliment);
    }
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));

    head->data = 12;
    head->ptr = second;

    second->data = 23;
    second->ptr = third;

    third->data = 43;
    third->ptr = NULL;

    traversal(head);

    insertNode(&head, 45, 0);
    insertNode(&head, 12, 2);
    insertNode(&head, 40, 5);

    traversal(head);

    deleteNode(&head, 0);
    deleteNode(&head, 1);
    deleteNode(&head, 3);

    traversal(head);

    return 0;
}