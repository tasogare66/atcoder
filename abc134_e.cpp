//https://atcoder.jp/contests/abc134/tasks/abc134_e
//E - Sequence Decomposing
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main() {
  ll N; cin>>N;
  vector<ll> an(N);
  for(auto&& a:an) cin>>a;
  multiset<ll> lis;
  for(const auto& a:an){
    auto it = lis.lower_bound(a);
    if(it != lis.begin()){
      --it;
      lis.erase(it);
    }
    lis.insert(a);
  }
  //dump(lis);
  cout<<lis.size()<<endl;
  return 0;
}

struct Dat{
    ll v;
    ll pos;
};
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<Dat> an(N);
    for(ll i=0;i<N;++i){
        cin>>an[i].v;
        an[i].pos=i;
    }
#if 1
    multiset<ll> tbl;
    for(auto& a:an){
        auto it=lower_bound(tbl.begin(),tbl.end(),a.v);
        //auto it=tbl.lower_bound(a.v);
        if(it==tbl.begin()){
        } else{
            --it;
            tbl.erase(it);
        }
        tbl.insert(a.v);
    }
#else
    vector<Dat> tbl;
    tbl.reserve(N);
    for(auto& a:an){
        //いれるところ探索
        ll pt=-1;
        ll df=INT64_MAX;
        for(ll i=0;i<tbl.size();++i){
            auto&& t=tbl[i];
            if(t.v<a.v){
                ll dff=a.v-t.v;
                if(df>dff){
                    df=dff;
                    pt=i;
                }
            }
        }
        if(pt<0){
            tbl.push_back(a);
        }else{
            tbl[pt]=a;
        }
    }
#endif
    cout<<tbl.size()<<endl;
    return 0;
}