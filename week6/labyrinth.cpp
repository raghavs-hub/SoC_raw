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

bool isvalid(int x,int y,int n,int m){
    if(x>=n || x<0 || y<0 || y>=m) return false;
    else return true;
}

int shortestpath(pii start,pii end,vector<vector<char>> grid,vector<vector<bool>>& visited,string& str){
    if(start == end) return 0;
    if(!isvalid(start.first,start.second,grid.size(),(grid[0]).size())) return 1e7;
    if(visited[start.first][start.second]) return 1e7;
    visited[start.first][start.second] = true;
    int tmp = 0;
    string str1="",str2="",str3="",str4="";
    int var1 = shortestpath({start.first-1,start.second},end,grid,visited,str1);
    int var2 = shortestpath({start.first+1,start.second},end,grid,visited,str2);
    int var3 = shortestpath({start.first,start.second-1},end,grid,visited,str3);
    int var4 = shortestpath({start.first,start.second+1},end,grid,visited,str4);
    //printf("for start = {%i, %i} the strs are %s, %s, %s, %s\n",start.first,start.second,str1,str2,str3,str4);
    //cout << "for start = {" << start.first << ", " << start.second << "} the vars are " << var1 << ", " << var2 << ", " << var3 << ", " << var4 << nl;

    tmp = min({var1,var2,var3,var4});
    if(tmp == var1) str = "U"+str1;
    else if(tmp == var2) str = "D"+str2;
    else if(tmp==var3) str = "L"+str3;
    else if(tmp==var4) str = "R"+str4;
    cout << "for start = {" << start.first << ", " << start.second << "} the min path is " << tmp+1 << nl;
    return tmp+1;
}



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin >> n >> m;
vector<vector<char>> grid(n,vector<char>(m));
vector<vector<bool>> visited(n,vector<bool>(m,true));
pii start,end;

f(0,n,i){
    f(0,m,j){
        cin >> grid[i][j];
        if(grid[i][j]=='A'){
            start.first = i;
            start.second = j;
            visited[i][j] = false;
        } if(grid[i][j]=='B'){
            end.first = i;
            end.second = j;
            visited[i][j] = false;
        } if(grid[i][j]=='.'){
            visited[i][j] = false;
        }
    }
}
//cout << start.first << " " << start.second << nl;
string s = "";
int len = shortestpath(start,end,grid,visited,s);

if(len >=1e7){
    cout << "NO" << nl;
} else{
    cout << "YES" << nl;
    cout << len << nl;
    cout << s << nl;
}

}