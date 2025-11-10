#include<iostream>
#include<string>
using namespace std;
struct node {
    int prn;
    string name;
    node* next;
};
node *temp,*temp1,*temp2;
class pinclub
{
 public:
    node *head,*tail,*nnode;
    pinclub() {
        head=tail=NULL;
    }
    void create();
    void display();
    void deletepresident();
    void deletesecretary();
    void deletemember();
    void count(); 
};

void pinclub::create()
{
    char m;
    do 
    {
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
    } 
    while(m=='y');
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



void pinclub::deletepresident() 
{
    if(head!=NULL) 
    {
        temp=head;
        cout<<endl<<"you deleted president= "<<temp->name<<" "<<temp->prn<<" "; 
        head=temp->next;
        delete temp;
        display();
    }
}

void pinclub::deletesecretary() 
{
    if(head!=NULL && tail!=NULL) 
    {
        temp=head;
        while(temp->next!=tail) 
        {
            temp=temp->next;
        }
        cout<<endl<<"you deleted secretary= "<<tail->name<<" "<<tail->prn<<" "; 
        delete tail;
        tail=temp;
        tail->next=NULL;
        display();
    }
}

void pinclub::deletemember() 
{
    string key;
    cout<<endl<<"Enter the member name that you want to delete: ";
    cin>>key;
    temp=head;
    while(temp->next!=NULL && (temp->next->name)!=key)
    {
        temp=temp->next;
    }
    if(temp->next==NULL) return;
    temp1=temp->next;
    temp2=temp1->next;
    cout<<endl<<"you deleted member= "<<temp1->name<<" "<< temp1->prn<<" "; 
    delete temp1;
    temp->next=temp2;
    display();
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

int main() {
    pinclub l1;
    int choice;
    cout<<"\nWelcome to PINNACLE Club "<<endl;
    l1.create();

    do {
        cout<<"\n\nOPERATIONS";
        
        cout<<"\n1. Delete President ";
        cout<<"\n2. Delete Secretary";
        cout<<"\n3. Delete Member ";
        cout<<"\n4. Count Members";
        cout<<"\n5. Display Members";
        cout<<"\n6. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice) 
        {
           
            case 1: l1.deletepresident(); break;
            case 2: l1.deletesecretary(); break;
            case 3: l1.deletemember(); break;
            case 4: l1.count(); break;
            case 5: l1.display(); break;
            case 6: cout<<"\nExiting..."; break;
            default: cout<<"\nInvalid choice!";
        }
    } 
    while(choice!=6);
    return 0;
}
