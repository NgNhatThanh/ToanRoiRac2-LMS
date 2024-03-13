#include <iostream>
using namespace std;

int n, mtKe[16][16], vst[16];

void dfs(int u){
    vst[u] = 1;
    for(int i = 1; i <= n; ++i){
        if(mtKe[u][i] && !vst[i]) dfs(i);
    }
}

int demTPLT(){
    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(!vst[i]){
            ++res;
            dfs(i);
        }
    }
    for(int i = 1; i <= n; ++i) vst[i] = 0;
    return res;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    int tplt = demTPLT();
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(mtKe[i][j]){
                mtKe[i][j] = 0;
                int cnt = demTPLT();
                if(cnt > tplt) cout << i << ' ' << j << '\n';
                mtKe[i][j] = 1;
            }
        }
    }
}