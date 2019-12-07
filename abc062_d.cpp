//https://atcoder.jp/contests/arc074/tasks/arc074_b
//D - 3N Numbers
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&0
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> a3n(3*N);
    for(auto&& a:a3n){
        cin>>a;
    }
    //先頭のNをいれる
    priority_queue<ll,vector<ll>,greater<ll>> h_que; //小さいのが先頭に
    vector<ll> h_sum;
    ll sum=0;
    FOR(i,0,N){
        auto v=a3n.at(i);
        sum += v;
        h_que.push(v);
    }
    //次のNを入れながらmaxとる
    h_sum.emplace_back(sum);
    FOR(i,N,2*N){
        auto v=a3n.at(i);
        sum += v;
        h_que.push(v);
        sum -= h_que.top();
        h_que.pop();
        h_sum.emplace_back(sum);
    }

    //次
    priority_queue<ll> f_que;
    vector<ll> f_sum;
    sum=0;
    FOR(i,2*N,3*N){
        auto v=a3n.at(i);
        sum += v;
        f_que.push(v);
    }
    f_sum.emplace_back(sum);
    for(ll i=2*N-1;i>=N;--i){
        auto v=a3n.at(i);
        sum += v;
        f_que.push(v);
        sum -= f_que.top();
        f_que.pop();
        f_sum.emplace_back(sum);
    }
    assert(f_sum.size()==h_sum.size());
    ll ans=INT64_MIN;
    REP(i,h_sum.size()){
        ll tmp = h_sum.at(i)-f_sum.at(f_sum.size()-i-1);
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;

    return 0;
}
