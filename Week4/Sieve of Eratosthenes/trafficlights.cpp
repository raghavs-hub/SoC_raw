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

ll x; int n;
cin >> x >> n;

set<ll> p = {0,x};
multiset<ll> partitions = {x};
ll p1;
f(0,n,i){
    cin >> p1;
    ll low = *(--p.lower_bound(p1));
    ll up = *(p.upper_bound(p1));
    p.insert(p1);
    if(up-low >= x/n){
    auto it = partitions.find(up-low);
    partitions.erase(it,next(it,1));
    if(up-p1 >= x/n) partitions.insert(up-p1);
    if(p1-low >= x/n) partitions.insert(p1-low);}
    cout << *(--partitions.lower_bound(x)) << " ";
}


}