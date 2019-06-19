//AtCoder ABC063 B - Varied
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string S;
    cin>>S;
    unordered_set<char> tbl;
    for(const auto& c:S){
		tbl.insert(c);
	}
    cout<<(S.size()==tbl.size()?"yes":"no")<<endl;
    return 0;
}