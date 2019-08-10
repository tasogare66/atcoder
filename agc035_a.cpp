    //https://atcoder.jp/contests/agc035/tasks/agc035_a
    //A - XOR Circle
    //a,b,a^b でならぶので、a,b,a^bの3種
    #include <bits/stdc++.h>
    using namespace std;
    using ll=int64_t;
    #define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
    #define REP(i,n)  FOR(i,0,n)
    int main() {
        ll N; cin>>N;
        vector<ll> an(N);
        unordered_map<ll,ll> vnum;
        for(auto&& a:an){
            cin>>a;
            ++vnum[a];
        }
        bool ret=false;
        //全0
        if(vnum.size()==1&&vnum.begin()->first==0){
            ret=true;
        }
        //0一つ、x,x,0
        if(N%3==0&&vnum.size()==2&&vnum.count(0)&&vnum[0]==N/3){
            ret=true;
        }
        //3つ違う a,b,c
        if(N%3==0&&vnum.size()==3){
            ll x=0;
            bool ret3=true;
            for(auto& d:vnum){
                x^=d.first;
                if(d.second!=N/3){
                    ret3=false;
                }
            }
            if(x!=0) ret3=false;
            ret|=ret3;
        }
#if 0
        ll tmp=an[i]
        ll ans=an[0];
        FOR(i,1,N){
            ans ^= an[i];
        }
#endif
        cout<<(ret?"Yes":"No")<<endl;
        return 0;
    }