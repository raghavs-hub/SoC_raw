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
test{
cin >> n;
vector<pii> numbers;

f(0,n,i){
    int a;
    cin >> a;
    numbers.PB({a,i});
}
sort(numbers.begin(),numbers.end());
int minsz = n;
pii prev = numbers[0];

f(1,n,i){
    if(prev.first == numbers[i].first) minsz = min(minsz,(numbers[i].second-prev.second));
    prev = numbers[i];
    if(minsz == 1) break;
}
if(minsz != n) cout << (minsz+1) << nl;
else cout << -1 << nl;
}
}