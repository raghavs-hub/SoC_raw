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
vector<vi> times;
int rooms[n];
int a,b;
f(0,n,i){
    cin >> a >> b;
    times.PB({a,0,i});
    times.PB({b,1,i});
}
sort(times.begin(),times.end());
int roomsreq = 0;
int crntreq = 0;
f(0,2*n,i){
    if(times[i][1] == 0){
        crntreq++;
        roomsreq = max(roomsreq,crntreq);
    } else{
        crntreq--;
    }
}
cout << roomsreq << nl;
stack<int> roomsavl;
f(0,roomsreq,i){
    roomsavl.push(i+1);
}

map<int,int> allocs;
f(0,2*n,i){
    if(times[i][1] == 0){
        int allot = roomsavl.top();
        roomsavl.pop();
        allocs[times[i][2]] = allot;
        rooms[times[i][2]] = allot;
    } else{
        int emp = allocs[times[i][2]];
        roomsavl.push(emp);
    }
}
f(0,n,i){
    cout << rooms[i] << " ";
}cout << endl;
}