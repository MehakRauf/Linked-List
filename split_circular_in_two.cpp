#include <iostream>
using namespace std;

struct List
{
    int data;
    struct List *next;
};

struct List *start = NULL;

void insert(int value)
{
    struct List *temp = new List();
    temp->data = value;
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
        start->next = start;
    }
    else
    {
        struct List *curr = start;
        while (curr->next != start)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = start;
    }
}

void *split(struct List **head1, struct List **head2)
{
    struct List *slow = start;
    struct List *fast = start;
    while (fast->next->next != start && fast->next != start)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // if even
    if (fast->next->next == start)
    {
        fast = fast->next;
    }
    *head1 = start;
    if (start->next != start)
    {
        *head2 = slow->next;
    }
    // make second half circular
    fast->next = slow->next;
    // make first half circular
    slow->next = start;
    
    
}


void print(struct List *start)
{
    if (start == NULL)
    {
        return;
    }

    struct List *temp = start;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);

    cout << endl;
}

int main()
{
    insert(1);
    insert(0);
    insert(12);
    
    

    print(start);
    List *head1, *head2;
    split(&head1, &head2);
    print(head1);
    print(head2);

    return 0;
}