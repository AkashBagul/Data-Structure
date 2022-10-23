#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Doubly_LLL
{
private:
    PNODE Head;

public: // Declartion
    Doubly_LLL();
    void InsertFirst(int no);
    void InsertLast(int no);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int no, int pos);
    void DeleteAtPos(int pos);
    void Display();
    int Count();
};

Doubly_LLL::Doubly_LLL() // default constructor
{
    Head = NULL;
}

void Doubly_LLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head != NULL)
    {
        Head->prev = newn;
        newn->next = Head;
    }
    Head = newn;
}

void Doubly_LLL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        PNODE temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newn->prev = temp;
        temp->next = newn;
    }
}

void Doubly_LLL::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }

    else if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        Head = Head->next; //*
        delete Head->prev; //*
        Head->prev = NULL; //*
    }
}

void Doubly_LLL::DeleteLast()
{
    PNODE temp = Head;

    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

void Doubly_LLL::InsertAtPos(int no, int pos)
{
    int iSize = 0;
    iSize = Count();

    if ((pos < 1) || (pos > iSize + 1))
    {
        cout << "Invalid Position" << endl;
        return;
    }

    else if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
        int iCnt = 0;
        PNODE newn = NULL;
        PNODE temp = Head;
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL; //*

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn; //*
        temp->next = newn;
        newn->prev = temp; //*
    }
}

void Doubly_LLL::DeleteAtPos(int pos)
{
    int iSize = 0;
    iSize = Count();

    if ((pos < 1) || (pos > iSize))
    {
        cout << "Invalid Position" << endl;
        return;
    }

    else if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iSize)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = Head;
        int iCnt = 0;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

void Doubly_LLL::Display()
{
    PNODE temp = Head;
    cout << "Data from linked list is :" << endl;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int Doubly_LLL::Count()
{
    PNODE temp = Head;
    int iCnt = 0;

    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

int main()
{
    int iRet = 0;
    Doubly_LLL obj;

    obj.InsertFirst(111);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(121);
    obj.Display();

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();

    obj.InsertAtPos(75, 3);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of node is :" << iRet << endl;

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of node is :" << iRet << endl;

    return 0;
}