//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<ll> orig(N);
    vector<ll> pu,mi;
    for(auto&& t:orig){
        cin>>t;
        if (t>=0) pu.push_back(t);
        else mi.push_back(t);
    }
    auto aaa_func = [&](){
        auto pu2=pu;
        auto mi2=mi;
        ll ans=0;
        for(int i=1;i<pu.size();++i){
            mi[0] -= pu[i];            
        }
        for(int i=1;i<mi.size();++i){
            pu[0] -= mi[i];
        }
        cout<<pu[0]-mi[0]<<endl;

        for(int i=1;i<pu2.size();++i){
            cout<<mi2[0]<<" "<<pu2[i]<<endl;            
            mi2[0] -= pu2[i];            
        }
        for(int i=1;i<mi2.size();++i){
            cout<<pu2[0]<<" "<<mi2[i]<<endl;
            pu2[0] -= mi2[i];
        }
        cout<<pu2[0]<<" "<<mi2[0]<<endl;
    };
    if (pu.size()!=0 && mi.size()!=0){
        aaa_func();
        return 0;
    }


    sort(orig.begin(),orig.end());
    auto tbl=orig;
    auto tbl2=tbl;

    while(tbl.size()>2){
        tbl[0] -= tbl.back();
        tbl.pop_back();
    }
    ll ans=tbl[1]>tbl[0]?tbl[1]-tbl[0]:tbl[0]-tbl[1];
    //cout<<ans<<endl;

    reverse(tbl2.begin(),tbl2.end());
    while(tbl2.size()>2){
        tbl2[0] -= tbl2.back();
        tbl2.pop_back();
    }
    ll ans2=tbl2[1]>tbl2[0]?tbl2[1]-tbl2[0]:tbl2[0]-tbl2[1];
    //cout<<ans2<<endl;

    if(ans>=ans2){
        cout<<ans<<endl;
    } else {
        cout<<ans2<<endl;
        reverse(orig.begin(),orig.end());
    }
    while(orig.size()>2){
        cout<<orig[0]<<" "<<orig.back()<<endl;
        orig[0] -= orig.back();
        orig.pop_back();
    }
    if(orig[1]>orig[0]){
        cout<<orig[1]<<" "<<orig[0]<<endl;
    } else {
        cout<<orig[0]<<" "<<orig[1]<<endl;
    }
#if 0
    ll N;
    cin>>N;
    vector<ll> pl;
    vector<ll> mi;
    for(int i=0;i<N;++i){
        ll a;
        cin>>a;
        if(a>=0) pl.push_back(a);
        else mi.push_back(a);
    }
    sort(pl.begin(),pl.end());
    sort(mi.begin(),mi.end());
    ll ans=0;
    if(pl.size()==0){
    } else if(mi.size()==0){
    }
#endif
    return 0;
}