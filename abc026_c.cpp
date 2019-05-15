//ABC026 C - 高橋君の給料
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
struct Node{
    lli m_income=1;
    vector<int> m_ch;
};
vector<Node> tbl;
lli calc(int n){
    if (tbl[n].m_ch.empty()) {
		return 1;
    }
    lli max_v=0;
    lli min_v=INT64_MAX;
    for (auto& no:tbl[n].m_ch) {
        lli v = calc(no);
        max_v = std::max(max_v, v);
        min_v = std::min(min_v, v);
    }
    return (max_v + min_v + 1);
}
int main() {
#if LOCAL&0
	std::ifstream in("input.txt");
	std::cin.rdbuf(in.rdbuf());
#endif
    lli N;
    cin>>N;
    tbl.resize(N);
    for (int i=1;i<N;++i) {
        lli b;
        cin>>b;
        --b;
        tbl[b].m_ch.push_back(i);
    }
    lli ans = calc(0);
    cout<<ans<<endl;
    return 0;
}