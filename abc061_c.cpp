    //AtCoder ABC061 C - Big Array
    #include <bits/stdc++.h>
    using namespace std;
    using ll=int64_t;

    int main() {
        ll N,K;
        cin>>N>>K;
        vector<pair<int,int>> arr(N);
        for(auto&& a:arr){
            cin>>a.first>>a.second;
        }
        sort(arr.begin(),arr.end());
        ll tmp=0;
        int ans=0;
        for(const auto& a:arr){
            tmp += a.second;
            if(tmp>=K){
                ans=a.first;
                break;
            }
        }
        cout<<ans<<endl;
        return 0;
    }