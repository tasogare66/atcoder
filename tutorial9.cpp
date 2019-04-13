//ABC085C - Otoshidama
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
std::vector<int> ktbl = {1000,5000,10000};//小さい順
std::vector<int> ans;
int make_sum(int rest,int uidx, int num){
    int cnt=0;
    if (rest == 0)
    {
        if ((ans[0]+ans[1]+ans[2]) == num){
            cout << ans[2] << " " << ans[1] << " " << ans[0] << endl;
            exit;
            return 1;
        }
    }
    else
    {
        for (int i = uidx; i >= 0; i--)
        {
            if (rest >= ktbl[i])
            {
                ++ans[i];
                cnt += make_sum(rest-ktbl[i], i,num);
                if (cnt > 0) { return cnt; }//みつかったら終わり
                --ans[i];
            }
        }
    }
    return cnt;
}
int main(){
    int n, y;
    cin>>n;
    cin>>y;
    ans.resize(ktbl.size(),0);
    int cnt = make_sum(y,ktbl.size()-1,n);
    if (cnt == 0) cout<<"-1 -1 -1" <<endl;
    return 0;
}