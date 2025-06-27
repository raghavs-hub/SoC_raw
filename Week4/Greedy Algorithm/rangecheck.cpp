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
#define setIO(inputFile, outputFile) freopen(inputFile, "r", stdin); freopen(outputFile, "w", stdout)


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
set<pair<pair<ll,ll>,int>> myset;
//freopen("input.txt","r",stdin);

int n; cin >>n;
vi contained(n,0);
vi contains(n,0);
f(0,n,j){
    ll x,y;
    cin >> x >> y;
    myset.insert({{x,y},j});
}
for(auto it = myset.begin();it != (--myset.end());it++){
    if((it->first).first == (next(it)->first).first) {contained[it->second] = 1; contains[next(it)->second];}
    if(contains[it->second] == 0){
        auto it2 = next(it);
        while(it2 != myset.end() && (it2->first).first <= (it->first).second){
            if((it2->first).second <= (it->first).second){
                contains[it->second] = 1;
                contained[it2->second] = 1;
                break;
            } it2 = next(it2);
        }
    }
}

for(auto it = myset.rbegin();it != (--myset.rend());it++){
    //cout << "( " << (it->first).first << " , " << (it->first.second) << " ) -> " << it->second << nl;
    if((it->first).first == (next(it)->first).first) {contains[it->second] = 1; contained[next(it)->second];}
    if(contained[it->second] == 0){
        auto it2 = next(it);
        while(it2 != myset.rend()){
            if((it2->first).second >= (it->first).second){
                contained[it->second] = 1;
                break;
            } it2 = next(it2);
        }}
}

f(0,n,i){
    cout << contains[i] << " ";
}cout << nl;
f(0,n,i){
    cout << contained[i] << " ";
}cout << nl;
}