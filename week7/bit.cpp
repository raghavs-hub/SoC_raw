#include<bits/stdc++.h>
#include"bit.h"
using namespace std;

class my_data_type{
    vector<int> my_bit;
    int n;
    public:
    my_data_type(vector<int> the_vec){
        n = the_vec.size();
        my_bit = vector<int>(n+1,0);
        for(int i=0;i<n;i++){
            for(int x=i+1;x<=n;x+=(x&(-x))){
                my_bit[x]+=the_vec[i];
            }
        }
    }
    void update(int i,int x){
        for(int j=i+1;j<=n;j+=(j&(-j))){
            my_bit[j]+=x;
        }
    }
    int sumtill(int t){
        int ans=0;
        for(int j=t+1;j>0;j-=(j&(-j))){
            ans+=my_bit[j];
        }
        return ans;
    }
};


