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

int n,a; cin >> n;
vector<pii> house;
f(0,2*n,j){
    cin >> a;
    house.PB({a,j});
}
sort(house.begin(),house.end());
ll walk = house[0].second+house[1].second;
pii prev = {house[0].second,house[1].second};
for(int i =2;i<2*n;i+=2){
    //cout << "( " << house[i].first << " , " << house[i].second << " )\n";
    //cout << "( " << house[i+1].first << " , " << house[i+1].second << " )\n";
    walk+=((ll)abs(prev.first-house[i].second)+(ll)abs(house[i+1].second-prev.second));
    prev = {house[i].second,house[i+1].second};
}
cout << walk;

}