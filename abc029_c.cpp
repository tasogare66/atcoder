//ABC029 C - Brute-force Attack
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

void dfs(int idx, string& str){
    if (idx>=str.size()) {
        cout<<str<<endl;
        return;
    }
    for (auto c:{'a','b','c'}) {
        str[idx]=c;
        dfs(idx+1,str);
    }
}
int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin>>N;
    string tmp(N,0);
    dfs(0,tmp);
	return 0;
}
