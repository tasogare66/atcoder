//AtCoder ABC096 C - Grid Repainting 2
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll H,W; cin>>H>>W;
    vector<string> sw(H);
    for(auto&& s:sw){
        cin>>s;
    }
    auto check_func = [&](ll y,ll x){
        if(y>=0&&y<H&&x>=0&&x<W){
            return (sw[y][x]=='#');
        }
        return false;
    };
    bool ans=true;
    for(ll y=0;y<H;++y){
        for(ll x=0;x<W;++x){
            //隣接があるかチェック
            if(sw[y][x]=='#'){
				if(!check_func(y - 1, x) && !check_func(y + 1, x) &&
				   !check_func(y, x - 1) && !check_func(y, x + 1))
                {
					ans = false;
					break;
				}
			}
		}
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}