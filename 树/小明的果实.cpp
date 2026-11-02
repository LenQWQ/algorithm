/*题目描述：小明种了一棵果树，这棵树有 n 个节点，树根为 1 号节点，现在这颗果树上有 m 个节
点长出果实(根节点 1 有可能长出果实)，小明要从节点 1 出发采集这些果实，从一个节点爬
到相邻的另一个节点所需要的时间为 1，采集果实不需要时间，问小明如果要采集这 m 个果
实，从节点 1 出发，并且最后需要回到节点 1，最少需要多少的时间。*/

/*思路：因为最终都要回到根节点，所以每条子树都要来回遍历两次
先用BFS把节点遍历一遍，把每个子节点单独存起来，标记处每个节点的父节点
最后反向遍历子节点，只要该节点存在果实就要走一遍，所以把该节点的父节点也要标记为必须经过*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin >> n >> m;
    int ans = 0;
    vector<vector<int>> edge(n+1);
    vector<int> fruit(n+1,0);
    for(int i=0;i<n-1;i++){
        int start,end;cin >> start >> end;
        edge[start].push_back(end);
        edge[start].push_back(end); //由于是无向边必须存两次
    }
    for(int i=0;i<m;i++){
        int a;cin >> a;
        fruit[a] = 1;
    }
    bool vis[1000000] = {0};
    vis[1] = 1;
    vector<int> parent(n+1,0),order;
    queue<int> q;
    q.push(1);
    while(!q.empty()){ //开始BFS遍历
        int temp = q.front();q.pop();
        order.push_back(temp); //记录子节点
        for(int u : edge[temp]){
            if(!vis[u]){
                q.push(u);
                vis[u] = 1;
                parent[u] = temp; //记录父节点
            }
        }
    }
    for(int i = order.size()-1;i>=0;i--){
        int temp = order[i];
        if(fruit[temp] && temp != 1){ //当前节点必须有果实且不为根节点
            ans++; 
            fruit[parent[temp]] = 1; //该节点的父节点也要经过
        }
    }
    cout << ans * 2 << endl;
    return 0;
}