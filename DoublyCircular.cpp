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

class Doubly_CLL
{
private:
    PNODE Head;
    PNODE Tail;
    int iCount;

public:
    Doubly_CLL();
    void InsertFirst(int);
    void InsertLast(int);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int, int);
    void DeleteAtPos(int);
    void Dispaly();
    int Count();
};

Doubly_CLL::Doubly_CLL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}
void Doubly_CLL::InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;
}
void Doubly_CLL::InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;
}
void Doubly_CLL::DeleteFirst()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        free(Tail->next);
    }
    Tail->next = Head;
    Head->prev = Tail;
}
void Doubly_CLL::DeleteLast()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Tail->next;
    }
    Head->prev = Tail;
    Tail->next = Head;
}
void Doubly_CLL::InsertAtPos(int iNo, int pos)
{
    int iSize = 0;
    iSize = Count();
    if ((pos < 1) || (pos > iSize + 1))
    {
        return;
    }
    else if (pos == 1)
    {
        InsertFirst(iNo);
    }
    else if (pos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        int iCnt = 0;
        PNODE temp = Head;

        PNODE newn = NULL;
        newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next->prev = newn;
        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;
    }
}
void Doubly_CLL::DeleteAtPos(int pos)
{
    int iSize = 0;
    iSize = Count();
    if ((pos < 1) || (pos > iSize))
    {
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
        int iCnt = 0;
        PNODE temp = Head;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}
void Doubly_CLL::Dispaly()
{
    PNODE temp = Head;
    cout << "Link list element is:" << endl;
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != Head);
    cout << endl;
}
int Doubly_CLL::Count()
{
    int iCnt = 0;
    PNODE temp = Head;
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
    Doubly_CLL obj;
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Dispaly();

    obj.InsertLast(121);
    obj.Dispaly();

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Dispaly();

    obj.InsertAtPos(75, 3);
    obj.Dispaly();
    iRet = obj.Count();
    cout << "Number of node :" << iRet << endl;

    obj.DeleteAtPos(3);
    obj.Dispaly();
    iRet = obj.Count();
    cout << "Number of node :" << iRet << endl;

    return 0;
}