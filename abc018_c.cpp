//ABC018 C - 菱型カウント
#include <bits/stdc++.h>
using namespace std;
struct Info{
    bool maru;//白
    int m_lev_x;
    int m_lev_y;
};
int main() {
    int R,C,K;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>R>>C>>K;
    Info mapd[R][C]={};
    string in_s;
    for(int y=0;y<R;++y){
        cin>>in_s;
        for(int x=0;x<in_s.size();++x){
            auto& p = mapd[y][x];
            p.maru = (in_s[x]=='o')?true:false;
        }
    }
    //levelつくる
    //横
    for(int y=0;y<R;++y){
        int cnt=0;
        for (int x=0;x<C;++x) {
			auto &p = mapd[y][x];
			if(p.maru) {
                ++cnt;
            } else {
                cnt=0;
            }
            p.m_lev_x=cnt;
        }
        cnt=0;
        for(int x=C-1;x>=0;--x){
			auto &p = mapd[y][x];
            if(p.maru) {
                ++cnt;
            } else {
                cnt=0;
            }
            p.m_lev_x=std::min(cnt,p.m_lev_x);
        }
    }
#if 0
    //縦
    for(int x=0;x<C;++x){
        int cnt=0;
        for (int y=0;y<R;++y) {
			auto &p = mapd[y][x];
			if(p.maru) {
                ++cnt;
            } else {
                cnt=0;
            }
            p.m_lev_y=cnt;
        }
        cnt=0;
        for(int y=R-1;y>=0;--y){
			auto &p = mapd[y][x];
            if(p.maru) {
                ++cnt;
            } else {
                cnt=0;
            }
            p.m_lev_y=std::min(cnt,p.m_lev_y);
        }
    }
#endif
#if LOCAL&0
	for(int y = 0; y < R; ++y) {
		for(int x = 0; x < C; ++x) {
			auto &p = mapd[y][x];
			cout<<p.m_lev_y;
		}
		cout << endl;
	}
#endif
    int cnt=0;
    int stk=K-1;
    for(int y=stk; y<R-stk;++y) {
        for(int x=stk; x<C-stk;++x){
            int kk = K;
            bool ok=true;
            int ofs=0;
			while(kk > 0) {
    			auto &pu = mapd[y-ofs][x];
				auto &pd = mapd[y+ofs][x];
				if(pu.m_lev_x < kk || pd.m_lev_x < kk) {
					ok=false;
                    break;
				}
				--kk;
                ++ofs;
			}
            if(ok)++cnt;
		}
    }
    cout<<cnt<<endl;
	return 0;
}