#include<iostream>
#include<cstring>
using namespace std;

struct node
{
    int seat_no;
    int status;   // 0 = vacant, 1 = booked
    node *next;
    node *prv;
};

class DLL
{
public:
    node *head, *tail;
    node *A[11];   // Array storing head pointer for each row

    DLL()
    {
        head = NULL;
        tail = NULL;
        for (int i = 0; i < 11; i++)
            A[i] = NULL;
    }

    void create();
    void display();
    void cancel_seat();
};

// ---------------- CREATE FUNCTION ----------------
void DLL::create()
{
    cout << "Creating seats with some pre-booked...\n";
    for (int r = 1; r <= 10; r++)
    {
        A[r] = NULL;
        head = tail = NULL;

        for (int s = 1; s <= 7; s++)
        {
            node *nnode = new node;
            nnode->seat_no = s;

            // Marking some seats as pre-booked (random pattern)
            if ((r == 2 && (s == 3 || s == 5)) || 
                (r == 4 && s == 1) || 
                (r == 5 && (s == 2 || s == 6)) || 
                (r == 7 && s == 4) || 
                (r == 9 && s == 7))
                nnode->status = 1; // booked
            else
                nnode->status = 0; // vacant

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
        cout << "Row " << r << " created.\n";
    }
}

// ---------------- DISPLAY FUNCTION ----------------
void DLL::display()
{
    cout << "\n Seat Status \n";
    for (int r = 1; r <= 10; r++)
    {
        cout << "\nRow " << r << ":\n";

        node *temp = A[r];
        cout << "Booked seats: ";
        while (temp != NULL)
        {
            if (temp->status == 1)
                cout << temp->seat_no << " ";
            temp = temp->next;
        }

        temp = A[r];
        cout << "\nVacant seats: ";
        while (temp != NULL)
        {
            if (temp->status == 0)
                cout << temp->seat_no << " ";
            temp = temp->next;
        }
        cout << "\n\n";
    }
    cout << endl;
}

// ---------------- CANCEL FUNCTION ----------------
void DLL::cancel_seat()
{
    char ch;
    do
    {
        int row, key;
        cout << "\nEnter row no from which you want to cancel seat: ";
        cin >> row;
        cout << "Enter seat no which you want to cancel: ";
        cin >> key;

        node *temp = A[row];
        while (temp != NULL && temp->seat_no != key)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid seat number.\n";
        }
        else if (temp->status == 1)
        {
            temp->status = 0;
            cout << "Seat cancellation successful!\n";
        }
        else
        {
            cout << "Seat was not booked.\n";
        }

        cout << "Do you want to continue cancelling? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

// ---------------- MAIN FUNCTION ----------------
int main()
{
    DLL b1;
    cout << "Welcome to CINEMAX Ticket Cancellation System\n";

    b1.create();
    cout << "\nInitial Seat Status:\n";
    b1.display();

    b1.cancel_seat();

    cout << "\nAfter Cancellation:\n";
    b1.display();

    return 0;
}
