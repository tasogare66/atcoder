//AtCoder ABC058 C - 怪文書 / Dubious Document
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    int n;
    cin>>n;
    vector<string> stbl(n);
    vector<int> pt(n,0);
    for(auto&& s:stbl){
        cin>>s;
        sort(s.begin(),s.end());
    }
    string ans;
    const string& base=stbl[0];
    for(int i=0;i<base.size();++i){
        bool flag=true;
        vector<int> tmp=pt;
        for(int no=1;no<stbl.size();++no){
            auto result = stbl[no].find(base[i],pt[no]);
            if(result != string::npos){
                tmp[no]=result+1;
            } else {
                flag=false;
                break;
            }
        }
        if(flag){
            ans.push_back(base[i]);
            pt=tmp;
        }
    }
    cout<<ans<<endl;
    return 0;
}