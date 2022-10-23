#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Singly_CLL
{
private:
    struct node<T> *Head; // Charteristic
    struct node<T> *Tail;

public: // Declartion
    Singly_CLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no, int pos);
    void DeleteAtPos(int pos);
    void Display();
    int Count();
};

template <class T>
Singly_CLL<T>::Singly_CLL() // default constructor
{
    Head = NULL;
    Tail = NULL;
}

template <class T>
void Singly_CLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
}

template <class T>
void Singly_CLL<T>::InsertLast(T no)
{

    struct node<T> *newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
}

template <class T>
void Singly_CLL<T>::DeleteFirst()
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
        delete Tail->next;
    }
    Tail->next = Head;
}

template <class T>
void Singly_CLL<T>::DeleteLast()
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
        struct node<T> *temp = Head;
        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
    }
    Tail->next = Head;
}

template <class T>
void Singly_CLL<T>::InsertAtPos(T no, int pos)
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
        struct node<T> *newn = NULL;
        struct node<T> *temp = Head;

        newn = new struct node<T>;

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

template <class T>
void Singly_CLL<T>::DeleteAtPos(int pos)
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
        struct node<T> *temp = Head;
        struct node<T> *tempdelete = NULL;
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

template <class T>
void Singly_CLL<T>::Display()
{
    struct node<T> *temp = Head;

    cout << "Elements from linked list are :" << endl;
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != Head);

    cout << endl;
}

template <class T>
int Singly_CLL<T>::Count()
{
    struct node<T> *temp = Head;
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
    Singly_CLL<int> obj;

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

    cout << "----------------------------------------------------" << endl;

    int iiRet = 0;
    Singly_CLL<char> obj1;

    obj1.InsertFirst('D');
    obj1.InsertFirst('C');
    obj1.InsertFirst('B');
    obj1.InsertFirst('A');
    obj1.Display();
    iiRet = obj1.Count();
    cout << "Number of node is :" << iiRet << endl;

    obj1.InsertLast('E');
    obj1.Display();
    iiRet = obj1.Count();
    cout << "Number of node is :" << iRet << endl;

    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.Display();
    iiRet = obj1.Count();
    cout << "Number of node is :" << iiRet << endl;

    obj1.InsertAtPos('Z', 3);
    obj1.Display();
    iiRet = obj1.Count();
    cout << "Number of node is :" << iiRet << endl;

    obj1.DeleteAtPos(3);
    obj1.Display();
    iiRet = obj1.Count();
    cout << "Number of node is :" << iiRet << endl;
    return 0;
}