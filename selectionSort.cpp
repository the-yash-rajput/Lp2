// Selection

#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int arr[],int n){
    int i,j,k;
    for(int i=0;i<n-1;i++){
        k=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        swap(arr[i],arr[k]);
    }
}
void display(int arr[],int n){
    cout<<"Array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of elements in array->";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements with a space in between"<<endl;
    for(int i=0;i<n;i++){
        
        cin>>arr[i];
    }
    display(arr,n);
    SelectionSort(arr,n);
    cout<<"After sorting ";
    display(arr,n);
    return 0;
}