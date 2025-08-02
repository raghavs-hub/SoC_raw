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

int editdist(string a, string b){
    int m=a.length();
    int n=b.length();
    vector<vi> thetable(m+1,vi(n+1,0));
    f(1,m+1,x) thetable[x][0] = x;
    f(1,n+1,y) thetable[0][y] = y;
    f(1,m+1,x){
        f(1,n+1,y){
            int c = (a[x-1]==b[y-1])?0:1; 
            thetable[x][y] = min(thetable[x-1][y]+1,thetable[x][y-1]+1);
            thetable[x][y] = min(thetable[x][y],thetable[x-1][y-1]+c);
        }
    }
    return thetable[m][n];
}



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

string a,b;
cin >> a >> b;

cout << editdist(a,b) << nl;
}