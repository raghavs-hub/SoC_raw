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


string minimalpath(int n,int x, int y,vector<vector<char>>& grid){
    if(x==n && y==n) return string(1,grid[n][n]);
    string s="";
    if(x==n){
        f(y,n+1,i) s+=grid[n][i];
        return s;
    } else if(y==n){
        f(x,n+1,i) s+=grid[i][n];
        return s;
    }
    else{
        while(x!=n && y!=n){
            if(grid[x][y+1] > grid[x+1][y]){
            }
        }
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);



}