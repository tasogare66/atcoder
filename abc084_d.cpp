//https://atcoder.jp/contests/abc084/tasks/abc084_d
//D - 2017-like Number
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//int N;
//エラトステネスの篩
//bool is_prime[ 10000 + 1 ];
vector<int> P;
auto Eratosthenes( const int N )
{
    unordered_map<ll,bool> result;
    vector<bool> is_prime(N+1,true);
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;//初期化
    }    
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            result.emplace( i,true );
        }
    }
    return result;
}

int main() {
#if LOCAL&0
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll Q; cin>>Q;
    vector<pair<ll,ll>> lrq(Q);
    for(auto&& lr:lrq){
        cin>>lr.first>>lr.second;
    }

    auto lst = Eratosthenes(1e+5);
    vector<ll> l2017;
    for(const auto& p:lst){
        auto v2 = (p.first + 1) / 2;
        if (lst.count(v2) > 0){
            l2017.push_back(p.first);
        }
    }
    sort(l2017.begin(),l2017.end());

    for(const auto& lr: lrq){
        auto it = lower_bound(l2017.begin(), l2017.end(), lr.first);
        ll st = std::distance(l2017.begin(), it);

        it = upper_bound(l2017.begin(), l2017.end(), lr.second);
        ll ed = std::distance(l2017.begin(), it);
        ll ans = (ed-st);
        cout<<ans<<endl;
    }
    return 0;
}
