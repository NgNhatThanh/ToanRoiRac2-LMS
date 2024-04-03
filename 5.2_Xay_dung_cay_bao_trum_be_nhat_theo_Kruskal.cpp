#include <iostream>
#include <vector>
#include <algorithm>
#define ppi pair<int, pair<int, int>>
#define fi first
#define se second
using namespace std;

int n, mtKe[14][14], vst[14];

void solve(){
    vector<ppi> v;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(mtKe[i][j]) v.push_back({mtKe[i][j], {min(i, j), max(i, j)}});
        }
    }
    sort(begin(v), end(v));
    int res = 0;
    vector<pair<int, int>> canh;
    for(auto x : v){
        if(vst[x.se.fi] && vst[x.se.se]) continue;
        res += x.fi;
        canh.push_back({x.se.fi, x.se.se});
        vst[x.se.fi] = vst[x.se.se] = 1;
    }
    cout << "dH = " << res << '\n';
    for(auto x : canh) cout << x.fi << ' ' << x.se << '\n';
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    solve();
}