//AtCoder ABC104 C - All Green
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll BinarySearch(ll low, ll high, std::function<bool(ll)> check){
    if(high-low<=1){
        return high;
    }
    ll mid = (high+low)/2; 
    //cout<<mid<<" ,"<<low<<","<<high<<endl;
    if(check(mid)){
        //return BinarySearch(mid, high, check);
        return BinarySearch(low, mid, check);
    }else{
        //return BinarySearch(low, mid, check);
        return BinarySearch(mid, high, check);
    }
}
struct Data{
    ll p; //問題数
    ll sc; //点数
    ll b; //ボーナス
    ll scb; //全部といた点数
    //bool flag=false;
    void use(){
        sc=0;
        scb=0;
        //flag=true;
    }
};
#if 1
ll search(ll num,ll score,const vector<Data>& pd,ll use_flag){
    if (num<=0) return score;
    ll ret_score=0;
    for(ll i=0;i<pd.size();++i){
        auto&& d=pd[i];
        ll uf=1<<i;
        if (use_flag&uf)continue;
        if(num>=d.p){
            ret_score=std::max(search(num-d.p,score+d.scb,pd,use_flag|uf),ret_score);
        } else {
            ret_score=std::max(search(0,score+d.sc*num,pd,use_flag|uf),ret_score);
        }
    }
    return ret_score;
}
#else
#endif
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
#if LOCAL&0
    std::ifstream in("input.txt");
    //std::ifstream in("./test/sample-2.in");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll D,G; cin>>D>>G;
    vector<Data> pd;
    pd.reserve(D+1);
    ll ttl_p_num=0;
    for(ll i=1;i<=D;++i){
        ll p,c; cin>>p>>c;
        Data dat;
        dat.p=p;
        dat.sc=100*i;
        dat.b=c;
        dat.scb=c+100*i*p;
        pd.push_back(dat);
        ttl_p_num+=p;
    }
    ll sc=0;
    ll num=0;
    // while(sc<G){
    //     //auto tmp=pd;//copy
    //     ++num;
    //     sc=search(num,0,pd,0);
    // }
	num = BinarySearch(0, ttl_p_num,
					   [&](ll mid) { return (search(mid, 0, pd, 0) >= G); });
	cout << num << endl;
	return 0;
}