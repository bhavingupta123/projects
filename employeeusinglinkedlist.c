#include <iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct employee{
    int id;
    char name[10];
    float salary;
    employee *llink;
    employee *rlink;
};
typedef employee* NODE;

/*struct allinfo{

int count1;
float totalsal;

};
allinfo info;

info.count1=0;

info.totalsal=0;*/

int highestsal(NODE first)
{
    NODE temp,store;
    float sal;

    temp=first;

    sal=temp->salary;

    while(temp!=NULL)
    {
        if(temp->salary > sal)
        {
            sal=temp->salary;
            store=temp;

        }

        temp=temp->rlink;
    }

    cout<<"\n employee with highest salary is:";
     cout<<"\n id:"<<store->id<<"\n name:"<<store->name<<"\n salary:"<<store->salary<<"\n";
return 0;
}

int lowestsal(NODE first)
{
    NODE temp,store;
    float sal;

    temp=first;

    sal=temp->salary;

    while(temp!=NULL)
    {
        if(temp->salary < sal)
        {
            sal=temp->salary;
            store=temp;

        }

        temp=temp->rlink;
    }

    cout<<"\n employee with lowest salary is:";
     cout<<"\n id:"<<store->id<<"\n name:"<<store->name<<"\n salary:"<<store->salary<<"\n";
return 0;
}

NODE push(NODE first)
{
    NODE newnode=(NODE)malloc(sizeof(employee));
    cout<<"\n enter id:";
    cin>>newnode->id;

    cout<<"\n enter name:";
    cin>>newnode->name;

    cout<<"\n enter salary:";
    cin>>newnode->salary;

    newnode->llink=NULL;
    newnode->rlink=first;

    if(first!=NULL)
    {
        first->llink=newnode;
    }

    first=newnode;
    cout<<"\nitem inserted";
    //info.count1++;
    return first;
}

NODE pop(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        cout<<"\n empty ";
        return first;
    }
    else
    {
        temp=first;
        cout<<"\n record deleted is:\n";
        cout<<"\n id:"<<temp->id<<"\n name:"<<temp->name<<"\n salary:"<<temp->salary<<"\n";
        first=first->rlink;
        first->llink=NULL;

       // info.count1--;

        free(temp);
        return first;
    }
}

void display(NODE first)
{
    NODE temp=first;
    if(first==NULL)
    {
        cout<<"\n empty";
    }

    else
    {
        while(temp!=NULL)
        {
                cout<<"\n id:"<<temp->id<<"\n name:"<<temp->name<<"\n salary:"<<temp->salary<<"\n";
                temp=temp->rlink;
        }


    }
}

NODE deleteinfo(NODE first)
{
    int key;
    NODE pres,prev;
    if(first==NULL)
    {
        cout<<"\n empty:";
        return first;
    }

    cout<<"\n enter id:";
    cin>>key;

    if(key==first->id)
    {
        pres=first;
        first=first->rlink;
        cout<<"\n record deleted is:\n";
        cout<<"\n id:"<<pres->id<<"\n name:"<<pres->name<<"\n salary:"<<pres->salary<<"\n";
        free(pres);
        first->llink=NULL;

        //info.count1--;

        return first;
    }

    pres=first;

    while(pres!=NULL && prev->id!=key)
    {
        prev=pres;
        pres=pres->rlink;
    }

    if(pres==NULL)
    {
        cout<<"\n not found";
        return first;
    }

    cout<<"\n record deleted is:\n";
    cout<<"\n id:"<<pres->id<<"\n name:"<<pres->name<<"\n salary:"<<pres->salary<<"\n";

    //info.count1--;

    prev->rlink=pres->rlink;
    pres->rlink->llink=prev;
    free(pres);

    return first;

}

NODE insertpos(NODE first)
{
    int pos;
    NODE prev,pres;

    cout<<"\n enter position to insert record:";
    cin>>pos;

    if(pos==1)
    {
        NODE newnode=(NODE)malloc(sizeof(employee));

        cout<<"\n enter id:";
        cin>>newnode->id;

        cout<<"\n enter name:";
        cin>>newnode->name;

        cout<<"\n enter salary:";
        cin>>newnode->salary;

        newnode->rlink=first;
        first->llink=newnode;

        first=newnode;
        newnode->llink=NULL;
        cout<<"\n record inserted";

        //info.count1++;

        return first;

    }
    int cnt=0;
    pres=first;

    while(cnt<=pos-1 && pres!=NULL)
    {
        prev=pres;
        pres=pres->rlink;
        cnt++;
    }

    if(pres==NULL)
    {
        cout<<"\n not possible:";
        return first;
    }

    else{
        NODE newnode=(NODE)malloc(sizeof(employee));

        cout<<"\n enter id:";
        cin>>newnode->id;

        cout<<"\n enter name:";
        cin>>newnode->name;

        cout<<"\n enter salary:";
        cin>>newnode->salary;

        newnode->llink=prev->rlink;
        newnode->rlink=pres->llink;
        prev->rlink=newnode;
        pres->llink=newnode;

        cout<<"\n record inserted:";

        //info.count1++;

        return first;
    }
}

/*int collectiveinfo()
{
    cout<<"\n total employees:"<<info.count1;
    cout<<"\n total salary:"<<info.totalsal;

    return 0;
}*/

int main()
{
    int ch,i,j,k;
    NODE first=NULL;
    while(1)
    {
        cout<<"\n \nenter 1-insert new record,\n 2-delete last inserted record,3-display \n 4-insert at particular position \n 5-delete according to info:";
        cout<<"\n enter 6 to see collective info \n 7-employee with highest salary \n 8-employee with lowest salary :";
        cin>>ch;

        switch(ch)
            {
                case 1:first=push(first);
                        break;

                case 2:first=pop(first);
                        break;

                case 3:display(first);
                       break;

                case 4:first = insertpos(first);
                       break;

                case 5:first = deleteinfo(first);
                       break;

                /*case 6:collectiveinfo();
                        break;*/

                case 7:highestsal(first);
                       break;

                case 8:lowestsal(first);
                       break;

                default:exit(0);
            }
    }
    return 0;
}
