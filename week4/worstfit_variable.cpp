#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node
{
    int start;
    int end;
    int process=0;
    struct node* next=NULL;
};
void deletion(struct node* head)
{
    struct node* temp=head;
    int ID;
    cout<<"Enter the PID to be deleted: ";
    cin>>ID;

    while(temp!=NULL)
    {
        if(temp->process==ID)
        {
            temp->process=0;
            break;
        }
        
        temp=temp->next;
    }
    if(temp==NULL)
        cout<<"No Process with the given ID\n";
    return;
}
void printing(struct node* head)
{
    struct node* temp=head;
    cout<<"PID\tstart\tend\tblocksize\n";
    while(temp!=NULL)
    {
        cout<<temp->process<<"\t"<<temp->start<<"\t"<<temp->end<<"\t"<<temp->end-temp->start+1<<endl;
        temp=temp->next;
    }
    return;
}

void insert(struct node* temp,int blocksize,int PID)
{
    if(blocksize==(temp->end-temp->start+1))
        temp->process=PID;
    else
    {
        struct node* temp2= new node;

        temp2->next=temp->next;
        temp->next=temp2;

        temp2->end=temp->end;
        temp->end=temp->start+blocksize-1;
        temp2->start=temp->end+1;
        temp->process=PID;
    }
    return;
}
void insertion(struct node* head)
{
    int blocksize,PID, flagsize=0;
    struct node* temp=head;
    struct node* temp2=NULL;
    cout<<"Enter the process size: ";
    cin>>blocksize;
    cout<<"Enter process ID: ";
    cin>>PID;

    while(temp!=NULL)
    {
        if(temp->process==0 && blocksize<=(temp->end-temp->start+1) && flagsize<(temp->end-temp->start+1))
        {
            flagsize=(temp->end-temp->start+1);
            temp2=temp;
        }
        temp=temp->next;
    }
    if(temp2==NULL)
    {
            cout<<"process "<<PID<<" cannot be added"<<endl;
            return;
    }
    else
        insert(temp2,blocksize,PID);
    
    return;
}
void arrange(struct node* head)
{
    struct node* temp=head;
    struct node* temp2=NULL;
    while(temp!=NULL)
    {
        if(temp->process==0 && temp->next!=NULL)
        {    
            if(temp->next->process==0 )
            {
                temp->end=temp->next->end;
                temp2=temp->next;
                temp->next=temp->next->next;
                free(temp2);
            }
        }
        temp=temp->next;
    }
    return;
}
void show(struct node *head)
{
    int a;
    cout<<"Enter the option:\n"<<"1. add process\n"<<"2. delete process\n"<<"3. print block\n"<<"4.Exit\n";
    cin>>a;

    switch(a)
    {
        case 1: insertion(head);
                show(head);
                break;
        case 2: deletion(head);
                arrange(head);
                arrange(head);
                show(head);
                break;
        case 3: printing(head);
                show(head);
                break;
        default: return;
    }
}
int main()
{
    int n;
    cout<<"Enter the block size: ";
    cin>>n;

    struct node *head=new node();
    head->start=0;
    head->end=n-1;

    show(head);
    return 0;
}