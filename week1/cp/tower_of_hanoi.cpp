#include<bits/stdc++.h>
using namespace std;

void move(int n,int x=1, int y=3){
    if(n==0){}
    else{
    move(n-1,x,6-x-y);
    cout << x <<" " <<y << "\n";
    move(n-1,6-x-y,y);}
}
int moves(int n){
    if(n==1) return 1;
    else return 2*moves(n-1)+1;
}

int main()
{
ios::sync_with_stdio(0); cin.tie(0);

int n;cin >> n;
cout << moves(n) << "\n";
move(n);


}