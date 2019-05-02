//ABC016 C - 友達の友達
#include <bits/stdc++.h>
using namespace std;
struct Lst{
    int m_id;
    bool m_flag=false;
    bool m_dis=false;
    std::vector<int> m_l;
};
int main() {
    int N;
    int pair_num;//M
#if LOCAL&1
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>pair_num;
    std::vector<Lst> hito(N);
    for (int i=0;i<hito.size();++i){
		hito[i].m_id = i;
	}
    for (int i=0;i<pair_num;++i){
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        hito[a].m_l.push_back(b);
        hito[b].m_l.push_back(a);
    }

    auto reset_func=[&](){
        for(auto&p:hito){
			p.m_flag = false;
			p.m_dis = false;
		}
    };
    for(auto&p:hito){
        reset_func();
		p.m_dis = true;
		for (auto id:p.m_l){
			//ans += std::max(0,((int)hito[id].m_l.size()-1)); //自分は抜くので-1
            hito[id].m_dis = true;
            for (auto ff : hito[id].m_l) {
                hito[ff].m_flag=true;
            }
		}
		int ans = 0;
        for (auto&pp:hito) {
            if(pp.m_flag&&!pp.m_dis) ++ans;
        }
		cout << ans << endl;
	}
    return 0;
}