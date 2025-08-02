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
    int n; cin >> n;
    int arr[4*n];
    f(0,4*n,i){
        cin >> arr[i];
    }
    sort(arr,arr+4*n);
    string ans = "YES";
    int i = 2, j = 4*n-3;
    if(arr[0] != arr[1] || arr[4*n-1] != arr[4*n-2]){
        cout << "NO" << nl;
        continue;
    }
    int area = arr[0]*arr[4*n-1];
    while(j>i+1){
        if(arr[i] != arr[i+1] || arr[j] != arr[j-1] || arr[i]*arr[j] != area){
            ans = "NO";
            break;
        }
        j-=2;
        i+=2;
    }
    cout << ans << nl;

}

}