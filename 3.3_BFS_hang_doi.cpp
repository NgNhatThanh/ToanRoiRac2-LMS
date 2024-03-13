#include <iostream>
#include <queue>
using namespace std;

int n, mtKe[6][6], vst[6];

void bfs(int vertex){
    queue<int> q;
    q.push(vertex);
    vst[vertex] = 1;
    while(!q.empty()){
        int u = q.front();
        cout << u << ' ';
        q.pop();
        for(int i = 1; i <= n; ++i){
            if(mtKe[u][i] && !vst[i]){
                q.push(i);
                vst[i] = 1;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    bfs(1);
}