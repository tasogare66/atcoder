//AtCoder ABC064 C - Colorful Leaderboard
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<ll> atbl(N);
    for(auto&& a:atbl){
		cin >> a;
	}
    vector<ll> rtbl(9,0);
    auto get_rate = [](ll ia){
        ll sttbl[]={3200,2800,2400,2000,1600,1200,800,400,1};
        for(ll i=0;i<array_size(sttbl);++i){
            if(ia>=sttbl[i]) return i;
        }
    };
    for(const auto& a:atbl){
        ll r = get_rate(a);
        ++rtbl[r];
    }
    ll ans=0;
    for(ll i=1;i<rtbl.size();++i){
        if(rtbl[i]>0) ++ans;
    }
    //ll ans_max=min(ans+rtbl[0],(ll)rtbl.size()-1);
    ll ans_max=ans+rtbl[0];
    if(ans==0&&rtbl[0]>0)ans=1;
    cout<<ans<<" "<<ans_max<<endl;
    return 0;
}