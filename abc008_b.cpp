//ABC008 B - 投票
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    std::map<string,int> table;
    string name;
    for(int i=0;i<N;++i){
		cin >> name;
		auto it = table.insert(make_pair(name,1));
        if (!it.second){
			//重複してる
			++it.first->second;
		}
	}
    string ans;
    int max=0;
    for(auto& it:table){
		if(max < it.second) {
			max = it.second;
			ans = it.first; //copy
		}
	}
    cout<<ans<<endl;
	return 0;
}