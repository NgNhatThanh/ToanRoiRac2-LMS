#include <iostream>
#include <stack>
using namespace std;

int n, mtKe[6][6], vst[6];

void dfs(int vertex){
    stack<int> st;
    st.push(vertex);
    cout << vertex << ' ';
    vst[vertex] = 1;
    while(!st.empty()){
        int u = st.top();
        int ok = 0;
        for(int i = 1; i <= n; ++i){
            if(mtKe[u][i] && !vst[i]){
                st.push(i);
                vst[i] = 1;
                ok = 1;
                cout << i << ' ';
                break;
            }
        }
        if(!ok) st.pop();
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    dfs(1);
}