//https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_a
//A - タイムカード
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Info{
    ll h,m,s;
    void get(){
        cin>>h>>m>>s;
    }
    Info operator - (Info obj) {
        Info ret;
		ret.s = s - obj.s;
        if(ret.s<0) {
            --m;
            ret.s+=60;
        }
        ret.m = m-obj.m;
        if(ret.m<0){
            --h;
            ret.m+=60;
        }
		ret.h = h-obj.h;
		return ret;
	}
    void cout(){
        std::cout<<h<<" "<<m<<" "<<s<<endl;
    }
};
int main() {
    vector<Info> st(3),ed(3);
    REP(i,3){
        st.at(i).get();
        ed.at(i).get();
    }
    REP(i,3){
        (ed.at(i)-st.at(i)).cout();
    }
    return 0;
}