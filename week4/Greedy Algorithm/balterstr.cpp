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

template <typename T>
void printarr(T arr[], int n){
    f(0,n,i){
        cout << arr[i] << " ";
    }cout << nl;
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;cin>> n;
char arr[n] = {0};
int sizes[3] = {0};
f(0,n,i){
    cin >> arr[i];
    sizes[arr[i]-'0']++;
}
//printarr<char>(arr,n);
int replacements=0;
//printarr<int>(sizes,3);
f(0,3,j){
    sizes[j]-=n/3;
}
//printarr<int>(sizes,3);
f(0,n,i){
    if(sizes[arr[i]-'0']>0){
        if(arr[i] == '1' && sizes[0] < 0){
            arr[i]='0';
            sizes[1]--;sizes[0]++;
        }
        else if(arr[i] == '2'){
            if(sizes[0] < 0){
                arr[i]='0';
                sizes[0]++;
            } else{
                arr[i]='1';
                sizes[1]++;
            }
            sizes[2]--;
        }
    }
}
for(int i=n-1;i>=0;i--){
    if(sizes[arr[i]-'0'] > 0){
        if(arr[i] == '1'){
            arr[i] = '2';
            sizes[1]--;sizes[2]++;
        } else{
            if(sizes[2]<0){
                arr[i] = '2';
                sizes[2]++;
            } else{
                arr[i] = '1';
                sizes[1]++;
            }
            sizes[0]--;
        }
    }
}
f(0,n,i) cout << arr[i];
cout << nl;



}
