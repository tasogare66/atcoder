//https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_c
//C - カードゲーム
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll n; cin>>n;
    vector<ll> tarou(n);
    vector<ll> hanako;
    for(auto&& v:tarou){
        cin>>v;
    }
    sort(tarou.begin(),tarou.end());
    FOR(i,1,2*n+1){
        if(!binary_search(tarou.begin(),tarou.end(),i)){
            hanako.push_back(i);
        }
    }
    assert(hanako.size()==tarou.size());
    //game
    ll ba=-1;
    reference_wrapper<vector<ll>> player[2] = { tarou, hanako };
    ll p=0;
     while(tarou.size()>0&&hanako.size()>0){
        auto& lst= player[p].get();
        if(ba<0){
            auto it = lst.begin();
            ba = *it;
            lst.erase(it);//消す
        } else {
            auto it = lower_bound(lst.begin(),lst.end(),ba);
            if (it!=lst.end()){
                ba = *it;
                lst.erase(it);
            }else{
                //pass
                ba=-1;
            }
        }
        ++p;
        p%=2;
    }
    cout<<hanako.size()<<endl;
    cout<<tarou.size()<<endl;
    return 0;
}