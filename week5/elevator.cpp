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


bool isgoodsubset(int subset, ll elevatorsize, vll weights){
    ll sum=0;
    ll min=1e9+1;
    bool minnotfound=true;
    int i=0;
    for(int i=0;subset != 0;i++,subset >>= 1){
        if(subset&1) {
            sum+=weights[i];
            if(sum > elevatorsize) return false;
        }
        else if(minnotfound){
            min=weights[i];
            minnotfound=false;
        }
        
    }
    if(elevatorsize-sum >= min) return false;
    else return true;
}

int minturns(int subsetrem,vll weights, ll elevatorsize){
    vll remweights(0);
    int n=0;
    for(int i=0;subsetrem != 0;i++,subsetrem >>= 1){
        if(subsetrem & 1) {
            remweights.PB(weights[i]);
            n <<= 1;n++;
        }
    }
    int size=remweights.size();
    int ways=size;
    f(1,n+1,i){
        if(isgoodsubset(i,elevatorsize,remweights)){
            ways=min(ways,1+minturns(n-i,remweights,elevatorsize));
        }
    }
    return ways;

}



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
getint(n);
getll(x);
int tmp=0;
vll weights(n);
f(0,n,i){
    cin >> weights[i];
    tmp <<= 1;
    tmp |= 1;
}
sort(weights.begin(),weights.end());

cout << minturns(tmp,weights,x) << nl;


}