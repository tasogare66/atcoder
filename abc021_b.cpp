//ABC021 B - 嘘つきの高橋くん
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    int a,b;
    int K;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N;
    cin>>a>>b;
    cin>>K;
    vector<int> ptbl(K);
    for(auto&&p:ptbl){
        cin>>p;
    }
    ptbl.push_back(a); //a,b入れる
    ptbl.push_back(b);
    auto tmp=ptbl;
    sort(tmp.begin(),tmp.end()); //sortしてから
	tmp.erase(std::unique(tmp.begin(), tmp.end()),tmp.end());
    if (tmp.size()==ptbl.size()) {
        cout<<"YES"<<endl;
    } else{
		cout << "NO" << endl;
	}
	return 0;
}