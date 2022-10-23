#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Singly_LLL
{
private:
    PNODE Head; // Charteristic

public: // Declartion
    Singly_LLL();
    void InsertFirst(int no);
    void InsertLast(int no);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int no, int pos);
    void DeleteAtPos(int pos);
    void Display();
    int Count();
};

Singly_LLL::Singly_LLL() // default constructor
{
    Head = NULL;
}

void Singly_LLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if (Head != NULL)
    {
        newn->next = Head;
    }

    Head = newn;
}

void Singly_LLL::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Singly_LLL::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        PNODE temp = Head;
        Head = Head->next;
        delete temp;
    }
}

void Singly_LLL::DeleteLast()
{
    if (Head == NULL) // LL is empty
    {
        return;
    }
    else if (Head->next == NULL) // LL contains one node
    {
        delete Head;
        Head = NULL;
    }
    else // LL contains more than one node
    {
        PNODE temp = Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

void Singly_LLL::InsertAtPos(int no, int pos)
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
        PNODE temp = Head;

        PNODE newn = NULL;
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void Singly_LLL::DeleteAtPos(int pos)
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
        PNODE tempdelete = NULL;
        int iCnt = 0;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = tempdelete->next;

        delete tempdelete;
    }
}

void Singly_LLL::Display()
{
    PNODE temp = Head;

    cout << "Elements from linked list are :" << endl;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int Singly_LLL::Count()
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
    Singly_LLL obj;

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

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of node is :" << iRet << endl;

    return 0;
}