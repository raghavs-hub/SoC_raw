#include<bits/stdc++.h>
using namespace std;
int main()
{

ios::sync_with_stdio(0);
cin.tie(0);

string s;
cin >> s;
int best=1;
int current=1;
for(int i=1,n=s.size();i<n;i++){
    if(s[i] == s[i-1]){
        current++;
        best = max(best,current);
    } else{
        best = max(best,current);
        current=1;
    }
}
cout << best;
}