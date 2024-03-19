#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, st, mtKe[21][21], trace[21], vst[21];

void in(int en){
    vector<int> path;
    path.push_back(st);
    while(en){
        path.push_back(en);
        en = trace[en];
    }
    reverse(begin(path), end(path));
    for(int x : path) cout << x << ' ';
    cout << '\n';
}

void dfs(int u, int cnt = 1){
    for(int i = 1; i <= n; ++i){
        if(i == st && mtKe[u][i] && cnt == n){
            in(u);
            return;
        }
        if(mtKe[u][i] && !vst[i]){
            vst[i] = 1;
            trace[i] = u;
            dfs(i, cnt + 1);
            vst[i] = 0;
        }
    }
}

int main(){
    cin >> n >> st;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    vst[st] = 1;
    dfs(st);
}