//https://atcoder.jp/contests/arc002/tasks/arc002_2
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
std::vector<std::string> split(const std::string& input, char delimiter){
    std::istringstream stream(input);
    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}
int main() {
    string s; cin>>s;
    auto ss = split(s,'/');
    ll y=atoi(ss[0].c_str());
    ll m=atoi(ss[1].c_str());
    ll d=atoi(ss[2].c_str());
    auto check_func = [](ll iy, ll im, ll id){
        return (iy % (im*id) == 0);
    };
    auto next_month = [&](){
        d=1;
        ++m;
    };
    auto check_uruu = [](ll iy){
        bool ans=false;
        if(iy%4==0) {
            ans=true;
        }    
        if(iy%100==0&&iy%400!=0) {
            ans=false;
        }
        return ans;
    };
    while(!check_func(y,m,d)){
        //次の日
        ++d;
        if (m==2) {
            if(check_uruu(y)){
                if(d>29) next_month();
            } else {
                if(d>28) next_month();
            }
        } else if(m==4||m==6||m==9||m==11){
            if(d>30){
                next_month();
            }
        } else {
            if(d>31){
                next_month();
            }
        }
        if(m>12) {
            m=1;
            ++y;
        }
    }
    cout<<y<<"/"<<std::setfill('0')<<std::setw(2)<<m<<"/"<<std::setfill('0')<<std::setw(2)<<d<<endl;
    return 0;
}