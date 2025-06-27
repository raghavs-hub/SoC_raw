#include<bits/stdc++.h>
using namespace std;

void insertionsort(int* A,int n){
if(n==1){return;}
else{
    insertionsort(A,n-1);
    int ins = A[n-1];
    int i=n-2;
    for(;(i>=0 && A[i] > ins);i--){
        A[i+1] = A[i];
    }
    A[i+1] = ins;
    return;
}
}

void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int A[] = {2,6,4,32,4,67,89,78,56,10,25,49};
int n=sizeof(A)/sizeof(int);
printarr(A,n);
insertionsort(A,n);
printarr(A,n);
}