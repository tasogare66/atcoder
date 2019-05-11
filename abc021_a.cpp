//ABC021 A - 足し算
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    int tbl[]={8,4,2,1};
    vector<int> ans;
    for (const auto& v:tbl){
        while(N>=v){
            N-=v;
            ans.push_back(v);
        }
    }
    cout<<ans.size()<<endl;
    for(auto&& a: ans){
        cout<<a<<endl;
    }
    return 0;
}