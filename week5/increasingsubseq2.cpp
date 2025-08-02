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

ll all(int n,vector<ll> arr,ll m){
    vector<ll> answers(n,1);
    ll sum=0;
    f(0,n,i){
        for(int y=i-1;y>=0;y--){
            if(arr[y]<arr[i]) answers[i] = (answers[i]+answers[y])%m;
        }
        sum = (sum+answers[i])%m;
    }
    return sum;
    
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin >> n;
ll m =1e9+7;
vector<ll> thearr(n);
f(0,n,i) cin >> thearr[i];
cout << all(n,thearr,m) << nl;

}