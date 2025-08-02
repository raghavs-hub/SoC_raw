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


ll greed(ll n){
    if(n==1 || n==2) return 1;
    else if(n==3) return 2;
    else if(n==4) return 3;
    else if(n%2 != 0){
        return n-greed(n-1);
    } else{
        if(n%4 == 0){
            return 1+greed(n-2);
        } else{
            return n/2+greed(n/2-1);
        }
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

test{
    ll n;cin >> n;
    cout << greed(n) << nl;
}

}