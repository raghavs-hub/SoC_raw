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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m;

bool bfs(vector<string> grid,pii start,pii end,vvi& visited,vvi& dir){
    // int sx=start.first;
    // int sy=start.second;
    // int ex=end.first;
    // int ey=end.second;

    queue<pii> theq;
    theq.push(start);
    while(!theq.empty()){
        auto [cx ,cy] = theq.front();
        if(theq.front() == end) return true;
        theq.pop();
        f(0,4,i){
            int nx=cx+dx[i],ny=cy+dy[i];
            if(nx<0 || ny <0 || nx >= n || ny >= m || grid[nx][ny] == '#' || visited[nx][ny] == 1) continue;
            dir[nx][ny] = i;
            visited[nx][ny] = true;
            theq.push({nx,ny});
        }
    }
    return false;
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);


int sx,sy,ex,ey;
cin >> n >> m;

vector<string> grid;
vvi visited(n,vi(m,0));
vvi dir(n,vi(m,-1));
f(0,n,i){
    string s;
    cin >> s;
    grid.PB(s);
}

f(0,n,i){
    f(0,m,j){
        if(grid[i][j] == 'A')sx=i,sy=j;
        if(grid[i][j]=='B')ex=i,ey=j;
    }
}

if(bfs(grid,{sx,sy},{ex,ey},visited,dir)){
    string s="";
    cout << "YES" << nl;
    while(ex != sx || ey != sy){
        if(dir[ex][ey] == 0){
            s = 'U'+s;
            ex++;
        }else if(dir[ex][ey]==1){
            s = 'D'+s;
            ex--;
        }else if(dir[ex][ey]==2){
            s='L'+s;
            ey++;
        }else if(dir[ex][ey]==3){
            s='R'+s;
            ey--;
        }
    }
    cout << s.size() << nl;
    cout << s << nl;
}else{
    cout << "NO" << nl;
}



}