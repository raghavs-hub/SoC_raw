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

map<int,int> numind;
int n; cin >> n;
f(0,n,i){
    int a;
    cin >> a;
    numind[a] = i;
}
int rounds=1;
auto en = numind.end();
int crntpos = numind.begin()->second;
for(auto it=++numind.begin();it != en;it++){
    if(crntpos > it->second){
        rounds++;
    }
    crntpos = it->second;
}
cout << rounds << nl;
}