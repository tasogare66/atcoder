//AtCoder ABC062 A - Grouping
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    vector<int> g1 = {1,3,5,7,8,10,12};
    vector<int> g2 = {4,6,9,11};
	vector<int> g3 = {2};
    int x,y;
    cin>>x>>y;
    auto check = [&](const vector<int>& v){
        bool f0 = find(v.begin(), v.end(), x) != v.end();
        bool f1 = find(v.begin(), v.end(), y) != v.end();
        return (f0&&f1);
    };
    bool ans = check(g1)||check(g2)||check(g3);
    cout<<(ans?"Yes":"No")<<endl;
	return 0;
}