#include <iostream>
#include<algorithm>
using namespace std;

void linearSearch(int A[],int n,int x){
   int i;
   int presence=0;
   for (i = 0; i < n; i++)
        {
            if (A[i] == x)
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
   
}
void binarySearch(int A[],int n,int key){
    sort(A,A+n);
    int start = 0;
    int end = n - 1;
    int match = 0;

    while (start <= end)
    {
        int mid = (start + end) / 2;
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
}

int main(){
    int n,choice,key;
    cout<<"Enter number of student were present:";
    cin>>n;
    int roll[100];
    cout<<"Enter roll numbers of present student:\n";
    for(int i=0;i<n;i++){
        cin>>roll[i];
    }
    do{
        cout<<"\n---Menu---\n";
        cout<<"1.Display Roll numbers\n";
        cout<<"2.Search student (linear Search)\n";
        cout<<"3.Search student (Bubble search\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Roll numbers of attended students:\n";
                for(int i;i<n;i++){
                    cout<<roll[i]<<" ";
                }
                break;
            case 2:
                cout<<"Enter roll number:";
                cin>>key;
                linearSearch(roll,n,key);
                break;
            case 3:
                cout<<"Enter roll number:";
                cin>>key;
                binarySearch(roll,n,key);
                break;
            case 4:
                cout<<"Exiting program..\n";
                break;
        }
        
    }while(choice!=4);
    return 0;
}