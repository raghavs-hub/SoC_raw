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

ll gridpaths(int n, vector<vi> grid){
    vector<vi> ways(n+1,vi(n+1,0));
    if(grid[0][0] == 1) return 0;
    ways[1][1]=1;
    f(0,n,x){
        f(0,n,y){
            if(x==0 && y==0) continue;
            if(grid[x][y] == 1) ways[x+1][y+1] = 0;
            else{
                ways[x+1][y+1] = (ways[x][y+1] + ways[x+1][y])%1000000007;
            }
            //printf("ways[%i][%i] = %i\n", x+1,y+1,ways[x+1][y+1]);
        }
    }
    return ways[n][n];
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;cin >> n;
vector<vi> grid(n,vi(n,0));
f(0,n,i){
    f(0,n,j){
        char a;cin >> a;
        if(a=='*') grid[i][j] = 1;
    }
}
cout << gridpaths(n,grid) << nl;
}