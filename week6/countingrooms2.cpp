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


void deleteroom(vector<vector<char>>& grid,int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m) return;
    else if(grid[i][j] != '.') return;
    else{
        //printf("grid character at %i, %i set to #\n",i,j);
        grid[i][j] = '#';
        deleteroom(grid,i+1,j,n,m);
        deleteroom(grid,i,j-1,n,m);
        deleteroom(grid,i-1,j,n,m);
        deleteroom(grid,i,j+1,n,m);
    }
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

getint(n);
getint(m);

vector<vector<char>> grid(n,vector<char>(m));
vi x,y;

f(0,n,i){
    f(0,m,j){
        cin >> grid[i][j];
        if(grid[i][j]=='.'){
            x.PB(i);
            y.PB(j);
        }
    }
}

int i=0;
int rooms=0;
while(i<x.size()){
    if(grid[x[i]][y[i]] == '.'){
        deleteroom(grid,x[i],y[i],n,m);
        rooms++;
        //printf("one room added due to deletion of . at %i,%i\n",x[i],y[i]);
    }
    i++;
}

cout << rooms << nl;

}