//ABC010 B - 花占い
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>n;
    vector<int> atbl(n,0);
    for (auto& a:atbl){
        cin>>a;
    }
    int ans = 0;
    for (auto &a: atbl) {
        while (a % 2 == 0 || a % 3 == 2) {
			++ans;
			--a;
        }
    }
    cout<<ans<<endl;
    return 0;
}