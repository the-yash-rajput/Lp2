#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g(100);
vector<bool> vis(100,0);
void dfs(int cur)
{
    if(vis[cur]==1)
        return;
    vis[cur] = 1;
    cout << cur << " ";
    for (auto i : g[cur])
    {
        if(!vis[i]){
            dfs(i);
        }
    }
}

void bfs(int cur){
    queue<int> q;
    q.push(cur);
    vis[cur] = 1;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout << ele << " ";
        for(auto i :g[ele]){
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

signed main()
{
    cout << "______________________________________________________\n";
    cout << "Enter the number of nodes:- ";
    int nodes;
    cin >> nodes;
    cout << "Enter the number of edges:- ";
    int edges;
    cin >> edges;
    
    cout << "Enter " << edges << " edges:- \n";
    for (int i = 1; i <= edges;i++){
        int u, v;
        cout << "Enter the " << i << " edge:- \n";
        cout << "u:- ";
        cin >> u;
        cout << "v:- ";
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start,c;
    cout << "Enter the starting node:- ";
    cin >> start;
    cout << "______________________________________________________\n";
    while(1){
        for (int i = 0; i < 100;i++)
            vis[i] = 0;
        cout << "MENU :-\n";
        cout << "1- DFS \n";
        cout << "2- BFS\n";
        cout << "0- EXIT\n";
        cin >> c;
        if (c == 1)
        {
            cout << "DFS Traversal:- \n";
            dfs(start);
        }
        else if(c==2){
            cout << "BFS Traversal:- \n";
            bfs(start);
        }
        else if(c==0){
            cout << "Exit Successfully :) \n";
            break;
        }
        else{
            cout << "Please Enter correct choise\n";
        }
        cout << "\n______________________________________________________\n";
    }
    return 0;
}