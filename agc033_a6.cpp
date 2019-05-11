//AGC033 A - Darker and Darker
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
using Pos=pair<int,int>;
using veci=vector<int>;

int h,w;

int main() {
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>h>>w;
    vector<string> cl(h);
    for(auto&& l:cl){
        cin>>l;
    }
    vector<char*> map(cl.size());
	for(int i = 0; i < cl.size(); ++i){
		map[i] = &cl[i][0];
	}

    //bfs
    vector<veci> dist(h,veci(w,-1));
    queue<Pos> que;
    for (int y=0;y<h;++y){
		for(int x = 0; x < w; ++x) {
            if (map[y][x]=='#'){
				dist[y][x] = 0;
				que.push({x,y});
			}
		}
	}
    while(!que.empty()){
        auto now = que.front();
        que.pop();
        int x= now.first;
        int y= now.second;

        int xofs[4]={1,-1,0,0};
        int yofs[4]={0,0,1,-1};
        for(int i=0;i<4;++i){
            auto gx=x+xofs[i];
            auto gy=y+yofs[i];
			if(gx >= 0 && gx < w && gy >= 0 && gy < h && dist[gy][gx]<0) {
				dist[gy][gx] = dist[y][x] + 1;
				que.push({gx, gy});
			}
        }
    }
    //max
    int ans=0;
    for(auto&& dl : dist){
        for(auto&& d:dl){
            ans=std::max(d,ans);
        }
    }
    cout<<ans<<endl;
	return 0;
}