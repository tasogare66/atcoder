//ABC028 C - 数を3つ選ぶマン
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int num[5];
    for (auto&n:num) {
        cin>>n;
    }
    int v0 = num[4]+num[3]+num[0];
    int v1 = num[4]+num[2]+num[1];
    cout<<max(v0,v1)<<endl;
    return 0;
}