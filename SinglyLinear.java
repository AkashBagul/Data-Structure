import java.lang.*;
import java.util.*;

class SinglyLinear
{
    public static void main(String arg[])
    {
        SinglyLL obj =new SinglyLL();
        int iRet=0;

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
    public node next;      //struct node * next;
}

class SinglyLL
{
    private node Head;   //Characterstic

    SinglyLL()
    {
        Head=null;
    }

    public void InsertFirst(int iNo)
    {
        node newn = null;
        newn= new node();

        newn.data= iNo;
        newn.next=null;
        if(Head!=null)
        {
            newn.next=Head;
        }
         Head= newn;

    }

    public void InsertLast(int iNo)
    {
        node newn = null;
        newn= new node();

        newn.data= iNo;
        newn.next=null;
        if(Head==null)
        {
           Head= newn;
        }
        else
        {
            node temp = Head;
            while(temp.next!=null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }  

    }

    public void DeleteFirst()
    {
        if(Head==null)
        {
            return;
        }
        else
        {
            node temp = Head;
            Head= Head.next;
            temp =null;
        }
    }

    public void DeleteLast()
    {
        if(Head==null)
        {
            return;
        }
        else
        {
            node temp = Head;
            while(temp.next.next!=null)
            {
                temp= temp.next;
            }
            temp.next=null;
        }
    }

    public void InsertAtPos(int iNo,int iPos)
    {
        int iSize= 0;
        iSize=Count();
        if((iPos<1)||(iPos>iSize+1))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(iPos==1)
        {
            InsertFirst(iNo);
        }
        else if(iPos ==iSize+1)
        {
            InsertLast(iNo);
        }
        else
        {
            int iCnt =0;
            node temp = Head;

            node newn=null;
            newn= new node();

            newn.data = iNo;
            newn.next = null;

            for(iCnt=1;iCnt<iPos-1;iCnt++)
            {
                temp = temp.next;
            }

            newn.next=temp.next;
            temp.next = newn;

        }
    }
    
    public void DeleteAtPos(int iPos)
    {
        int iSize= 0;
        iSize=Count();
        if((iPos<1)||(iPos>iSize))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(iPos==1)
        {
            DeleteFirst();
        }
        else if(iPos ==iSize)
        {
            DeleteLast();
        }
        else
        {
            int iCnt =0;
            node temp = Head;
            for(iCnt=1;iCnt<iPos-1;iCnt++)
            {
                temp = temp.next;
            }

            node tempdelete = temp.next;
            temp.next= tempdelete.next;
            tempdelete= null;

        }
    }

    public void Display()
    {
        node temp= Head;

        System.out.println("Data from linked list is :");
        while(temp!=null)
        {
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public int Count()
    {
        int iCnt=0;
        node temp= Head;

        while(temp!=null)
        {
           iCnt++;
            temp = temp.next;
        }
        return iCnt;
    }
}