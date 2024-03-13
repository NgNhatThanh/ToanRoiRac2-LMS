#include <iostream>
using namespace std;

int n, mtKe[6][6], vst[6];

void dfs(int u){
    vst[u] = 1;
    cout << u << ' ';
    for(int i = 1; i <= n; ++i){
        if(mtKe[u][i] && !vst[i]) dfs(i);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    dfs(1);
}