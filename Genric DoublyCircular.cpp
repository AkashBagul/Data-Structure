#include <iostream>
using namespace std;

template <class T>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

template <class T>
class Doubly_CLL
{
private:
    struct node<T> *Head;
    struct node<T> *Tail;
    int iCount;

public:
    Doubly_CLL();
    void InsertFirst(T);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T, int);
    void DeleteAtPos(int);
    void Dispaly();
    int Count();
};

template <class T>
Doubly_CLL<T>::Doubly_CLL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}

template <class T>
void Doubly_CLL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) || (Tail == NULL))
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

template <class T>
void Doubly_CLL<T>::InsertLast(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) || (Tail == NULL))
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

template <class T>
void Doubly_CLL<T>::DeleteFirst()
{
    if ((Head == NULL) || (Tail == NULL))
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

template <class T>
void Doubly_CLL<T>::DeleteLast()
{
    if ((Head == NULL) || (Tail == NULL))
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

template <class T>
void Doubly_CLL<T>::InsertAtPos(T iNo, int pos)
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
        struct node<T> *temp = Head;
        struct node<T> *newn = NULL;

        newn = new struct node<T>;

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

template <class T>
void Doubly_CLL<T>::DeleteAtPos(int pos)
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
        struct node<T> *temp = Head;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
}

template <class T>
void Doubly_CLL<T>::Dispaly()
{
    struct node<T> *temp = Head;

    cout << "Link list element is:" << endl;
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != Head);
    cout << endl;
}

template <class T>
int Doubly_CLL<T>::Count()
{
    int iCnt = 0;
    struct node<T> *temp = Head;
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
    Doubly_CLL<int> obj;
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

    obj.DeleteAtPos(2);
    obj.Dispaly();
    iRet = obj.Count();
    cout << "Number of node :" << iRet << endl;

    int iiRet = 0;
    Doubly_CLL<double> obj1;
    obj1.InsertFirst(10.11);
    obj1.InsertFirst(51.15);
    obj1.InsertFirst(21.23);
    obj1.InsertFirst(11.54);
    obj1.Dispaly();

    obj1.InsertLast(121.23);
    obj1.Dispaly();

    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.Dispaly();

    obj1.InsertAtPos(75.69, 3);
    obj1.Dispaly();
    iiRet = obj.Count();
    cout << "Number of node :" << iiRet << endl;

    obj1.DeleteAtPos(3);
    obj1.Dispaly();
    iiRet = obj1.Count();
    cout << "Number of node :" << iiRet << endl;

    return 0;
}