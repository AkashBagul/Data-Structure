#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if ((*Head == NULL) || (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = *Head;
}
void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
    }
    (*Tail)->next = *Head;
}
void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if ((*Head == NULL) && (*Tail == NULL)) // Linked list empty
    {
        return;
    }
    else if (*Head == *Tail) // LL contain  one node
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);
    }
    (*Tail)->next = *Head;
}
void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PPNODE temp = NULL;
    if ((*Head == NULL) && (*Tail == NULL)) // Linked list empty
    {
        return;
    }
    else if (*Head == *Tail) // LL contain  one node
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else // If LL contains more than 1 node
    {
        PNODE temp = *Head;

        while (temp->next != (*Tail))
        {
            temp = temp->next;
        }
        free(*Tail);
        *Tail = temp;
    }
    (*Tail)->next = *Head;
}
void InsertAtPos(PPNODE Head, PPNODE Tail, int iNo, int pos)
{
    PNODE temp = *Head;
    int iSize = 0;

    iSize = Count(*Head);
    if ((pos < 1) || (pos > iSize + 1))
    {
        return;
    }
    else if (pos == 1)
    {
        InsertFirst(Head, Tail, iNo);
    }
    else if (pos == iSize + 1)
    {
        InsertLast(Head, Tail, iNo);
    }
    else
    {

        int iCnt = 0;
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = (temp)->next;
        }
        newn->next = (temp)->next;
        temp->next = newn;
    }
}
void DeleteAtPos(PPNODE Head, PPNODE Tail, int pos)
{
    int iSize = Count(*Head);
    if ((pos < 1) || (pos > iSize))
    {
        return;
    }
    else if (pos == 1)
    {
        DeleteFirst(Head, Tail);
    }
    else if (pos == iSize)
    {
        DeleteLast(Head, Tail);
    }
    else
    {
        PNODE temp = *Head;
        int iCnt = 0;
        PNODE newn = NULL;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = (temp)->next;
        }
        PNODE tempdelete = (temp)->next;
        (temp)->next = (tempdelete)->next;
        free(tempdelete);
    }
}
void Dispaly(PNODE Head)
{
    PNODE temp = Head;
    printf("Elements from linked list are : \n");

    do
    {
        printf("| %d |->", temp->data);
        temp = temp->next;
    } while (temp != (Head));
    printf("\n");
}
int Count(PNODE Head)
{
    int iCnt = 0;
    PNODE temp = Head;
    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != (Head));
    return iCnt;
}

int main()
{
    PNODE first = NULL;
    PNODE second = NULL;
    int iRet = 0;

    InsertFirst(&first, &second, 101);
    InsertFirst(&first, &second, 51);
    InsertFirst(&first, &second, 21);
    InsertFirst(&first, &second, 11);

    Dispaly(first);

    InsertLast(&first, &second, 121);
    Dispaly(first);

    DeleteFirst(&first, &second);
    Dispaly(first);

    DeleteLast(&first, &second);
    Dispaly(first);
    iRet = Count(first);
    printf("Number of node is:%d\n", iRet);

    InsertAtPos(&first, &second, 75, 3);
    Dispaly(first);

    DeleteAtPos(&first, &second, 3);
    Dispaly(first);

    iRet = Count(first);
    printf("Number of node is:%d", iRet);

    return 0;
}