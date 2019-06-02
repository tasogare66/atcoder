//AtCoder ABC036 C - 座圧
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
    cin>>N;
    vector<int> intbl(N);
    unordered_set<int> aset;
    for(int i=0;i<N;++i){
        int a;
        cin>>a;
        intbl[i]=a;
        aset.insert(a);
    }
    vector<int> atbl(aset.size()); //set->vector
    int i=0;
    for(auto it=aset.begin();it!=aset.end();++it){
        atbl[i++]=*it;
    }
    std::sort(atbl.begin(),atbl.end()); //vector sort
    unordered_map<int,int> amap; //mapにいれる
    for(int i=0;i<atbl.size();++i){
        amap[atbl[i]]=i;
    }
    for(const auto& a:intbl){
        cout<<amap[a]<<endl;
    }
    return 0;
}