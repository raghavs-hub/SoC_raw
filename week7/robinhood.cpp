#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
class my_data_type{
    vector<int> my_bit;
    int n;
    public:
    my_data_type(vector<int> the_vec){
        n = the_vec.size();
        my_bit = vector<int>(n,0);
        for(int i=0;i<n;i++){
            for(int x=i+1;x<=n;x+=(x&(-x))){
                my_bit[x-1]+=the_vec[i];
            }
        }
    }
    void update(int i,int x){
        for(int j=i+1;j<=n;j+=(j&(-j))){
            my_bit[j-1]+=x;
            printf("%i increased by %i to %i\n",j-1,x,my_bit[j-1]);
        }
        
    }
    long long sumtill(int t){
        long long ans=0;
        for(int j=t+1;j>0;j-=(j&(-j))){
            ans+=my_bit[j-1];
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int z;
    cin >> z;
    for(int k=0;k<z;k++){
        cout << "Case " << k+1 << ":\n";
        int n,q;
        cin >> n >> q;
        vector<int> money(n);
        for(int i=0;i<n;i++) cin >> money[i];
        my_data_type a(money);
        for(int i=0;i<q;i++){
            int p,x;
            cin >> p >> x;
            if(p==1) {a.update(x,-money[x]); cout << money[x] << "\n"; money[x]=0;}
            else if(p==2){
                int v; cin >> v;
                money[x]+=v;
                a.update(x,v);
            } else if(p==3){
                int f; cin >> f;
                cout << a.sumtill(f)-a.sumtill(x-1) << "\n";
            }
        }
    }
}


