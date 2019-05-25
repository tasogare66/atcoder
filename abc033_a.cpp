//AtCoder ABC033 A - 暗証番号
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    string n;
    cin>>n;
    bool same = (n[0]==n[1] && n[1]==n[2] && n[2]==n[3]);
    cout<<(same?"SAME":"DIFFERENT")<<endl;
    return 0;
}