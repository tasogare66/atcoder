//AtCoder ABC069 C - 4-adjacent
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    vector<ll> an(N,0);
    for(auto&& a:an){
        cin>>a;
    }
    //
    ll four_bai=0;
    ll two_bai=0;
    ll dis=0;
    for(const auto& a:an){
        if(a%4==0){
            ++four_bai;
        } else if(a%2==0){
            ++two_bai;
        } else {
            ++dis;
        }
    }
    bool ans=false;
    ans |= (four_bai>=dis);
    ans |= (two_bai==0&&four_bai+1>=dis);
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}