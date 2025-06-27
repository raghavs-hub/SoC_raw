#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int luckiness(int n){
    int maxm = n%10, minm = n%10;
    for(int t=n;t>0;t/=10){
        maxm = max(t%10,maxm);
        minm = min(t%10,minm);
    }
    return maxm-minm;
}

int main()
{
ios::sync_with_stdio(0); cin.tie(0);

int t; cin >> t;



for(int x=0;x<t;x++){
    int l,r;
    cin >> l >> r; 
    if(r-l > 79 && l > 9){
        if(l%100 > 9 and l%100 <= 90) cout << l + 90 - l%100 << "\n";
        else if(l%100 > 90) cout << l+109-l%100 << "\n";
        else cout << l+9-l%100 << "\n"; 
    } else{
        int best=l;
        int luck_best = luckiness(l);
        for(int i=l;i<r+1;i++){
            best = (luck_best < luckiness(i))?(luck_best=luckiness(i), i):best;
            if(luck_best == 9) break;
        }
        cout << best << "\n";
    }


}
}