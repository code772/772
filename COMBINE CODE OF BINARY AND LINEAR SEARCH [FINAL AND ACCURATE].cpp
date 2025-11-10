#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, i;
    int A[10];
    cout << "how many students are present for the training: ";
    cin >> n;

    cout << "\nenter roll no of all " << n << " students:";
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    cout << "roll no of present students: ";
    for (i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    int roll, presence;
    char ch;

    do
    {
        presence = 0; 
        cout << "\nEnter a roll no that you want to check is present or not: ";
        cin >> roll;

        for (i = 0; i < n; i++)
        {
            if (A[i] == roll)
            {
                presence = 1;
                break;
            }
        }

        if (presence == 1)
        {
            cout << "student is present";
        }
        else
        {
            cout << "student is absent";
        }

        cout << "\nDo you want to continue?(y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "\nbinary search\n";

    sort(A, A + n);

    cout << "\nsorted data: ";
    for (i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    // Binary search part
    int start, end, mid, key, match;
    do
    {
        cout << "\nEnter roll number to search (binary search): ";
        cin >> key;

        start = 0;
        end = n - 1;
        match = 0;

        while (start <= end)
        {
            mid = (start + end) / 2;
            if (A[mid] == key)
            {
                match = 1;
                break;
            }
            else if (A[mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        if (match == 1)
        {
            cout << "student is present\n";
        }
        else
        {
            cout << "student is absent\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}