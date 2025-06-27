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
int arr[n];
f(0,n,i) cin >> arr[i];
sort(arr,arr+n,greater<int>());
ll beauty = 0;
int power = 0;
int n1 = n;
while(n1 != 1){
    n1 /= 4;
    power++;
} power++;
beauty += (ll)power*arr[0];
power--;

int num=3;
int current = 1;
while(power != 0){
    for(int i=0;i<num;i++){
        beauty += (ll)power*arr[i+current];
    }
    current+=num;
    num*=4;
    power--;
}
cout << beauty;

}