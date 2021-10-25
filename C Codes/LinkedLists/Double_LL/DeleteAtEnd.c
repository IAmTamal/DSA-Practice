#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    return temp;
}

// here we are going all the way to the last node
// then we are making the second last node as q
// making q the last node and finally freeing t
node *Delete(node *head)
{
    node *t = head;
    if (head == NULL)
    {
        printf("Invalid");
    }
    else
    {
        while (t->next != NULL)
        {
            t = t->next;
        }

        node *q = t->prev;
        q->next = NULL;
        free(t);
    }
    return head;
}

void traversal(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    node *head = create();
    node *second = create();
    node *third = create();
    node *fourth = create();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = NULL;

    head = Delete(head);

    traversal(head);
}