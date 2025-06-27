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

int countPrimes(int n) {
        int x = sqrt(n);
        int primes = 0;
        std::vector<bool> isprime(n,true);
        for(int i=2;i<n;i++){
            if(isprime[i]){
                primes++;
                if((long long)i*i<n){
                for(int j=i*i;j<n;j+=i){
                    isprime[j]=false;
                }}
            }
        }
        return primes;
    }
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

}