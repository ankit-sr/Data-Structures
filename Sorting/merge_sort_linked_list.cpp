#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = tail = NULL;
    }

    void insertNode(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

Node *midNode(Node *head, Node *tail)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

LinkedList merge(LinkedList first, LinkedList second)
{
    LinkedList sortedList;
    Node *head1 = first.head;
    Node *head2 = second.head;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            sortedList.insertNode(head1->data);
            head1 = head1->next;
        }
        else
        {
            sortedList.insertNode(head2->data);
            head2 = head2->next;
        }
    }

    while (head1 != NULL)
    {
        sortedList.insertNode(head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        sortedList.insertNode(head2->data);
        head2 = head2->next;
    }

    return sortedList;
}

LinkedList mergeSort(Node *head, Node *tail)
{
    if (head == tail)
    {
        LinkedList currentList;
        currentList.insertNode(head->data);
        currentList.printList();
        return currentList;
    }
    else
    {
        Node *mid = midNode(head, tail);
        LinkedList firstList = mergeSort(head, mid);
        LinkedList secondList = mergeSort(mid->next, tail);
        firstList.printList();
        secondList.printList();

        LinkedList sortedList = merge(firstList, secondList);
        sortedList.printList();
        return sortedList;
    }
}

int main()
{
    LinkedList list, sortedList;

    list.insertNode(10);
    list.insertNode(8);
    list.insertNode(90);
    list.insertNode(45);
    list.insertNode(5);

    cout << "Current List is : ";
    list.printList();

    sortedList = mergeSort(list.head, list.tail);
    cout << "sorted list is : ";
    sortedList.printList();

    return 0;
}