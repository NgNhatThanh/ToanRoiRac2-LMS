#include <iostream>
#include <vector>
#include <algorithm>
#define ppi pair<int, pair<int, int>>
#define fi first
#define se second
using namespace std;

int n, mtKe[14][14], par[14];

int find_par(int u){
    if(par[u] == u) return u;
    return par[u] = find_par(par[u]);
}

int join(int u, int v){
    u = find_par(u);
    v = find_par(v);
    if(u == v) return 0;
    par[u] = v;
    return 1;
}

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
        if(join(x.se.fi, x.se.se)){
            res += mtKe[x.se.fi][x.se.se];
            canh.push_back({min(x.se.fi, x.se.se), max(x.se.fi, x.se.se)});
        }
    }
    cout << "dH = " << res << '\n';
    for(auto x : canh) cout << x.fi << ' ' << x.se << '\n';
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        par[i] = i;
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    solve();
}