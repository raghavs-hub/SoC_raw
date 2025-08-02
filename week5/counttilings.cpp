#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef set<long long> sll;
typedef vector<long long> vll;


#define test int t;cin >> t;for(int z=0;z<t;z++)
#define getint(name) int name;cin >> name;
#define getll(name) long long name;cin >> name;
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)



vi generatemasks(int mask,int n,map<pii,vi>& prevdata){
    if(n == 0){
    if(mask == 0) return {0};
    else return {};
}
if(n < 0){
    return {};
}
    if(prevdata.count({mask,n})) return prevdata[{mask,n}];
    else{
        vi toreturn;
        if(mask & 1){
            toreturn=generatemasks(mask >> 1,n-1,prevdata);
            for(auto &x: toreturn){
                x = x << 1;
            }
        } else{
            if((mask >> 1) & 1){
                toreturn=generatemasks(mask >> 1,n-1,prevdata);
                for(auto &x: toreturn){
                    x = (x << 1) | 1;
                }
            } else{
                toreturn=generatemasks(mask >> 2,n-2,prevdata);
                vi tmp = generatemasks(mask >> 1,n-1,prevdata);
                for(auto &x:toreturn){
                    x = x << 2;
                }
                for(auto x:tmp){
                    x= (x << 1) | 1;
                    toreturn.PB(x);
                }
            }
        }
        prevdata[{mask,n}] = toreturn;
        return toreturn;
    }
    
    
}

ll totalways(int mask,int col, int m, int n,map<pii,vi>& maskdata){
    if(col==m+1){
        if(mask==0) return 1;
        else return 0;
    }
    vi nextmasks= generatemasks(mask,n,maskdata);
    ll ans=0;
    for(auto x:nextmasks){
        ans = (ans+totalways(x,col+1,m,n,maskdata))%1000000007;
    }
    return ans;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;
map<pii,vi> maskdata;
maskdata[{1,1}]={0};
maskdata[{0,1}]={1};
maskdata[{0,2}]={0,3};
maskdata[{2,2}]={1};
maskdata[{1,2}]={2};
maskdata[{3,2}]={0};

cout << totalways(0,1,m,n,maskdata) << nl;

}