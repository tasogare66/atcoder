//AGC033 A - Darker and Darker
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

struct Edge{
    int m_dist=0;
    int m_open_cnt=-1;
    char m_ch;
};

int h,w;

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>h>>w;
    vector<string> cl0(h);
    for(auto&& l:cl0){
        cin>>l;
    }
    vector<char*> map0(cl0.size());
	for(int i = 0; i < cl0.size(); ++i){
		map0[i] = &cl0[i][0];
	}

    int num=0;
    deque<pair<int,int>> lst; //x,y
	for(int y = 0; y < h; ++y) {
		for(int x = 0; x < w; ++x) {
			if(map0[y][x] == '#') {
				++num;
			} else {
                lst.push_back(make_pair(x,y));
            }
        }
	}

	auto update_map = [&](int ix, int iy) {
		if(ix >= 0 && ix < w && iy >= 0 && iy < h) {
			if(map0[iy][ix] == '#') {
				return true;
			}
		}
        return false;
	};

    int ans=0;
    while (num != w*h){
        deque<pair<int,int>> tmp;

		auto it = lst.begin();
		while(it != lst.end()) {
			int x=it->first;
            int y=it->second;
			if(update_map(x + 1, y) || update_map(x - 1, y) ||
			   update_map(x, y - 1) || update_map(x, y + 1)) {
				++num;
				tmp.push_back(*it);
				it = lst.erase(it);
			} else
				++it;
		}
		for(auto &p : tmp) {
			map0[p.second][p.first]='#';
        }
        ++ans;
	}

    cout<<ans<<endl;
}