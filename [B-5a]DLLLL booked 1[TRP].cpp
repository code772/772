#include<iostream>
#include<cstring>
using namespace std;
struct node
{
int seat_no;
int status;
node *next;
node *prv;
};

class DLL
{
public:
node *head, *tail;
node *A[11];
DLL()
{
    head = NULL;
    tail = NULL;
    for (int i = 0; i < 11; i++)
    {
        A[i] = NULL;
    }
}

void create();
void display();
void book_seat();
};

void DLL::create()
{
for (int r = 1; r <= 10; r++)
{
A[r] = NULL;
for (int s = 1; s <= 7; s++)
{
node *nnode = new node;
nnode->status = 0;
nnode->seat_no = s;
nnode->next = NULL;
nnode->prv = NULL;
        if (A[r] == NULL)
        {
            A[r] = nnode;
            head = nnode;
            tail = nnode;
        }
        else
        {
            tail->next = nnode;
            nnode->prv = tail;
            tail = nnode;
        }
    }
    cout << "Row " << r << " is created" << endl;
}
}

void DLL::display()
{
for (int r = 1; r <= 10; r++)
{
cout << "\nRow NO " << r << endl;
node *temp = A[r];
cout << "Vacant seats:\n";
cout << "Seat_NO" << endl;
    while (temp != NULL)
    {
        if (temp->status == 0)
        {
            cout << temp->seat_no << "    ";
        }
        temp = temp->next;
    }
}

}

void DLL::book_seat()
{
char ch;
do
{
int row, key;
cout << "\n Enter row no from which you want to book seat: ";
cin >> row;
cout << "\n Enter seat no which you want to book: ";
cin >> key;
    node *temp = A[row];
    while (temp != NULL && temp->seat_no != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "row is empty" << endl;
    }
    else
    {
        cout << "Status of this seat is " << temp->status << endl;
        if (temp->status == 0)
        {
            temp->status = 1;
            cout << " Your seat is booked now" << endl;
        }
        else
        {
            cout << " Seat is not available" << endl;
        }
    }

    cout << "\nDo you want to continue? (y/n)" << endl;
    cin >> ch;
} while (ch == 'y');
}

int main()
{
DLL b1;
cout << "Welcome to booking" << endl;

b1.create();
cout << "\nList of vacant seats:" << endl;
b1.display();

b1.book_seat();
b1.display();


return 0;


}
