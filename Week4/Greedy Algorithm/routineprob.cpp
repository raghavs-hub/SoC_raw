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


int gcd(int a,int b){
    if(a==0) return b;
    else return gcd(b%a,a);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int a,b,c,d;
cin >> a >> b >> c >> d;
int g1 = gcd(a*d,b*c);
if(a*d>b*c){
    cout << (a*d-b*c)/g1 << "/" << (a*d)/g1;
} else{
    cout << (b*c-a*d)/g1 << "/" << (b*c)/g1;
}

}