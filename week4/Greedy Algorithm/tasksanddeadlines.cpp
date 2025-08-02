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

int n;
cin >> n;
ll dsum = 0;
ll asum = 0;
vector<ll> as(n);
f(0,n,p){
    cin >> as[p];
    ll d; cin >> d;
    dsum += d;
}
sort(as.begin(),as.end());
asum = as[0];
f(1,n,i){
    as[i] += as[i-1]; 
    asum += as[i];
}
cout << dsum - asum;

}