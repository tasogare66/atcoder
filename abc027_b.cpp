//ABC027 B - 島と橋
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    int N;
    cin>>N;
    vector<int> atbl(N);
    int total=0;
    for(auto&& a:atbl){
        cin>>a;
        total += a;
    }
    int ans=-1;
    if (total % N == 0){
        int ave = total/N;
        ans=0;
        int num=0;
        int sum=0;
        for (int i=0;i<atbl.size();++i) {
            sum+=atbl[i];
            ++num;
            if (sum==ave*num) {
                num=0;
                sum=0;
            } else {
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}