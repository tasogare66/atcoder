//https://atcoder.jp/contests/agc003/tasks/agc003_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//なるべく次に余らせる,貪欲でよかった
int main() {
    ll N; cin>>N;
    vector<ll> an(N+1,0);
    FOR(i,1,N+1){
        cin>>an.at(i);
    }

    auto decan = [](ll& av, ll val){
        av -= val; assert(av>=0);
    };

    ll ans=0;
    FOR(i,1,N+1){
        ll tmp=an.at(i)/2;
        ans += tmp;
        decan(an[i], tmp*2);
        //次のとマッチ
        if(i<N){
            ll nt=min(an.at(i), an.at(i+1));
            ans+=nt;
            decan(an[i+1],nt);
        }
    }
    cout<<ans<<endl;
    return 0;
}
#if 0
int main_wa() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> an(N+1,0);
    FOR(i,1,N+1){
        cin>>an[i];
    }
    auto decan = [](ll& av, ll val){
        av -= val; assert(av>=0);
    };

    ll ans=0;
     FOR(i,1,N+1){
        ll tmp=max<ll>(an.at(i)-1,0);
        tmp /= 2;
        ans+=tmp;
        decan(an[i], tmp*2);
    }
    FOR(i,1,N){
         ll tmp=min(an.at(i), an.at(i+1));
         ans+=tmp;
         an[i]-=tmp; assert(an[i]>=0);
         an[i+1]-=tmp; assert(an[i+1]>=0);
    }
    FOR(i,1,N+1){
        ans+=an.at(i)/2;
    }
    cout<<ans<<endl;
    return 0;
}
#endif