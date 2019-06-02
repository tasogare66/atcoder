//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

struct Denk{
    vector<int> sw;
    int p=0;
    bool check(const vector<int>& onoff){
        int cnt=0;
        for(auto n:sw){
            if(onoff[n-1]) ++cnt;
        }
        return(cnt%2==p);
    }
};

int N,M;
vector<Denk> ds;
vector<int> onoff(11,0);
int ans=0;

bool judge(const vector<int>& sw)
{
    for(auto&& d:ds){
        if(!d.check(sw)) return false;
    }
    return true;
}

void check(int i, vector<int> sw){
    if (i >= N){//hantei
        if(judge(sw)){
            ++ans;
        }
        return;
    }
    //on
    sw[i]=0;
    check(i+1, sw);
    //off
    sw[i]=1;
    check(i+1, sw);
}

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>M;
    ds.resize(M);    
    for(auto&& d:ds){
        int k;
        cin>>k;
        for(int i=0;i<k;++i){
            int sw;
            cin>>sw;
            d.sw.push_back(sw);
        }
    }
    for(auto&& d:ds){
        cin>>d.p;
    }
    //全sw試す
    vector<int> sw(N,0);
    check(0,sw);
    cout<<ans<<endl;
    return 0;
}