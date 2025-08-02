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

ll factorial(vector<ll>& v,int n){
    if(n==0 || n==1) return 1;
    else if(v[n] != 1) return v[n];
    else{
        v[n] = n*factorial(v,n-1);
        return v[n];
    }
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
vector<ll> factorials(21,1);
int x;
test{
    cin >> x;
    int n;
    cin >> n;
    set<int> theset;
    f(1,n+1,i) theset.insert(i);
    if(x==1){
        ll k;
        cin >> k;
        for(int i = n-1;i>=0;i--){
            int p = (k-1)/factorial(factorials,i);
            if(k==0){
                for(auto it = theset.rbegin();it != theset.rend();++it){
                    cout << *it << " ";
                }
                break;
            }
            p = *(next(theset.begin(),p));
            cout << p << " ";
            theset.erase(p);
            k = k%factorial(factorials,i);
        } cout << nl;
    } else{
        ll k=1;
        int l;
        f(0,n,j){
            cin >> l;
            int p = distance(theset.begin(),theset.find(l));
            theset.erase(l);
            k += p*factorial(factorials,n-1-j);
        }
        cout << k << nl;
    }
}


}