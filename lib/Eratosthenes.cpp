//エラトステネスの篩
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//素数判定,O(√n)
bool is_prime(const ll n){
    switch(n){
    case 0: // fall-through
    case 1: return false;
    case 2: return true;
    }
    if(n%2 == 0) return false;
    //i=3から奇数のみ調べる
    for(ll i=3;i*i<=n;i+=2){
        if(n%i == 0) return false;
    }
    return true;
}

//エラトステネスの篩
//n以下の素数のリストを返す
auto Eratosthenes(const int n)
{
    vector<ll> result;
    vector<bool> is_prime(n+1,true); //trueで初期化
    for(ll i = 2; i <= n; ++i){
        if (is_prime.at(i)) {
            for(ll j = 2 * i; j <= n; j += i){
                is_prime[ j ] = false;
            }
            result.emplace_back( i );
        }
    }
    return result;
}

int main() {
    auto ret = Eratosthenes(1000);
    for(const auto& v:ret){
        cout<<v<<endl;
    }
    return 0;
}