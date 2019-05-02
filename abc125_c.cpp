//ABC125 C - GCD on Blackboard
#include <bits/stdc++.h>
using namespace std;
int64_t calc_gdc(int64_t a,int64_t b)
{
    if (a<b){
        swap(a,b);
    }
	int64_t r = a % b;
	while(r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
    return b;
}
int main() {
    int64_t n;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>n;
    vector<int64_t> atbl(n);
    for(auto&a:atbl){
		cin >> a;
	}
#if 1
    //外す数を探す
    vector<int64_t> tmp(n);
    tmp[n-1]=atbl[n-1];
    for(int i=n-2;i>=0;--i){
        tmp[i]=calc_gdc(atbl[i],tmp[i+1]);
    }
    vector<int64_t> tmp_st(n);
    tmp_st[0]=atbl[0];
    for (int i=1; i<n;++i) {
        tmp_st[i] = calc_gdc(atbl[i], tmp_st[i-1]);       
    }
    int64_t ans=0;
    for(int skip=0;skip<n;++skip){
        int64_t val;
        if(skip==0){
            val=tmp[1];
        } else if (skip==n-1) {
            val=tmp_st[n-2];
        } else {
			int64_t ll = tmp_st[skip - 1];
			int64_t rr = tmp[skip + 1];
    		val=calc_gdc(ll,rr);
		}
        ans=max(ans,val);
    }
    cout<<ans<<endl;
#else
    //tleする
    int64_t ans=0;
    for(int skip=0;skip<n;++skip){
        bool flag=false;
        int64_t val = -1;
        for(int i=0;i<n;++i){
            if(i==skip) continue;
            if (val<0) {
				val = atbl[i];
			} else {
                val = calc_gdc(val,atbl[i]);
            }
        }
        ans=max(ans,val);
    }
    cout<<ans<<endl;
#endif
    return 0;
}