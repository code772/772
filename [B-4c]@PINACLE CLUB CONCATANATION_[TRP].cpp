#include<iostream>
#include<string>
using namespace std;

struct node {
    int prn;
    string name;
    node* next;
};
node *temp,*temp1,*temp2;

class pinclub {
 public:
    node *head,*tail,*nnode;
    pinclub() {
        head=tail=NULL;
    }
    void create();
    void display();
    void count(); 
    void concatenation(pinclub &l2);
};

void pinclub::create() {
    char m;
    do {
        nnode=new node;
        nnode->next=NULL;
        cout<<endl<<"Enter prn number: ";
        cin>>nnode->prn;
        cout<<endl<<"Enter name of user: ";
        cin>>nnode->name;
        if(head==NULL) 
        {
            head=tail=nnode;
        } 
        else
        {
            tail->next=nnode;
            tail=nnode;
        }
        cout<<endl<<"Do you want to continue(y or n): ";
        cin>>m;
    } while(m=='y');
    display();
}

void pinclub::display() 
{
    cout<<endl<<" YOUR UPDATED CLUB DATA IS: "<<endl;
    if(head==NULL) 
    {
        cout<<endl<<"club is empty";
    } 
    else 
    {
        cout<<"\n PRN NO.\t NAME"<<endl;  
        temp=head;
        while(temp!=NULL) 
        {
            cout<<endl<<temp->prn<<"           " <<temp->name;
            temp=temp->next;
        }
    }
}


void pinclub::count() 
{
    int c=0;
    temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    cout<<"\nTotal members in club are: "<<c<<endl;
}
void pinclub::concatenation(pinclub &l2) 
{
    if(tail!=NULL && l2.head!=NULL) 
    {
        tail->next=l2.head;
        tail=l2.tail;
        cout<<"\nClubs concatenated successfully"<<endl;
    } 
    else 
    {
        cout<<"\nConcatenation not possible (one list is empty)."<<endl;
    }
}

int main()
{
    pinclub l1,l2;
    int choice;
    cout<<"\nWelcome to PINNACLE Club 1"<<endl;
    l1.create();

    cout<<"\nWelcome to PINNACLE Club 2"<<endl;
    l2.create();

    do 
    {
        cout<<"\n\nOPERATIONS";
        cout<<"\n1. Count Members (Club 1)";
        cout<<"\n2. Display Members (Club 1)";
        cout<<"\n3. Concatenate Club1 + Club2";
        cout<<"\n4. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice) 
        {
            
            case 1: l1.count(); break;
            case 2: l1.display(); break;
            case 3: l1.concatenation(l2); l1.display(); break;
            case 4: cout<<"\nExiting..."; break;
            default: cout<<"\nInvalid choice!";
        }
    } while(choice!=4);

    return 0;
}
