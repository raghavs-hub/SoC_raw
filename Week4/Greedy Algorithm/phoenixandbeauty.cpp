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

test{
    int n,k;cin >> n >> k;
    int a[n];
    set<int> s;
    f(0,n,i) {cin >> a[i];s.insert(a[i]);}
    int m = s.size();
    if(m>k) cout << -1 << nl;
    if(m == k){
        cout << k*n << nl;
        f(0,n,i){
            for(auto it = s.begin();it != s.end();it++){
                cout << *(it) << " ";
            }
        } cout << nl;
    }else {
        cout << k*n <<nl;
        f(0,n,i){
            for(auto x:s){
                cout << x << " ";
            }
            f(0,k-m,j) cout << *(s.begin()) << " ";
        } cout << nl;
    }

}
}