#include<bits/stdc++.h>
using namespace std;
int main()
{
ios::sync_with_stdio(0); cin.tie(0);

int t; cin >> t;
long long a,b,c,d,moves;

for(int i=0;i<t;i++){
    moves=0;
    cin >> a >> b >> c >> d;
    if(b>d) {cout << -1;}
    else {
        moves+=d-b;
        if(c>a+d-b){cout << -1;}
        else cout << a+d-b-c+moves;
    }
    cout << "\n";
}
}