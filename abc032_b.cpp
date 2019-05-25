//AtCoder ABC032 B - 高橋君とパスワード
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int main() {
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
	string s;
	int k;
	cin>>s;
	cin>>k;
	unordered_set<string> list;
	for(int i=0;i+k<=s.size();++i){
		string p(&s[i],k);
		list.insert(p);
	}
	cout<<list.size()<<endl;
    return 0;
}