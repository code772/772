#include <iostream>
#include <cstring>
using namespace std;

struct record 
{
    char name[10];
    int telno;
};

int main()
{
    
    record qptelDir[10];
    
    // Initialize QUADRATIC TABLE
    for (int i = 0; i < 10; i++) 
    {
        strcpy(qptelDir[i].name, "empty");
        qptelDir[i].telno = -1;
    }

    int n;
    cout << "How Many Records? ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char Tempname[10];
        int TempNo;

        cout << "\nEnter Client Name: ";
        cin >> Tempname;

        cout << "Enter Telephone No of client: ";
        cin >> TempNo;

        int Total = 0;
        for (int j = 0; Tempname[j] != '\0'; j++) 
        {
            Total += Tempname[j];
        }
        int h = Total % 10;
        // QUADRATIC PROBING
        if (strcmp(qptelDir[h].name, "empty") == 0) 
        {
            strcpy(qptelDir[h].name, Tempname);
            qptelDir[h].telno = TempNo;
        } 
        else 
        {
            for (int k = 1; k < 10; k++)
            {
                int idx = (h + k * k) % 10;
                if (qptelDir[idx].telno == -1) 
                {
                    strcpy(qptelDir[idx].name, Tempname);
                    qptelDir[idx].telno = TempNo;
                    break;
                }
            }
    }   }
    // Display QUADRATIC PROBING
    cout << "\nFor Quadratic Probing:\nIndex\tName\t\tTel No:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t" << qptelDir[i].name << "\t\t" << qptelDir[i].telno << endl;
    }
    // SEARCHING in all tables
    char searchName[10];
    char ch;
    do
    {
    cout << "\nEnter name to search: ";
    cin >> searchName;
    // Search in Quadratic Probing
    cout << "\nSearching in Quadratic Probing:\n";
    int foundQuadratic = 0;
    for (int i = 0; i < 10; i++) 
    {
        if (strcmp(qptelDir[i].name, searchName) == 0)
         {
            cout << qptelDir[i].name << " is found";
            cout<< "\ntelno of given name is== " << qptelDir[i].telno;
            cout<< " \nat the index " << i << endl;
            foundQuadratic = 1;
        }
    }
    if (foundQuadratic == 0)
        cout << "  this name is not found in Quadratic Probing\n";
    cout << "do you want to continue searching? (y/n): ";
    cin>>ch;
    } 
    while (ch=='y');
    return 0;
}
