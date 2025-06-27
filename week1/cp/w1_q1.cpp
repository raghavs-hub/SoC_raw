#include<bits/stdc++.h>
using namespace std;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;cin >> n;
set<int> s;

for(int i=0;i<n-1;i++){
    int x;
    cin >> x;
    s.insert(x);
}
for(int i=1;i<=n;i++){
    if(!(bool)s.count(i)){
        cout << i;
        break;
    }
}

}