//ABC049C - 白昼夢 / Daydream
#include <bits/stdc++.h>
using namespace std;
bool check_syuutan(int index, string& str,const string& c){
    for (int i = 0; i < c.length(); ++i)
    {
        if (index - i - 1 >= 0 && str.data()[index - i - 1] != c.data()[c.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main(){
    string str="dreameraser";
    cin>>str;
    array<string,4> tbl = {"dream","dreamer","erase","eraser"};
    //cout << str <<endl;
    int index = str.length();
    while(index>0){
        bool ff = false;
        for(auto& s: tbl){
            if(check_syuutan(index, str, s)) {
                //del
                index -= s.length();
                ff=true;
                break;
            }
        }
        if(!ff)break;//終わり
    }
    if (index == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}