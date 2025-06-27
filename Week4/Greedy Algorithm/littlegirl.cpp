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

void printarr(int arr[], int n){
    f(0,n,i) cout << arr[i] << " ";
    cout << nl;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

map<int,int> indocu;
int n,q;cin >> n >> q;
int arr[n] = {0};
int occ[n] = {0};
f(0,n,i) cin >> arr[i];
sort(arr,arr+n,greater<int>());
int d[n] = {0};
f(0,q,i){
    int l,r;cin >> l >> r;
    d[l-1]++;d[r]--;
}
occ[0] = d[0];
f(1,n,i) occ[i] = occ[i-1] + d[i];
sort(occ,occ+n,greater<int>());
ll sum = 0;
f(0,n,w){
    sum += 1LL*arr[w]*occ[w];
}
cout << sum;
}