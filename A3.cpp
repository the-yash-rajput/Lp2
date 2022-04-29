#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void selectionSort() 
{
    cout << "Enter the length of array:- ";
    int n;
    cin >> n;
    cout << "Enter the array seperated by space:- ";
    ll a[n];
    for (int i = 0; i < n;i++)
        cin >> a[i];

    int i, j, min_idx;
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (a[j] < a[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(a[min_idx],a[i]); 
    }
    cout << "Your sorted array is:- ";
    for (int i = 0; i < n;i++)
        cout << a[i] << " ";
}

signed main()
{
    while(1){
        cout << "\nMenu:\n";
        cout << "1] Selection Sort\n";
        cout << "0] Exit\n";
        cout << "Enter your choice:- ";
        int c;
        cin >> c;
        if (c==0){
            break;
        }
        else if(c==1){
            selectionSort();
        }
    }
    return 0;
}