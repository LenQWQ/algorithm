/*某部队进行新兵队列训练，将新兵从一开始按顺序依次编号，并排成一行横队，
训练的规则如下：从头开始一至二报数，凡报到二的出列，剩下的向小序号方向靠拢，再从头开始进行一至三报数，凡报到三的出列，
剩下的向小序号方向靠拢，继续从头开始进行一至二报数…以后从头开始轮流进行一至二报数、
一至三报 数直到剩下的人数不超过三人为止。*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    if(scanf("%d", &T) != 1) return 0;
    while(T--){
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int i = 0; i < n; ++i) a[i] = i + 1;  
        int k = 2;                               
        while((int)a.size() > 3){
            vector<int> b;
            b.reserve(a.size());
            for(int i = 0; i < (int)a.size(); ++i)
                if((i + 1) % k != 0)          
                    b.push_back(a[i]);
            a.swap(b);
            k = (k == 2 ? 3 : 2);               
        }
        for(int i = 0; i < (int)a.size(); ++i){
            if(i) putchar(' ');
            printf("%d", a[i]);                  
        }
        putchar('\n');
    }
    return 0;
}