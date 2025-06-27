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

int n;cin>> n;
char arr[n] = {0};
map<char,vi> mymap;
mymap['1'] = mymap['2'] = mymap['0'] = {};
int sizes[3] = {0};
f(0,n,i){
    cin >> arr[i];
    mymap[arr[i]].PB(i);
    sizes[arr[i]-'0']++;
}
int replacements=0;
int counters[3] = {0};
if(sizes[0] <= n/3){
    if(sizes[1] <= n/3){
        while(sizes[0] != n/3){
        arr[mymap['2'][counters[2]++]] = '0';
        sizes[0]++;
        replacements++;
        } while(sizes[1] != n/3){
        arr[mymap['2'][counters[2]++]] = '1';
        sizes[1]++;
        replacements++;
        }
    } else{
        if(sizes[2] <= n/3){
        while(sizes[0] != n/3){
        arr[mymap['1'][counters[1]++]] = '0';
        sizes[0]++;
        replacements++;
        } while(sizes[2] != n/3){
        arr[mymap['1'][counters[1]++]] = '2';
        sizes[2]++;
        replacements++;
        }
        } else{
        while(sizes[1] != n/3){
        arr[mymap['1'][counters[1]++]] = '0';
        sizes[1]--;
        replacements++;
        } while(sizes[2] != n/3){
        arr[mymap['2'][counters[1]++]] = '0';
        sizes[2]--;
        replacements++;
        }
        }
    }
} else{
    
}


}
