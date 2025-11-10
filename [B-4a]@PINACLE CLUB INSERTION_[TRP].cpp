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
    void insertion();
    void insertionlast();
    void insertionmid();
    void count(); 
    
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
        if(head==NULL) {
            head=tail=nnode;
        } else {
            tail->next=nnode;
            tail=nnode;
        }
        cout<<endl<<"Do you want to continue(y or n): ";
        cin>>m;
    } while(m=='y');
    display();
}

void pinclub::display() {
    cout<<endl<<" YOUR UPDATED CLUB DATA IS: "<<endl;
    if(head==NULL) {
        cout<<endl<<"club is empty";
    } else {
        cout<<"\n PRN NO.\t NAME"<<endl;  
        temp=head;
        while(temp!=NULL) {
            cout<<endl<<temp->prn<<"           " <<temp->name;
            temp=temp->next;
        }
    }
}

void pinclub::insertion() { //president
    nnode=new node;
    nnode->next=NULL;
    cout<<endl<<"Enter president name: ";
    cin>>nnode->name;
    cout<<endl<<"Enter prn of president: ";
    cin>>nnode->prn;
    nnode->next=head;
    head=nnode;
    display();
}

void pinclub::insertionlast() {
    nnode=new node;
    nnode->next=NULL;
    cout<<endl<<"Enter name of secretary : ";
    cin>>nnode->name;
    cout<<endl<<"Enter prn of secretary: ";
    cin>>nnode->prn;
    tail->next=nnode;
    tail=nnode;
    display();
}

void pinclub::insertionmid() {
    cout<<endl<<"Middle insertion";
    string key;
    cout<<endl<<"Enter the name of club member after which you want to insert: ";
    cin>>key;
    nnode=new node;
    nnode->next=NULL;
    cout<<endl<<"Enter prn number that you want to insert: ";
    cin>>nnode->prn;
    cout<<endl<<"Enter name of user that you want to insert: ";
    cin>>nnode->name;
    temp=head;
    while(temp!=NULL && temp->name!=key) {
        temp=temp->next;
    }
    if(temp!=NULL) {
        nnode->next=temp->next;
        temp->next=nnode;
    }
    display();
}
void pinclub::count() {
    int c=0;
    temp=head;
    while(temp!=NULL) {
        c++;
        temp=temp->next;
    }
    cout<<"\nTotal members in club are: "<<c<<endl;
}
int main() 
{
    pinclub l1;
    int choice;
    cout<<"\nWelcome to PINNACLE CLUB"<<endl;
    l1.create();
    do {
        cout<<"\n\nOPERATIONS";
        cout<<"\n1. Insert President ";
        cout<<"\n2. Insert Secretary ";
        cout<<"\n3. Insert Member in Middle ";
        cout<<"\n4. Count Members ";
        cout<<"\n5. Display Members ";
        cout<<"\n6. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1: l1.insertion(); break;
            case 2: l1.insertionlast(); break;
            case 3: l1.insertionmid(); break;
            case 4: l1.count(); break;
            case 5: l1.display(); break;
            case 6: cout<<"\nExiting..."; break;
            default: cout<<"\nInvalid choice!";
        }
    } while(choice!=6);

    return 0;
}
