#include<iostream>
using namespace std;

int main() {
    int n, i, j, pass, minIndex;
    cout << "\nHow many students for Selection Sort? ";
    cin >> n;

    float G[20], temp;
    cout << "Enter percentage of students:\n";
    for(i = 0; i < n; i++) {
        cin >> G[i];
    }

    cout << "\nSelection Sort: ";
    for(i = 0; i < n; i++) {
        cout << G[i] << " ";
    }
    cout << endl;

    for(pass = 0; pass < n - 1; pass++) {
        minIndex = pass;
        int comparisons = 0;

        for(j = pass + 1; j < n; j++) {
            comparisons++;
            if(G[j] < G[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != pass) {
            temp = G[pass];
            G[pass] = G[minIndex];
            G[minIndex] = temp;
        }

        cout << "Pass " << pass + 1 << " Comparisons: " << comparisons << "  Array: ";
        for(i = 0; i < n; i++) {
            cout << G[i] << " ";
        }
        cout << endl;
    }

    cout << "Top 5 scores are: ";
    for(i = n - 1; i >= n - 5 && i >= 0; i--) {
        cout << G[i] << " ";
    }
    return 0;
}