#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define test int t;cin >> t;for(int z=0;z<t;z++)
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)

set<int> moneysums(int arr[],int n){
    if(n==1) return {0,arr[0]};
    else{
        set<int> s=moneysums(arr,n-1);
        set <int> tmp={};
        for(auto x:s){tmp.insert(x+arr[n-1]);}
        s.insert(tmp.begin(),tmp.end());
        return s;
    }
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;cin >> n;
int arr[n];
f(0,n,i) cin >> arr[i];
set<int> s = moneysums(arr,n);
s.erase(0);
cout << s.size() << nl;
for(auto it=s.begin();it != s.end();it++){
    cout << *(it) << " ";
}
cout << nl;
}