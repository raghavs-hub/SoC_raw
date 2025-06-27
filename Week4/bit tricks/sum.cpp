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


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
test{
    ll n,x;
    cin >> n >> x;
    ll rem = n-__builtin_popcount(x);
    if(rem>=0){
    if(rem%2==0) cout << x+rem << nl;
    else{
        if(n>1) cout << x+rem+3 << nl;
        else cout << -1 << nl;;
    }} else{
        cout << x << nl;
    }
}

}