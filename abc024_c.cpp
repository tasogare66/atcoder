//ABC024 C - 民族大移動
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
using Dur=pair<int,int>;
int main() {
    lli N,D,K;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>D>>K;
    vector<Dur> lrs(D);
    for(auto& d:lrs){
		cin >> d.first >> d.second;
	}
    vector<int> ans;
    ans.reserve(K);
    for(int i= 0;i<K;++i){
        int s,t;
		cin >> s >> t;
        if(s<t){
            //max,右
			int cur = s;
			for(int day=0;day<lrs.size();++day){
				const auto &m = lrs[day];
				if(cur >= m.first && cur <= m.second) {
					cur = max(cur, m.second);
					if(cur >= t) {
						ans.push_back(day+1);
                        break;
					}
				}
			}
		}else{
            //min,左
			int cur = s;
            for(int day=0;day<lrs.size();++day){
				const auto &m = lrs[day];
				if(cur >= m.first && cur <= m.second) {
					cur = min(cur, m.first);
                    if(cur<=t){
						ans.push_back(day+1);
                        break;
                    }
				}
			}
		}
	}
    for(auto&a:ans){
        cout<<a<<endl;
    }
    return 0;
}