//AGC033 A - Darker and Darker
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

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
	for(int y = 0; y < h; ++y) {
		for(int x = 0; x < w; ++x) {
			if(map0[y][x] == '#') {
				++num;
			}
        }
	}
    int ans=0;
#if 1
	auto update_map = [&](int ix, int iy) {
		if(ix >= 0 && ix < w && iy >= 0 && iy < h) {
			if(map0[iy][ix] == '#') {
				return true;
			}
		}
        return false;
	};

	vector<pair<int, int>> tmp;
    tmp.reserve(w*h);
	while(num != w*h){
        //update
		for(int y = 0; y < h; ++y) {
			for(int x = 0; x < w; ++x) {
				if(map0[y][x] == '.') {
					if(update_map(x + 1, y) || update_map(x - 1, y) ||
					   update_map(x, y - 1) || update_map(x, y + 1)) {
						++num;
						tmp.push_back(make_pair(x, y));
					}
				}
			}
		}
		for(auto &p : tmp) {
			map0[p.second][p.first]='#';
        }
        tmp.clear();
        ++ans;
    }
    cout<<ans<<endl;
#endif
    return 0;
}