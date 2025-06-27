#include<bits/stdc++.h>
using namespace std;
int main()
{
ios::sync_with_stdio(0); cin.tie(0);

int t; cin >> t;
int a,b;
for(int i=0;i<t;i++){
    cin >> a >> b;
    if(a>=b) swap(a,b);
    if(b>2*a) cout<<"NO"<<"\n";
    else if((2*a-b)%3==0) cout << "YES" << "\n";
    else cout << "NO" <<"\n";  
}

}
