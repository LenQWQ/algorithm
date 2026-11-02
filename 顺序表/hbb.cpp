#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const int Head = 0,Tail = MAXN-1;
int nex[MAXN],pre[MAXN];
bool alive[MAXN];

int main(){
    nex[Head] = Tail;
    pre[Tail] = Head;
    int OP;
    cin >> OP;
    int n = 0;
    while(OP--){
        int op;cin >> op;
        if(op == 1){
            int Insert_id;cin >> Insert_id;
            int v = ++n;
            int p;
            if(alive[Insert_id]){p = Insert_id;}else{p = pre[Tail];}
            alive[v] = 1;
            int q = nex[p];
            nex[p]=v,pre[v]=p;
            pre[q]=v,nex[v]=q;
        }else{
            int a,count;cin >> a >> count;
            int now;
            if(a >= 1 && a <= MAXN && alive[a]){now = a;}else{now = nex[Head];}
            while(count-- && now != Tail){
                int q = nex[now];
                pre[q]=pre[now];
                nex[pre[now]]=q;
                alive[now] = 0;
                now = q;
            }
        }
    }
   if(nex[Head] == Tail){                         
        cout << 0;
        return 0;
    }
    bool first = true;                              
    for(int p = nex[Head]; p != Tail; p = nex[p]){
        if(!first) cout << ' ';
        cout << p;
        first = false;
    }
    return 0;
}