//AtCoder ABC062 B - Picture Frame
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    int H,W;
    cin>>H>>W;
    vector<string> atbl(H);
    for(auto&& a:atbl){
        cin>>a;
    }
    cout<<string(atbl[0].size()+2,'#')<<endl;
    for(const auto & a:atbl){
        cout<<"#"<<a<<"#"<<endl;
    }
    cout<<string(atbl[0].size()+2,'#')<<endl;
    return 0;
}