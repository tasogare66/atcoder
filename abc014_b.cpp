//ABC014 B - 価格の合計
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,X;
    cin>>n>>X;
    vector<int> atbl(n,0);
    for(auto& a:atbl) {
		cin >> a;
	}
    int ans = 0;
    for (auto& a:atbl) {
        if (X & 1) {
            ans += a;
        }
        X /= 2;
    }
    cout<<ans<<endl;
    return 0;
}