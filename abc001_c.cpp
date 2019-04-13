//ABC0001 C - 風力観測
#include <bits/stdc++.h>
using namespace std;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}
int main() {
    struct {
        const char* s;
        int st;
        int ed;
    } tbl[] = {
        {"NNE", 1125},
        {"NE"},
        {"ENE"},
        {"E"},
        {"ESE"},
        {"SE"},
        {"SSE"},
        {"S"},
        {"SSW"},
        {"SW"},
        {"WSW"},
        {"W"},
        {"WNW"},
        {"NW"},
        {"NNW"},
    };
    for(int i=0;i<array_size(tbl);++i){
        tbl[i].st = 1125 + 2250*i;
        tbl[i].ed = 3375 + 2250*i;
    }
    struct Wind {
        int l;
        int st;
        int ed;
    };
    std::vector<Wind> wtbl = {
        {0, 0, 2},
        {1, 3, 15},
        {2, 16, 33},
        {3, 34, 54},
        {4, 55, 79},
        {5, 80, 107},
        {6, 108, 138},
        {7, 139, 171},
        {8, 172, 207},
        {9, 208, 244},
        {10, 245, 284},
        {11, 285, 326},
        {12, 327, INT_MAX}
    };
#if 0
    for (int dis=0;dis<12000;++dis) {
        int ws = dis * 100 / 60;
        ws = (ws + 5) / 10;
        int level = 0;
        for (auto &wd : wtbl)
        {
            if (ws >= wd.st && ws <= wd.ed)
            {
                level = wd.l;
                cout << dis << ":" << level << endl;
                break;
            }
        }
    }
#endif    

    int deg=161, dis=8;
    cin>>deg>>dis;
    //level
    int ws = dis*100/60;
    ws=(ws+5)/10;
    int level=0;
    for (auto& wd: wtbl){
        if(ws >= wd.st && ws <= wd.ed){
            level=wd.l;
            break;
        }
    }
    //degree
    deg*=10;
    const char* sd = "N";
    if (level == 0)
        sd = "C";
    else {
        for (int i = 0; i < array_size(tbl); ++i)
        {
            if (deg >= tbl[i].st && deg < tbl[i].ed)
            {
                sd = tbl[i].s;
                break;
            }
        }
    }
    cout << sd << " " << level << endl;
    return 0;
}