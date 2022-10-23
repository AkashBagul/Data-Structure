#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class Doubly_LLL
{
private:
    struct node<T> *Head;

public: // Declartion
    Doubly_LLL();
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
Doubly_LLL<T>::Doubly_LLL() // default constructor
{
    Head = NULL;
}

template <class T>
void Doubly_LLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

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

template <class T>
void Doubly_LLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newn->prev = temp;
        temp->next = newn;
    }
}

template <class T>
void Doubly_LLL<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
        Head->prev = NULL;
    }
}

template <class T>
void Doubly_LLL<T>::DeleteLast()
{
    struct node<T> *temp = Head;

    if (Head == NULL)
    {
        return;
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

template <class T>
void Doubly_LLL<T>::InsertAtPos(T no, int pos)
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
        newn->prev = NULL;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}

template <class T>
void Doubly_LLL<T>::DeleteAtPos(int pos)
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

template <class T>
void Doubly_LLL<T>::Display()
{
    struct node<T> *temp = Head;

    printf("Data from linked list is : \n");

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
int Doubly_LLL<T>::Count()
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
    int iRet = 0;
    Doubly_LLL<int> obj;

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

    cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << endl;

    Doubly_LLL<char> obj1;
    int iiRet = 0;

    obj1.InsertFirst('d');
    obj1.InsertFirst('c');
    obj1.InsertFirst('b');
    obj1.InsertFirst('a');
    obj1.Display();

    obj1.InsertLast('e');
    obj1.Display();

    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.Display();

    obj1.InsertAtPos('z', 3);
    obj1.Display();
    iiRet = obj1.Count();
    cout << "Number of node is :" << iiRet << endl;

    obj1.DeleteAtPos(3);
    obj1.Display();
    iiRet = obj1.Count();
    cout << "Number of node is :" << iiRet << endl;

    return 0;
}