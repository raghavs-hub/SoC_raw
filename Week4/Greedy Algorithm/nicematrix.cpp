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


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

test{
    int r,c;
    cin >> r >> c;
    ll a[r][c];
    f(0,r,i){
        f(0,c,j){
            cin >> a[i][j];
        }
    }
ll operations = 0;
f(0,r/2,i){
    f(0,c/2,j){
        ll temp[4];
        temp[0] = a[i][j];
        temp[1] = a[i][c-1-j];
        temp[2] = a[r-1-i][j];
        temp[3] = a[r-1-i][c-j-1];
        sort(temp,temp+4);
        //cout << temp[0] << " " << temp[1] << " " << temp[2] << " " << temp[3] << nl;
        operations += (temp[3]+temp[2]-temp[1]-temp[0]);
        //cout << operations << endl;
    }
}
if(r%2 != 0){
    int x=(r-1)/2;
    f(0,c/2,j){
        operations+=abs(a[x][j]-a[x][c-1-j]);
    }
}
if(c%2 != 0){
    int y=(c-1)/2;
    f(0,r/2,i){
        operations+=abs(a[i][y]-a[r-1-i][y]);
    }
}
cout << operations << endl;
}

}