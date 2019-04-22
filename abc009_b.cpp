//ABC009 B - 心配性な富豪、ファミリーレストランに行く。
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int> atbl(N);
    for (auto& a:atbl) {
		cin >> a;
	}
    std::sort(atbl.begin(), atbl.end(), greater<int>());
    auto ha = atbl[0];
    for (auto& a:atbl) {
        if (ha > a) {
			cout << a << endl;
			break;
        }
    }
    return 0;
}