#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, st, mtKe[14][14], vst[14];

void dfs(int u){
    vst[u] = 1;
    for(int i = 1; i <= n; ++i){
        if(mtKe[u][i] && !vst[i]){
            cout << min(u, i) << ' ' << max(u, i) << '\n';
            dfs(i);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    vst[u] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 1; i <= n; ++i){
            if(mtKe[v][i] && !vst[i]){
                vst[i] = 1;
                cout << min(v, i) << ' ' << max(v, i) << '\n';
                q.push(i);
            }
        }
    }
}

int main(){
    cin >> n >> st;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    cout << "DFS tree\n";
    dfs(st);
    memset(vst, 0, sizeof(vst));
    cout << "BFS tree\n";
    bfs(st);
}