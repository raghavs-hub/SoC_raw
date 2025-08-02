#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef set<long long> sll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;


#define test int t;cin >> t;for(int z=0;z<t;z++)
#define getint(name) int name;cin >> name;
#define getll(name) long long name;cin >> name;
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)



vi getpow(vi& tpt,map<int,vi>& useful,int x){
    if(x==1) return tpt;
    else if(useful.count(x)) return useful[x];
    else{
        int n=tpt.size()-1;
        vi bef=getpow(tpt,useful,x-1);
        vi ans(n+1);
        ans[0]=0;
        f(1,n+1,i) ans[i] = bef[bef[i]];
        useful[x] = ans;
        return useful[x];
    }
}

void printvec(vi s){
    for(int x:s) cout << x << " ";
    cout << nl;
}

int ans(int x,int k,vi& tpt,map<int,vi>& useful){
    vi tpt1=tpt;
    int i=0;
    while(k != 0){
        i++;
        if(k&1){
            x = tpt1[x];
        }
        k >>= 1;
        tpt1 = getpow(tpt,useful,i+1);
    }
    return x;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,q;
cin >> n >> q;
vi tpt(n+1);
map<int,vi> useful;
tpt[0]=0;
f(1,n+1,i) cin >> tpt[i];
useful[1] = tpt;
f(0,q,z){
    int x,k;
    cin >> x >> k;
    cout << ans(x,k,tpt,useful) << nl;
}


}