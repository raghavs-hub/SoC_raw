#include<bits/stdc++.h>
using namespace std;

long long two_knight(int n){
    long long attacking = 1LL*4*(n-1)*(n-2);
    return 1LL*pow(n,2)*(pow(n,2)-1)/2 - attacking;
}

int main()
{
ios::sync_with_stdio(0); cin.tie(0);

int n; cin >> n;
for(int i=0;i<n;i++){
    cout << two_knight(i+1) << "\n";
}

}