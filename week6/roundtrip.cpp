#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef set<long long> sll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;


#define test int t;cin >> t;for(int z=0;z<t;z++)
#define getint(name) int name;cin >> name;
#define getll(name) long long name;cin >> name;
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)


bool iterativedf(vvi& adjlist,int n,vector<bool>& visited,vi& theseq,int start){
    stack<int> thestack;
    vector<int> parents(n+1,-1);
    thestack.push(start);
    parents[start] = 0;
    while(thestack.size() != 0){
        int x = thestack.top();
        visited[x] = true;
        //cerr << "running for x = " << x << nl;;
        thestack.pop();
        for(auto y:adjlist[x]){
            //cerr << "running for x = " << x << " and for y = " << y << nl;
            if(visited[y] && parents[x] != y){
                int l =x;
                theseq.PB(y);
                while(l != y){
                    theseq.PB(l);
                    l = parents[l];
                }
                theseq.PB(y);
                return true;
            } else if(!visited[y]){
                thestack.push(y);
                //visited[y] = true;
                parents[y] = x;
            }
        }
    }
    return false;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;

vvi adjlist(n+1);
int a,b;
f(0,m,i){
    cin >> a >> b;
    adjlist[a].PB(b);
    adjlist[b].PB(a);
}
vector<bool> visited(n+1,false);
vi theseq;
bool tmp=false;
f(1,n+1,i){
    //cerr << 'c';
    if(!visited[i] && adjlist[i].size() != 0){
        if(iterativedf(adjlist,n,visited,theseq,i)){
            cout << theseq.size() << nl;
            for(int x=0,p=theseq.size();x<p;x++) cout << theseq[x] << " ";
            cout << nl;
            tmp = true;
            break;
        }
    }
}
if(!tmp) cout << "IMPOSSIBLE" << nl;

}