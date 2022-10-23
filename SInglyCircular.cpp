#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Singly_CLL
{
private:
    PNODE Head; // Charteristic
    PNODE Tail;

public: // Declartion
    Singly_CLL();
    void InsertFirst(int no);
    void InsertLast(int no);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int no, int pos);
    void DeleteAtPos(int pos);
    void Display();
    int Count();
};

Singly_CLL::Singly_CLL() // default constructor
{
    Head = NULL;
    Tail = NULL;
}

void Singly_CLL::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else // If LL constains atleast one node
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
}

void Singly_CLL::InsertLast(int no)
{

    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else // If LL constains atleast one node
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
}

void Singly_CLL::DeleteFirst()
{
    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return;
    }
    else if (Head == Tail) // If LL contains 1 node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }

    else // If LL contains more than 1 node
    {
        Head = Head->next;
        delete Tail->next;
    }
    Tail->next = Head;
}

void Singly_CLL::DeleteLast()
{
    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return;
    }
    else if (Head == Tail) // If LL contains 1 node
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }

    else // If LL contains more than 1 node
    {
        PNODE temp = Head;
        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
    }
    Tail->next = Head;
}

void Singly_CLL::InsertAtPos(int no, int pos)
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

void Singly_CLL::DeleteAtPos(int pos)
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

void Singly_CLL::Display()
{
    PNODE temp = Head;
    if (Head == NULL && Tail == NULL)
    {
        return;
    }

    cout << "Elements from linked list are :" << endl;

    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != Head);

    cout << endl;
}

int Singly_CLL::Count()
{
    PNODE temp = Head;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Head);
    return iCnt;
}

int main()
{
    int iRet = 0;
    Singly_CLL obj;

    obj.InsertFirst(111);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of node is :" << iRet << endl;

    obj.InsertLast(121);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of node is :" << iRet << endl;

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout << "Number of node is :" << iRet << endl;

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