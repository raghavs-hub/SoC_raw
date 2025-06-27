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
ll m,n;
cin >> n >> m;
ll tmp1 = n/m;

cout << ((n%m)*(tmp1)*(tmp1+1))/2 + ((m-(n%m))*(tmp1)*(tmp1-1))/2 << " "; 

cout << ((n-m+1)*(n-m))/2;
}