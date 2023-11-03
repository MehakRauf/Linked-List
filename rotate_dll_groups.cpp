#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    int data;
    struct List *prev;
    struct List *next;
};
struct List *start = NULL;

void insert(int value)
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct List *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}
void rotate(int k)
{
    struct List *temp = start;
    //finding the end of the list
    while (temp->next != NULL)
    {
        temp=temp->next;
    }
    //making the list circular;
    temp->next=start;
    start->prev=temp;

    int count=1;
    //rotating the list
    while(count<=k){
        temp=temp->next;
        start=start->next;
        count++;
    }
    //making it non circular again
    temp->next=NULL;
    start->prev=NULL;
}
void print(List *start)
{
    struct List *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    insert(2);
    insert(14);
    insert(5);
    insert(9);
    insert(2);
    insert(6);
    insert(2);
    insert(9);
    print(start);
    rotate(2);
    print(start);
}