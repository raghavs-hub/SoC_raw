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

set<pair<pair<ll,ll>,int>> myset;
multiset<int> ends;
int n; cin >>n;
int contained[n];
int contains[n];

f(0,n,j){
    ll x,y;
    cin >> x >> y;
    myset.insert({{x,y},j});
    ends.insert(y);
    contains[j] = contained[j] = 0;
}
multiset<int> ends1(ends);
for(auto it = myset.begin();it != (--myset.end());it++){
    if((it->first).first == (next(it)->first).first) {contains[next(it)->second]+=(contains[it->second]+1);}
    ends.erase(ends.find((it->first).second));
    contains[it->second] += distance(ends.begin(),ends.upper_bound((it->first).second));
}

for(auto it = myset.rbegin();it != (--myset.rend());it++){
    if((it->first).first == (next(it)->first).first) {contained[next(it)->second]+=(contained[it->second]+1);}
    ends1.erase(ends1.find((it->first).second));
    contained[it->second] += distance(ends1.lower_bound((it->first).second),ends1.end());
}

f(0,n,i){
    cout << contains[i] << " ";
}cout << nl;
f(0,n,i){
    cout << contained[i] << " ";
}cout << nl;

}