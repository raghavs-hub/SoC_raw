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


struct xyt{
    int x,y,t;
};

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int m,n;
cin >> n >> m;
vector<string> lab;

f(0,n,i){
    string s;
    cin >> s;
    lab.push_back(s);
}

int sx,sy;
bool flag=false;
int ex,ey;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vvi timesmon(n,vi(m,-1));
queue<xyt> q1;
f(0,n,i){
    //cerr << 'a';
    f(0,m,j){
        if(lab[i][j]=='M') q1.push({i,j,0});
        if(lab[i][j] == 'A') sx=i,sy=j;
    }
}

while(!q1.empty()){
    auto x = q1.front();
    q1.pop();
    int cx = x.x;
    int cy = x.y;
    int t = x.t;
    //cerr << cx << " and " << cy << " in the queue" << nl;
    timesmon[cx][cy] = t;
    //if(cx<1 || cx>n || cy>n || cy<1 || t != -1) continue;
    //cerr << "timesmon for ( " << cx << ", " << cy << ") is" << t << nl;
    f(0,4,i){
        //cerr << 'd';
        int nx=cx+dx[i],ny=cy+dy[i];
        //cerr << "nx and ny are (" << nx << ", " << ny << ")" <<nl;
        if(nx <0 || ny <0 || nx >= n || ny >= m || lab[nx][ny] == '#' || timesmon[nx][ny] != -1) {continue;}
        timesmon[nx][ny] = t+1;
        //cerr << "nx,ny processed" << nl;
        q1.push({nx,ny,t+1});
    }
    //cerr << "pls" << nl;
}

/*
f(1,n+1,i){
    f(1,m+1,j){
        cout << timesmon[i][j] << " ";
    }
    cout << nl;
}
//cerr << nl;
*/

//vvi timesman(n+2,vi(m+2,-1));
vvi path(n+1,vi(m+1,-1));
path[sx][sy] = -2;

queue<xyt> q2;
q2.push({sx,sy,0});

while(!q2.empty()){
    auto x = q2.front();
    q2.pop();
    int cx = x.x;
    int cy = x.y;
    int t = x.t;
    //cout << "man loop for cx cy = " << cx << ", " << cy <<nl;
    //if(timesmon[cx][cy] != -1 && timesmon[cx][cy] <= t) continue;
    if(cx == n-1 || cy == m-1 || cx == 0 || cy == 0){
        ex=cx,ey=cy;
        flag=true;
        break;
    }
    
    f(0,4,i){
        int nx=cx+dx[i],ny=cy+dy[i];
        //cout << "(nx, ny) = (" << nx << ", " << ny << ")\n";
        if(nx <0 || ny <0 || nx >= n || ny >= m || lab[nx][ny] == '#' || path[nx][ny] != -1 || (timesmon[nx][ny] != -1 && timesmon[nx][ny] <= t+1)) continue;
        path[nx][ny] = i;
        q2.push({nx,ny,t+1});
    }
}
if(!flag) cout << "NO" << nl;
else{
    cout << "YES" << nl;
    int n1=0;
    string s="";
    while(path[ex][ey] != -2){
        int x = path[ex][ey];
        if(x==0){
            s = "D" +s;
            ex--;
        }else if(x==1){
            s = "U"+s;
            ex++;
        }else if(x==2){
            s="R"+s;
            ey--;
        }else if(x==3){
            s="L"+s;
            ey++;
        }
        n1++;
    }
    cout << n1 << nl;
    cout << s << nl;
}


}