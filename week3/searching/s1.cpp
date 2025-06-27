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

int bin_search(int a[],int low,int high,int key){
    if(low > high) return -1; // the base case

    int mid = (low+high)/2;

    if(a[mid]==key) return mid;
    else if(a[mid]>key) return bin_search(a,low,mid-1,key);
    else return bin_search(a,mid+1,high,key);
}

int bin_search_without_n(int a[],int key){
    int p=1;
    while(a[2*p] < key){
        p *= 2;
    }
    return bin_search(a,p,2*p,key);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

}