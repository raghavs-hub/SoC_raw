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

void p4(int n){
    for(int k=0;k<n;k+=4){
        printf("%i %i %i %i ",k+2,k+4,k+1,k+3);
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;cin >> n;
if(n==1){
    cout << 1;
}else if(n<4){
    cout << "NO SOLUTION";
}else if(n%4==0){
    p4(n);
}else if(n%4==1){
    p4(n-1);
    printf("%i",n);
}else if(n%4==2){
    printf("%i ",n);
    p4(n-2);
    printf("%i",n-1);
}else{
    printf("%i ",n-1);
    p4(n-3);
    printf("%i %i",n-2,n);
}

}