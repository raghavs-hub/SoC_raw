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

int n,target;
cin >> n >> target;
int c[n];

ll m = 1e9+7;

vector<ll> ways(target+1,0);

f(0,n,i){
    cin >> c[i];
    if(c[i]<=target) ways[c[i]]+=1;
}

f(1,target+1,k){
    f(0,n,i){
        if(k-c[i] > 0){
            ways[k]+=ways[k-c[i]];
        }
    }
    ways[k] = ways[k]%m;
}

cout << ways[target] << nl;



}