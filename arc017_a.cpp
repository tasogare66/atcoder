//https://atcoder.jp/contests/arc017/tasks/arc017_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

bool primeNumber(int n){
    if(n < 2) return false;
    else{
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
}

int main() {
    ll N; cin>>N;    
    cout<<(primeNumber(N)?"YES":"NO")<<endl;
    return 0;
}