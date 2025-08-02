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



ll maxmoney(vector<vector<ll>> all,int x,int n,vector<ll>& maxomoneys){
    if(x>n) return 0;
    if(maxomoneys[x-1] != -1) return maxomoneys[x-1];
    else {//return max(all[x][2]+maxmoney(all,next(all,x),n),maxmoney(all,x+1,n))
        int a=x;
        int inc=1;
        bool plato=false;
        while(inc != 0){
            if(a+inc<=n && all[x][1]>=all[a+inc][0]){
                a+=inc;
                if(!plato) inc=2*inc;
            } else{
                plato=true;
                inc/=2;
            }
        }
            maxomoneys[x-1] = max(all[x][2]+maxmoney(all,a+1,n,maxomoneys),maxmoney(all,x+1,n,maxomoneys));
            return maxomoneys[x-1];
    }
}


ll maxmoney2(vector<vector<ll>> all,int n){
    vector<ll> maxomoneys(n+1,0);
    for(int x=n;x>0;x--){
        int a=x;
        int inc=1;
        bool plato=false;
        while(inc != 0){
            if(a+inc<=n && all[x][1]>=all[a+inc][0]){
                a+=inc;
                if(!plato) inc=2*inc;
            } else{
                plato=true;
                inc/=2;
            }
        }
        maxomoneys[x-1] = max(all[x][2]+maxomoneys[a],maxomoneys[x]);
        //printf("maxmoney from project %i to end is %i",,);

    }
    return maxomoneys[0];
}




int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;cin >> n;
vector<vector<ll>> sep(n+1,vector<ll>(3));
//vector<ll> maxomoneys(n,-1);

f(0,n,i){
    cin >> sep[i+1][0] >> sep[i+1][1] >> sep[i+1][2];
    //maxomoneys[i] = -1;
}
sort(sep.begin(),sep.end());

cout << maxmoney2(sep,n) << nl;


}