//ABC023 B - 手芸王
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    int n;
    string s;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>n;
    cin>>s;
    string tmp="b";
    int cnt=0;
    while(tmp.size() < s.size()){
        ++cnt;
        if(cnt%3==1){
			tmp = "a" + tmp + "c";
		} else if(cnt%3==2){
			tmp = "c" + tmp + "a";
		} else if(cnt%3==0){
			tmp = "b" + tmp + "b";
        }
    }
    int ans=(tmp==s)?cnt:-1;
    cout<<ans<<endl;
    return 0;
}