//AtCoder C - Pyramid
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
struct Dat{
    ll x,y;
    ll h;
};
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<Dat> dtbl(N);
    for(auto&& d:dtbl){
        cin>>d.x>>d.y>>d.h;
    }
    sort(dtbl.begin(),dtbl.end(),[](auto& a, auto& b){return a.h>b.h;});
    auto check_data = [&](const Dat& d,ll cx,ll cy){
        ll h=abs(d.x-cx)+abs(d.y-cy)+d.h;
        return h;
    };
    auto check2 = [&](const Dat& d,ll cx,ll cy, ll h){
        return (max(h-abs(d.x-cx)-abs(d.y-cy),(ll)0)==d.h);
    };
    for(ll cy=0;cy<=100;++cy){
        for(ll cx=0;cx<=100;++cx){
            ll h=check_data(dtbl[0],cx,cy);
            if (h<0) break;
            bool ok_flag=true;
            for(const auto& d:dtbl){
                ok_flag &= check2(d,cx,cy,h);
                if(!ok_flag) break;
            }
            if (ok_flag){
                cout<<cx<<" "<<cy<<" "<<h<<endl;
                return 0;
            }
        }
    }
    return 0;
}