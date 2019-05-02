//ABC010 C - 浮気調査
#include <bits/stdc++.h>
using namespace std;
struct Pos{
    int m_x;
    int m_y;
};
constexpr double e = std::numeric_limits<double>::epsilon();
int main() {
    int stx,sty;
    int edx,edy;
    int T,V;
    int n;
#if LOCAL&1
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>stx>>sty>>edx>>edy>>T>>V;
    cin>>n;
    vector<Pos> ptbl(n);
    for(auto& p:ptbl) {
        cin>>p.m_x>>p.m_y;
    }
    double len = T * V;
    bool flag = false;
    for (const auto& p:ptbl) {
		double dist1 =
			(stx - p.m_x) * (stx - p.m_x) + (sty - p.m_y) * (sty - p.m_y);
		double dist2 =
			(edx - p.m_x) * (edx - p.m_x) + (edy - p.m_y) * (edy - p.m_y);
        double dist = sqrt(dist1) + sqrt(dist2);
        if (dist - len<=e) {
            flag = true;
            break;
        }
	}
    cout<<(flag?"YES":"NO")<<endl;
    return 0;
}