#include<bits/stdc++.h>
using namespace std;
int main()
{
ios::sync_with_stdio(0); cin.tie(0);

int n; cin >> n;
long long prev,now;
cin >> prev;
long long moves=0;
for(int i=0;i<n-1;i++){
    cin >> now;
    if(now>=prev) {
        prev=now;
        continue;
    } else{
        moves+=prev-now;
    }
}
cout << moves << "\n";
}