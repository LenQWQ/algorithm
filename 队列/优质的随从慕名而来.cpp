/*模拟酒馆战旗，三个随从可以合成一个金色随从，随后这个随从会给卖掉，容纳随从的格子有上限，求最后被卖掉的随从数量*/

/*用两个数组来模拟双端队列，队满时弹出首元素，并且在三连时维护队列，并用两个数组来存放随从，当这两个数组都有随从时就证明可以三连。*/

#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000001;      

int main(){
    int n, m;
    if(scanf("%d %d", &n, &m) != 2) return 0;
    if(m == 0){ printf("0"); return 0; } 
    vector<int> pre(n + 2), nex(n + 2), typ(n + 2, 0);
    vector<int> occ1(MAXV, 0), occ2(MAXV, 0);
    const int HEAD = 0, TAIL = n + 1; 
    nex[HEAD] = TAIL;  pre[TAIL] = HEAD;
    int sz = 0, tot = 0, golden = 0;
    for(int i = 0; i < n; ++i){
        int x;  scanf("%d", &x);
        if(occ1[x] && occ2[x]){
            int u = occ1[x], v = occ2[x];
            nex[pre[u]] = nex[u];  pre[nex[u]] = pre[u];  
            nex[pre[v]] = nex[v];  pre[nex[v]] = pre[v]; 
            occ1[x] = occ2[x] = 0;
            sz -= 2;
            ++golden;
            continue;
        }
        if(sz == m){
            int h  = nex[HEAD];
            int ht = typ[h];
            nex[pre[h]] = nex[h];  pre[nex[h]] = pre[h];
            --sz;
            if(occ1[ht] == h){ occ1[ht] = occ2[ht]; occ2[ht] = 0; } 
            else{ occ2[ht] = 0; }
        }
        int v = ++tot;
        typ[v] = x;
        int p = pre[TAIL];
        nex[p] = v;  pre[v] = p;
        nex[v] = TAIL;  pre[TAIL] = v;
        ++sz;
        if(occ1[x] == 0) occ1[x] = v;  else occ2[x] = v;
    }

    printf("%d\n", golden);
    return 0;
}