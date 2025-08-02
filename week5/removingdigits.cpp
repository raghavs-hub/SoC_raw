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

set<int> digits(int n){
    set<int> s;
    while(n!=0){
        s.insert(n%10);
        n /= 10;
    }
    return s;
}

int remdig(vi& memo, int n){
    if(n == 0) return 0;
    else if(memo[n] != -1) return memo[n];
    else{
        memo[n]=n+1;
        set<int> s = digits(n);
        for(auto x:s) memo[n] = min(memo[n],1+remdig(memo,n-x));
        //printf("memo[%i] calculated as %i\n",n,memo[n]);
        return memo[n];
    }
}



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;
cin >> n;
vi memo(n+1,-1);
cout << remdig(memo,n) << nl;



}