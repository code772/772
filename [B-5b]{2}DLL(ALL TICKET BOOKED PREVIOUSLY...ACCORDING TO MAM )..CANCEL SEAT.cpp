#include<iostream>
using namespace std;

struct node
{
    int seat_no;
    int status;     // 0 = vacant, 1 = booked
    node *next;
    node *prv;
};

class DLL
{
public:
    node *A[11];    // head pointer for each row
    node *head, *tail;

    DLL()
    {
        for (int i = 0; i < 11; i++)
            A[i] = NULL;
        head = tail = NULL;
    }

    void create();
    void display();
    void cancel_seat();
};

void DLL::create()
{
    cout << "Creating all rows with all seats booked...\n";
    for (int r = 1; r <= 10; r++)
    {
        A[r] = NULL;
        head = tail = NULL;

        for (int s = 1; s <= 7; s++)
        {
            node *nnode = new node;
            nnode->seat_no = s;
            nnode->status = 1;    // all seats booked
            nnode->next = NULL;
            nnode->prv = NULL;

            if (A[r] == NULL)
            {
                A[r] = nnode;
                head = tail = nnode;
            }
            else
            {
                tail->next = nnode;
                nnode->prv = tail;
                tail = nnode;
            }
        }
        cout << "Row " << r << " created successfully.\n";   // ✅ shows each row created
    }
}

void DLL::display()
{
    cout << "\nSeat Status:\n";
    for (int r = 1; r <= 10; r++)
    {
        cout << "\nRow " << r << " -> ";
        node *temp = A[r];

        cout << "Booked: ";
        while (temp != NULL)
        {
            if (temp->status == 1)
                cout << temp->seat_no << " ";
            temp = temp->next;
        }

        temp = A[r];
        cout << "\n         Vacant: ";
        bool empty = false;
        while (temp != NULL)
        {
            if (temp->status == 0)
            {
                cout << temp->seat_no << " ";
                empty = true;
            }
            temp = temp->next;
        }
        if (!empty)
            cout << "None";
        cout << endl;
    }
}

void DLL::cancel_seat()
{
    char ch;
    do
    {
        int row, seat;
        cout << "\nEnter row number: ";
        cin >> row;
        cout << "Enter seat number to cancel: ";
        cin >> seat;

        node *temp = A[row];
        while (temp != NULL && temp->seat_no != seat)
            temp = temp->next;

        if (temp == NULL)
            cout << "Invalid seat number!\n";
        else if (temp->status == 1)
        {
            temp->status = 0;
            cout << "Seat cancelled successfully!\n";
        }
        else
            cout << "Seat already vacant!\n";

        cout << "Do you want to cancel another seat? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

int main()
{
    DLL obj;
    cout << "Welcome to CINEMAX Ticket Cancellation System\n";

    obj.create();       // ✅ Shows rows created
    obj.display();      // Shows booked and vacant seats

    obj.cancel_seat();  // Allows user to cancel
    obj.display();      // Shows updated seat status

    return 0;
}
