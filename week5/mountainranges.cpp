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
/*
func(int n, arr[n]){
    for(0 to n-1){
        ways
    }
}


int mountains(int n, int arr[]){
    int maxend[n];
    f(0,n,i){
        int maxmountain=arr[i];
        maxend[i]=1;
        for(int l = i-1;l>=0;l--){
            if(maxmountain<=arr[l]){
                maxend[i] = max(maxend[i],maxend[l]+1);
                maxmountain=arr[l];
                //printf("new max for i= %i and h= %i at l= %i and height= %i and maxend = %i\n",i,arr[i],l,arr[l],maxend[i]);
            }
            //printf("maxend[%i] = %i at l = %i\n",i,maxend[i],l);
        }
    }
    int ans=0;
    f(0,n,i) ans = max(ans,maxend[i]);
    return ans;
}

*/

int right_mountains(int n,int arr[]){
    int right[]
    int maxm=0;
    int maxh=arr[n];
    for(int i=n-2;i>=0;i--){
        if(arr[i]<=arr[i+1]);
        else if(arr[i]>maxh){
            maxm = n-1-i;
            maxh=arr[i];
        } else{
            int l=i+1;
            while(arr[l]<arr[i]) l++;
            maxm = max(maxm,l-i-1);
        }
    }
    return maxm;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;cin >> n;
int arr[n];
f(0,n,i) cin >>arr[i];

int rmax = right_mountains(n,arr);
//reverse(arr,arr+n);
//int lmax = right_mountains(n,arr);
cout << rmax << nl;
}