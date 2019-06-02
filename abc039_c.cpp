//AtCoder ABC039 C - ピアニスト高橋君
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string S;   //d r mf s l s
    cin>>S;     //0123456789ab
    string piano="WBWBWWBWBWBW" "WBWBWWBWBWBW" "WBWBWWBWBWBW";//白黒白黒白白黒白黒白黒白
    int pt=0;
    while(strncmp(&piano[pt], &S[0], S.length())!=0){
        ++pt;
    }
    const string ans[]={
        "Do","",
        "Re","",
        "Mi",
        "Fa","",
        "So","",
        "La","",
        "Si",
    };
    cout<<ans[pt]<<endl;
    return 0;
}