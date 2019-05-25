//AtCoder ABC033 B - 町の合併
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
    cin>>N;
    vector<string> s(N);
    vector<int> p(N);
    int total=0;
    for (int i=0;i<N;++i) {
        cin>>s[i]>>p[i];
        total += p[i];
    }
    string name="atcoder";
    for (int i=0;i<N;++i) {
        if (total < p[i]*2){
			name = s[i];
		}
    }
	cout << name << endl;
	return 0;
}