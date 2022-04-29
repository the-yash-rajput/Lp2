//yash rajput
//03-03-2022
#include <bits/stdc++.h>
using namespace std;
#define line cout << "_________________________________________________\n";


void print(int a[],int n){
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}
void selectionSort()
{
    cout<<"Please Enter The Length Of Array: ";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Please Enter the "<<i+1<<" element: ";
        cin>>a[i];
        cout<<'\n';
    }
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index])
                index = j;
        }
        // swapping the element.
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
    print(a,n);
}
int main()
{

    int choice;
    while (1)
    {
        line;
        cout << "Menu" << '\n';
        cout << "1) Selection Sort" << '\n';
        cout << "0) Exit" << '\n';
        line;
        cout<<"Please Enter Your Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            selectionSort();
        }
        else if (choice == 0)
        {
            cout << "Seccessfully Exited :) \n";
            break;
        }
        else
        {
            cout << "Wrong Choise, Please Enter The correct Choice\n";
        }
    }

    return 0;
}