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

int n;
cin >> n;
double a[n];
ll sum = 0;
int b[n];
f(0,n,i) {
    cin >> a[i];
    if(a[i]-int(a[i]) != 0){
    if(a[i] >= 0) b[i] = int(a[i]);
    else b[i] = (int(a[i])-1);
    } else b[i] = a[i];
    sum = sum+ll(b[i]);
}

int i=0;
while(sum != 0){
    if(a[i] != double(b[i])){
        b[i] = b[i]+1;
        sum++;
    }
    i++;
}
f(0,n,i) cout << b[i]<<nl;

}