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

string minpath(int n,vector<vector<char>> grid){
    vector<string> prev(n+1,"~"),curr(n+1,"~");
    f(1,n+1,x){
        f(1,n+1,y){
            if(x==1 && y==1) curr[1] = grid[1][1];
            else{ 
            curr[y] = min(curr[y-1],prev[y])+grid[x][y];}
            //cout << "answers[" << x << "][" << y << "] : " << answers[x][y] << nl;
        }
        prev = curr;
    }
    return curr[n];
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n; cin >> n;
vector<vector<char>> grid(n+1,vector<char>(n+1,'0'));
f(0,n,x) f(0,n,y) cin >> grid[x+1][y+1];

cout << minpath(n,grid)<<nl;

}