//ABC022 B - Bumble Bee
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    lli n;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>n;
    vector<lli> atbl(n);
    for (auto&& a:atbl){
        cin>>a;
    }
    auto atbl2=atbl;//copy
    std::sort(atbl2.begin(), atbl2.end());
	atbl2.erase(std::unique(atbl2.begin(), atbl2.end()), atbl2.end());
	cout<<atbl.size()-atbl2.size()<<endl;
    return 0;
}