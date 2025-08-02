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


int binsearch(int high,int low,vi arr,int ref){
    if(high==low) return high;
    int middle = (high+low)/2;
    if(ref == arr[middle]) return middle;
    else if(ref>arr[middle]) return binsearch(high,middle+1,arr,ref);
    else return binsearch(middle,low,arr,ref);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;cin >> n;
vi v(n);
f(0,n,i) cin >> v[i];
int size=1;
vi myvec={v[0]};

f(1,n,k){
   if(v[k]>myvec[size-1]){
    size++;
    myvec.PB(v[k]);
   } else{
    int a = binsearch(size-1,0,myvec,v[k]);
    myvec[a] = v[k];
   }
   //f(0,size,p) cout << myvec[p] << " ";
   //cout << nl;
}
cout << size << nl;

}