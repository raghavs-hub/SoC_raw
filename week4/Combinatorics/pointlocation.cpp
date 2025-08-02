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
    int x[3];
    int y[3];
    f(0,3,i){
        cin >> x[i];
        cin >> y[i];
    }
    pair<ll,ll> p1 = {x[1]-x[0],y[1]-y[0]};
    pair<ll,ll> p2 = {x[2]-x[0],y[2]-y[0]};

    ll c1 = p2.first*p1.second;
    ll c2 = p2.second*p1.first;
    if(c1 > c2){
        cout << "RIGHT" << nl;
    } else if(c1 == c2){
        cout << "TOUCH" << nl;
    } else{
        cout << "LEFT" << nl;
    }
}

}