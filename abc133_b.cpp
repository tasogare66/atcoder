//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

bool isPowerOfTwo(ll x) {
#if LOCAL&0
    cout<<"a*"<<(x & (x - 1))<<endl;
#endif
    ll tmp = sqrt(x);
    return (tmp*tmp==x);
    //return ((x & (x - 1)) == 0);
}

int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,D; cin>>N>>D;
    //vector<vector<ll>> abc(3,vector<ll>(N));
    vector<vector<ll>> xd(N);
    for(auto&& t:xd){
        for(ll i=0;i<D;++i){
            ll x; cin>>x;
            t.push_back(x);
        }
    }

    auto calc_dist = [&](ll i, ll j){
        ll ret=0;
        for(ll p=0;p<xd[i].size();++p){
            ll tmp=xd[i][p]-xd[j][p];
            ret += (tmp*tmp);
        }
#if LOCAL&0
        cout<<ret<<endl;
#endif
        return isPowerOfTwo(ret);
    };

    ll ans=0;
    for(ll i=0;i<N;++i){
        for(ll j=0;j<N;++j){
            if(i<j){
                if(calc_dist(i,j)) ++ans;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}