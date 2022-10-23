import java.lang.*;
import java.util.*;

class SinglyCircular
{
    public static void main(String arg[])
    {
        int iRet =0;
        SinglyCLL obj = new SinglyCLL();

        
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
        iRet= obj.Count();
        System.out.println("Nuber of node is:"+iRet);

        obj.InsertAtPos(75,3);
        obj.Display();
        iRet= obj.Count();
        System.out.println("Nuber of node is:"+iRet);

        obj.DeleteAtPos(3);
        obj.Display();
        iRet= obj.Count();
        System.out.println("Nuber of node is:"+iRet);


    }
}

class node 
{
    public int data;
    public node next;
}

class SinglyCLL
{
    private node Head;
    private node Tail;

    public SinglyCLL()
    {
        Head = null;
        Tail = null;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node();

        newn.data = iNo;
        newn.next = null;

        if((Head==null)&&(Tail==null))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            newn.next = Head;
            Head = newn;
        }
        Tail.next = Head;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node();

        newn.data = iNo;
        newn.next = null;

        if((Head==null)&&(Tail==null))
        {
            Tail = newn;
            Head = newn;
        }
        else
        {
            Tail.next = newn;
            Tail = newn;
        }
        Tail.next = Head;
    }

    public void DeleteFirst()
    {
        if((Head == null)&&(Tail == null))
        {
            return;
        }
        else if(Head == Tail)
        {
            Head =null;
            Tail =null;
        }
        else
        {
            Head = Head.next;
            Tail.next=null;
        }
        Tail.next = Head;
    }

    public void DeleteLast()
    {
        if((Head == null)&&(Tail == null))
        {
            return;
        } 
        else if(Head == Tail)
        {
            Head =null;
            Tail =null;
        }
        else
        {
            node temp = Head;

            while(temp.next!=Tail)
            {
                temp = temp.next;
            }
            Tail = null;
            Tail= temp;
        }
        Tail.next = Head;
    }

    public void InsertAtPos(int iNo, int iPos)
    {
        int iSize = Count();
        if((iPos < 1)||(iPos > iSize+1))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if (iPos == iSize+1)
        {
            InsertLast(iNo);
        }
        else
        {
            int iCnt =0;
            node temp = Head;

            node newn = null;
            newn = new node();

            newn.data = iNo;
            newn.next = null;

            for(iCnt = 1; iCnt < iPos -1; iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next =newn;
        }

    }

    public void DeleteAtPos( int iPos)
    {
        int iSize = Count();
        if((iPos < 1)||(iPos > iSize))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(iPos == 1)
        {
            DeleteFirst();
        }
        else if (iPos == iSize)
        {
            DeleteLast();
        }
        else
        {
            int iCnt =0;
            node temp = Head;

            for(iCnt = 1; iCnt < iPos -1; iCnt++)
            {
                temp = temp.next;
            }
            node tempdelete = temp.next;
            temp.next=tempdelete.next;
            tempdelete =null;
        }

    }

    public void Display()
    {
        node temp = Head;

        System.out.println("Data from linked list is :");
        do
        {
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        } while(temp!=Head);
        
        System.out.println("");

    }

    public int Count()
    {
        int iCnt=0;
        node temp = Head;
        do
        {
           iCnt++;
            temp = temp.next;
        } while(temp!=Head);
        
        return iCnt;

    }
}