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

bool issafe(map<ll,int>& answers, ll n){
    if(answers[n] != 0) return (answers[n]==1)?true:false;
    else if(n%10 != (n/10)%10 && issafe(answers,n/10)) {answers[n] =1;return true;}
    else {answers[n] = 2;return false;}
}



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll a,b;
cin >> a >> b;
map<ll,int> answers;
answers[0] = 1;
ll ans=0;
f(a,b+1,i){
    if(issafe(answers,i)) ans++;
}

cout << ans << nl;

}