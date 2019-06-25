//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,K; cin>>N>>K;
#if 1
    vector<ll> u,v;

    bool ans=(N-2>=K);    
    auto func = [&](ll st){
        u.push_back(st);
        v.push_back(st+1);
        for(ll i=st+2;i<=N;++i){
            u.push_back(st+2);
            v.push_back(i);
        }
        for(ll i=K;i<N-2;++i){
            u.push_back(st+1);
            v.push_back(i-K+st+2);
        }
    };
    ll st=1;
    while(N-2>=K){
        func(st);
        st+=2;
    }

#else
    vector<ll> u,v;
    if(ans){
        u.push_back(1);
        v.push_back(2);
        for(ll i=3;i<=N;++i){
            u.push_back(2);
            v.push_back(i);
        }
        for(ll i=K;i<N-2;++i){
            u.push_back(1);
            v.push_back(i-K+3);
        }
        cout<<u.size()<<endl;
        for(ll i=0;i<u.size();++i){
            cout<<u[i]<<" "<<v[i]<<endl;
        }
    } else{
        cout<<-1<<endl;
    }
#endif
    return 0;
}