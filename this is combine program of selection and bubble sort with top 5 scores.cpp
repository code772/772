
#include <iostream>
using namespace std;

int main() 
{
    int i,n,j,f;
    float temp;
    cout<<"Enter The Total No of students for sorting : ";
    cin>>n;
    float a[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter the Score of "<<i+1<<" student: ";
        cin>>a[i];
    }
    cout<<endl;
    //BUBBLE SORT
    cout<<"ALL PASS OF BUUBLE SORT :-"<<endl;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-i)-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        cout<<"PASS "<<i+1<<" :- ";
        for(f=0;f<n;f++)
        {
           cout<<a[f]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"AFTER APPLYING BUBBLE SORT : "<<endl;
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<endl;
    cout<<"TOP 5 SCORES : "<<endl;
    for(f=n-1;f>=n-5;f--)
    {
        cout<<a[f]<<" ";
    }
    cout<<endl<<endl;
    // SELCTION SORT
    for(i=0;i<n-1;i++)
    {
        int s=i;
        for(j=i+1;j<n;j++)
        {
            if(a[s]<a[j])
            {
                s=j;
            }
            swap(a[j],a[s]);
        }
        cout<<"PASS "<<i+1<<" :- ";
        for(f=0;f<n;f++)
        {
           cout<<a[f]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"AFTER APPLYING SELECTION SORT : "<<endl;
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<endl;
    cout<<"TOP 5 SCORES : "<<endl;
    for(f=n-1;f>=n-5;f--)
    {
        cout<<a[f]<<" ";
    }
    return 0;
}

