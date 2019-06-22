//AtCoder ABC091 C - 2D Plane 2N Points
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
struct Pt{
    ll x,y;
    ll m_dstsq; //ユークリッド距離
    ll m_dstmh; //マンハッタン距離
    ll m_max;
    bool m_flag;
    void setup(){
        m_dstsq=x*x+y*y;
        m_dstmh=x+y;
        m_max=max(x,y);
        m_flag=false;
    }
};
int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<Pt> ab(N); //red
    vector<Pt> cd(N); //blue
    for(auto&& p:ab){
        cin>>p.x>>p.y;
        p.setup();        
    }
    for(auto&& p:cd){
        cin>>p.x>>p.y;
        p.setup();
    }
#if 1
    //青をsort,xで小さいものから
    sort(cd.begin(),cd.end(),[](const auto& a,const auto& b){
        return (a.x<b.x);
    });
    //赤は,y大きいものから
    sort(ab.begin(),ab.end(),[](const auto& a,const auto& b){
        return (a.y>b.y);
    });
    //青を回して入るやつをカウント
    ll ans=0;
    for(const auto& b:cd){
        for(auto&& r:ab){
            if(!r.m_flag && r.x<b.x&&r.y<b.y){
                ++ans;
                r.m_flag=true;
                break;
            }
        }
    }
    cout<<ans<<endl;
#else
    //赤をsort 
    sort(ab.begin(),ab.end(), [](const auto& a, const auto& b){
        if(a.m_dstsq==b.m_dstsq) return (a.m_max>b.m_max);
        return (a.m_dstsq>b.m_dstsq);
//        if(a.m_max==b.m_max) return(a.m_dstmh>b.m_dstmh);
//        return (a.m_max>b.m_max);
    });
    //青も
    sort(cd.begin(),cd.end(), [](const auto& a, const auto& b){
        if(a.m_dstsq==b.m_dstsq) return (a.m_max<b.m_max);
        return (a.m_dstsq<b.m_dstsq);
//        if(a.m_max==b.m_max) return(a.m_dstmh>b.m_dstmh);
//        return (a.m_max>b.m_max);
    });
    //赤を回して入るやつをカウント
    ll ans=0;
    for(const auto& r:ab){
        for(auto&& b:cd){
            if(!b.m_flag && r.x<b.x&&r.y<b.y){
                ++ans;
                b.m_flag=true;
                break;
            }
        }
    }
    cout<<ans<<endl;
#endif
    return 0;
}