//https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_b
//B - サッカー (Soccer)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Info {
    ll point;
    ll idx;
    ll rank;
};
int main() {
    ll N; cin>>N;
    ll match_num=N*(N-1)/2;
    vector<Info> point(N+1);
    FOR(i,1,point.size()){
        point.at(i).idx=i;
    }
    REP(i,match_num){
        ll a,b; cin>>a>>b; //a vs b
        ll as, bs; cin>>as>>bs;
        if(as==bs){
            point.at(a).point++;
            point.at(b).point++;
        }else if(as>bs){
            point.at(a).point += 3;
        }else{
            point.at(b).point += 3;
        }
    }

    sort(point.begin()+1,point.end(),[](auto& a, auto& b){ return a.point>b.point;});
    FOR(i,1,point.size()){
        point.at(i).rank=i;
    }
    FOR(i,2,point.size()){
        if(point.at(i).point == point.at(i-1).point){
            point.at(i).rank=point.at(i-1).rank;
        }
    }

    sort(point.begin()+1,point.end(),[](auto&a,auto&b){return a.idx<b.idx;});
    FOR(i,1,point.size()){
        cout<<point.at(i).rank<<endl;
    }

    return 0;
}