#include <iostream>
using namespace std;

int n, mtKe[15][15], vst[15];

void dfs(int u){
    vst[u] = 1;
    for(int i = 1; i <= n; ++i){
        if(mtKe[u][i] && !vst[i]) dfs(i);
    }    
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(!vst[i]){
            ++res;
            dfs(i);
        }
    }
    cout << res;
}