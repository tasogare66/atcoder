//AtCoder ABC051 C - Back and Forth
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
struct Pos{
    int x=0,y=0;
};
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    Pos st,ed;
    cin>>st.x>>st.y;
    cin>>ed.x>>ed.y;
    auto difx=ed.x-st.x;
    auto dify=ed.y-st.y;
    //1
    cout<<string(dify,'U');
    cout<<string(difx,'R');
    //2
    cout<<string(dify,'D');
    cout<<string(difx,'L');
    //3
    cout<<"L"<<"U";
    cout<<string(dify,'U');
    cout<<string(difx,'R');
    cout<<"R"<<"D";
    //4
    cout<<"R"<<"D";
    cout<<string(dify,'D');
    cout<<string(difx,'L');
    cout<<"L"<<"U";
    cout<<endl;
    return 0;
}