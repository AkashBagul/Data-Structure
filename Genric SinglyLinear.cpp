#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Singly_LLL
{
private:
    struct node<T> *Head; // Charteristic

public: // Declartion
    Singly_LLL();
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
Singly_LLL<T>::Singly_LLL() // default constructor
{
    Head = NULL;
}

template <class T>
void Singly_LLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if (Head != NULL)
    {
        newn->next = Head;
    }

    Head = newn;
}

template <class T>
void Singly_LLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;

    newn = new struct node<T>;

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

template <class T>
void Singly_LLL<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        struct node<T> *temp = Head;
        Head = Head->next;
        delete temp;
    }
}

template <class T>
void Singly_LLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        struct node<T> *temp = Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

template <class T>
void Singly_LLL<T>::InsertAtPos(T no, int pos)
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
        struct node<T> *temp = Head;

        struct node<T> *newn = NULL;
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
void Singly_LLL<T>::DeleteAtPos(int pos)
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
void Singly_LLL<T>::Display()
{
    struct node<T> *temp = Head;

    cout << "Elements from linked list are :" << endl;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
int Singly_LLL<T>::Count()
{
    struct node<T> *temp = Head;
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
    Singly_LLL<int> obj;
    int iRet = 0;

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

    cout << "-------------------------------------------------" << endl;

    Singly_LLL<float> obj1;
    float fRet = 0;

    obj1.InsertFirst(11.1);
    obj1.InsertFirst(51.0);
    obj1.InsertFirst(21.11);
    obj1.InsertFirst(11.21);
    obj1.Display();

    obj1.InsertLast(12.1);
    obj1.Display();

    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.Display();

    obj1.InsertAtPos(75.36, 3);
    obj1.Display();
    fRet = obj1.Count();
    cout << "Number of node is :" << fRet << endl;

    obj1.DeleteAtPos(3);
    obj1.Display();
    fRet = obj1.Count();
    cout << "Number of node is :" << fRet << endl;

    return 0;
}
