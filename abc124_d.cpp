//
#include <bits/stdc++.h>
using namespace std;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}
int main() {
#if 1
    int n=5, k=1;
    string str="00010";
    cin >> n >> k;
    cin >> str;

    std::vector<int64_t> tbl;
    tbl.reserve(str.size());
    char nowc=1; //1-0-1-0-の数を格納していく
    int cnt=0;
    for (int i=0;i<str.size();++i) {
        if (str[i]==('0'+nowc)) ++cnt;
        else {
            tbl.push_back(cnt);
            cnt = 1;
            nowc = 1 - nowc; //0 or 1
        }
    }
    tbl.push_back(cnt);
    //1-0-1 ,1で終わってほしい
    if (tbl.size()%2==0)tbl.push_back(0);

    //累積和
    vector<int> sumtbl(tbl.size()+1,0);
    for(int i=0;i < tbl.size();++i){
        sumtbl[i+1] = sumtbl[i]+tbl[i];
    }
    int pick_num=2*k+1;
    int ans = 0;
    for (int i = 0; i < tbl.size(); i+=2)
    {
        int left = i;
        int right = min(left + pick_num, (int)tbl.size());
        ans = max(ans, sumtbl[right] - sumtbl[left]);
    }
    cout<<ans<<endl;
    return 0;
#else
    char c[] = {'0', '1'}; //1逆立ち
    int n=5, k=1;
    string str="00010";
#if 1
    cin>>n>>k;
    cin>>str;
#endif
    bool zero_st=false;
    if(str[0]=='0'){
        zero_st = true;
    }
    std::vector<int64_t> tbl;
    tbl.reserve(str.size());
    int cnt = 0;
    for(int64_t i=0;i<str.size()-1;++i){
        ++cnt;
        if (str[i] != str[i+1]) {
            tbl.emplace_back(cnt);
            cnt = 0;
        }
    }
    tbl.emplace_back(cnt+1);

    int64_t max=0;
    int count_num=2*k+1;
    int st_val = zero_st?-1:0;
    int64_t tmp = -1;
#if 1
    int64_t sum0 = 0;
    for (int j = 0; j < 2 * k + 1; ++j)
    {
        if (st_val + j < tbl.size() && st_val + j >= 0)
        {
            sum0 += tbl[st_val + j];
        }
    }
    for (int i = st_val+2; i < (int)tbl.size(); i += 2)
        int64_t sum = sum0;
        if (i-2>=0) sum0 -= tbl[i-2];
        if (i-1>=0) sum0 -= tbl[i-1];
        if (i+2*k-1<tbl.size()) sum0 += tbl[i+2*k-1];
        if (i+2*k<tbl.sie()) sum0 += tbl[i+2*k];
        if(max <= sum0){
            max = sum0;
        }
    }
}
#else
    for (int i = st_val; i < (int)tbl.size(); i += 2)
    {
        int64_t sum = 0;
        for(int j=0;j<2*k+1;++j){
            if (i+j<tbl.size() && i+j>=0) {
                sum += tbl[i + j];
            }
        }
        if(max <= sum){
            max = sum;
        }
    }
#endif
    cout<<max<<endl;
    return 0;
#endif
}