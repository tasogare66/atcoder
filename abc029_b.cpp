//ABC029 B - カキ
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int num=12;
    int cnt=0;
    for (int i=0;i<num;++i){
        string s;
        cin>>s;
        if (s.find('r') != string::npos) ++cnt;
    }
    cout<<cnt<<endl;
    return 0;
}
