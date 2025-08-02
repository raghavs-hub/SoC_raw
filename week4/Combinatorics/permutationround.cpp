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

ll modpow(ll a,ll b,ll m){
    if(b==0) return 1;
    ll u = modpow(a,b/2,m);
    u = u*u%m;
    if(b%2 == 1) u = a*u % m;
    return u;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

ll m = 1e9+7;
int n; cin >> n;
vi thevec;
vi v(n+1,0);
set<int> theset;
f(1,n+1,i){
    cin >> v[i];
    theset.insert(i);
}
while(theset.size() != 0){
    int st = *(theset.begin());
    int i = v[st];
    int round = 1;
    theset.erase(st);
    while(i != st){
        theset.erase(i);
        i = v[i];
        round++;
    }
    thevec.push_back(round);
}
map<int,int> lcm;

f(0,thevec.size(),j){
    map<int,int> temp;
    int cop = thevec[j];
    for(int x = 2; x*x<=cop;x++){
        while(cop%x == 0){
            temp[x]++;
            cop /= x;
        }
    } if(cop > 1) temp[cop]++;
    for(auto p:temp){
        lcm[p.first] = max(p.second,lcm[p.first]);
    }
}
ll ans = 1;
for(auto p:lcm){
    ans = ans*modpow(p.first,p.second,m)%m;
}
cout << ans << nl;

}