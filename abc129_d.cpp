//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll H,W;
    cin>>H>>W;
    vector<string> map(H);
    for(auto&& m:map){
        cin>>m;
    }
    vector<vector<ll>> acc_x(H,vector<ll>(W,0));
    vector<vector<ll>> acc_y(H,vector<ll>(W,0));
    //よこ
    for(int y=0;y<H;++y){
        ll sum=0;
        for(int x=0;x<W;++x){
            if(map[y][x]=='.'){
                ++sum;
            } else {
                sum=0;
            }
            acc_x[y][x]=sum;
        }
        sum=0;
        for(int x=W-1;x>=0;--x){
            if(map[y][x]=='.'){
                ++sum;
            } else {
                sum=0;
            }
            acc_x[y][x]+=sum;
        }
    }
    //たて
    for(int x=0;x<W;++x){
        ll sum=0;
        for(int y=0;y<H;++y){
            if(map[y][x]=='.'){
                ++sum;
            } else {
                sum=0;
            }
            acc_y[y][x]=sum;
        }
        sum=0;
        for(int y=H-1;y>=0;--y){
            if(map[y][x]=='.'){
                ++sum;
            } else {
                sum=0;
            }
            acc_y[y][x]+=sum;
        }
    }
    //全探索
    ll ans=0;
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            ans=max(acc_x[y][x]+acc_y[y][x],ans);
	    }
    }
    cout<<ans-1-1-1<<endl;
    return 0;
}