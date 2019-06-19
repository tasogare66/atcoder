//AtCoder ABC057 B - Checkpoints
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
using Pos=pair<ll,ll>;

int main() {
    int N,M;
    cin>>N>>M;
    vector<Pos> ab(N);
    vector<Pos> cd(M);
    for(auto&& p:ab){
        cin>>p.first>>p.second;
    }
    for(auto&& p:cd){
        cin>>p.first>>p.second;
    }
    auto nearest = [&](Pos p){
        ll max_dist=INT64_MAX;
        ll ret=0;
        for(int i=0;i<cd.size();++i){
            ll cur_dst= abs(cd[i].first-p.first)+abs(cd[i].second-p.second);
            if (cur_dst < max_dist){
				max_dist = cur_dst;
				ret = i;
			}
        }
        return ret+1;
    };
    for(const auto&p:ab){
        auto idx=nearest(p);
        cout<<idx<<endl;
    }
    return 0;
}