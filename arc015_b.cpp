//https://atcoder.jp/contests/arc015/tasks/arc015_2
//B - 真冬日？真夏日？
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<pair<double,double>> mt(N); //高,低
    for(auto&& m:mt){
        cin>>m.first>>m.second;
    }
    vector<ll> cnt(6);
    //0 猛暑日：最高気温が 35 度以上の日
    //1 真夏日：最高気温が 30 度以上、35 度未満の日
    //2 夏日　：最高気温が 25 度以上、30 度未満の日
    //3 熱帯夜：最低気温が 25 度以上の日
    //4 冬日　：最低気温が 0 度未満で、最高気温が 0 度以上の日
    //5 真冬日：最高気温が 0 度未満の日
    auto check_func = [&](double h,double l){
        if(h>=35.0){
            ++cnt.at(0);
        }else if(h>=30){
            ++cnt.at(1);
        }else if(h>=25){
            ++cnt.at(2);
        }
        if(l>=25){
            ++cnt.at(3);
        }
        if(l<0&&h>=0){
            ++cnt.at(4);
        }
        if (h<0){
            ++cnt.at(5);
        }
    };
    for(const auto& m:mt){
        check_func(m.first,m.second);
    }
    REP(i,cnt.size()){
        if(i>0)cout<<" ";
        cout<<cnt.at(i);
    }
    cout<<endl;
    return 0;
}