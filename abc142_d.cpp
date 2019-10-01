//https://atcoder.jp/contests/abc142/tasks/abc142_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

auto Eratosthenes(const int n)
{
    vector<ll> result;
    result.emplace_back(1); //特殊
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
bool is_prime(const ll n){
    switch(n){
        case 0: // fall-through
        case 1: return true;//false;
        case 2: return true;
    } // n > 2 が保証された

    if(n%2 == 0) return false;

    // 上で i=2 相当は調べたので、i=3から奇数のみ調べる
    for(ll i=3;i*i<=n;i+=2){
        if(n%i == 0) return false;
    }

    return true;
}

int main() {
#if LOCAL&01
    //std::ifstream in("./test/sample-2.in"); //input.txt
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll A,B; cin>>A>>B;
    //if(A>B) swap(A,B); //A小さい
    auto gcdv = __gcd(A,B);
    //auto al = divisor(A);
    //auto bl = divisor(B);
#if LOCAL
    cout<<"gcd"<<gcdv<<endl;
#endif
    vector<ll> tyou = divisor(gcdv);
#if LOCAL
    cout<<tyou.back()<<endl;
#endif
    // for(auto a:al){
    //     auto it = lower_bound(bl.begin(),bl.end(), a);
    //     if(*it==a){ tyou.push_back(a);}
    // }

    //素数は判定
//    auto sosu = Eratosthenes(tyou.back());
#if LOCAL
//    cout<<sosu.size()<<endl;
#endif
    ll ans=0;
    for(auto v:tyou){
        if (is_prime(v)) {
#if LOCAL
            cout<<v<<endl;
#endif
            ++ans;
        }
        //else break;
    }
    // for(auto v:tyou){
    //     auto it = lower_bound(sosu.begin(),sosu.end(),v);
    //     if(*it==v) ++ans;
    // }
    cout<<ans<<endl;

    return 0;
}