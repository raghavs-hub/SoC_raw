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

int cutrect(int a,int b){
    if(a==b) return 0;
    int table[a+1][b+1] = {0};
    f(1,a+1,i) table[i][1] = i-1;
    f(1,b+1,j) table[1][j] = j-1;

    f(1,a+1,i){
        f(1,b+1,j){
            if(i==j) table[i][j] = 0;
            else{
            int minsum=2*(max(i,j))+1;
            f(1,i/2+1,x) minsum=min(minsum,table[x][j]+table[i-x][j]+1);
            f(1,j/2+1,y) minsum=min(minsum,table[i][y]+table[i][j-y]+1);
            table[i][j] = minsum;}
            //printf("table[%i][%i] : %i\n",i,j,table[i][j]);
        }
    }
    return table[a][b];

}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);


int a,b;
cin >> a >> b;
cout << cutrect(a,b)<<nl;
}