#include <iostream>
#include <queue>
using namespace std;

int n, s, t, mtKe[15][15], vst[15], path[15];

void dfs(int u){
    vst[u] = 1;
    for(int i = 1; i <= n; ++i){
        if(mtKe[u][i] && !vst[i]){
            path[i] = u; 
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
                q.push(i);
                path[i] = v;
            }
        }
    }
}

void inPath(int t){
    cout << t << ' ';
    while(path[t]){
        cout << path[t] << ' ';
        t = path[t];
    }
    cout << '\n';
}

int main(){
    cin >> n >> s >> t;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    dfs(s);
    if(!path[t]) cout << "no path";
    else{
        cout << "DFS path: ";
        inPath(t);
        for(int i = 1; i <= n; ++i) vst[i] = path[i] = 0;
        bfs(s);
        cout << "BFS path: ";
        inPath(t);
    }
}