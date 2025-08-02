#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef set<long long> sll;
typedef vector<long long> vll;


#define test int t;cin >> t;for(int z=0;z<t;z++)
#define getint(name) int name;cin >> name;
#define getll(name) long long name;cin >> name;
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)

void deleteusingdfs(map<pii,vi>& thelist,pii ref,int n){
    if(thelist.count(ref) == 0) return;
    vi nextones = thelist[ref];
    thelist.erase(ref);
    for(auto x: nextones){
        if(x%n==0){
            deleteusingdfs(thelist,{x/n,n},n);
        } else{
            deleteusingdfs(thelist,{x/n+1,x%n},n);
        }
    }
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
getint(n);
getint(m);

//vector<vi> adjlist;
int rooms=0;
char plan[n][m];
map<pii,vi> adjlist;
f(0,n,i){
    f(0,m,j){
        cin >> plan[i][j];
        if(plan[i][j]=='.') adjlist[{i+1,j+1}] = {i*m+j+1};
    }
}
/*

for(auto p: adjlist){
    cout << p.first.first << " , " << p.first.second << " -> ";
    for(auto x: p.second) cout << x << " ";
    cout << nl;
}
*/

for(auto it=adjlist.begin();it != adjlist.end();it++){
    int x = (it->first).first;
    int y = (it->first).second;
    vector<pii> tmp = {{x,y-1},{x-1,y},{x,y+1},{x+1,y}};
    for(auto p: tmp){
        if(adjlist.count(p)) adjlist[p].PB((x-1)*m+y);
    }
}





while(adjlist.size() != 0){
    auto it = adjlist.begin();
    deleteusingdfs(adjlist,it->first,m);
    rooms++;

}

cout << rooms << nl;




}