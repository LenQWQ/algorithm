/*TonyY 是一个word 小白，今天他对 word 中撤销和恢复功能特别感兴趣，玩耍了一个上午（mdzz~），现在他知道了它们的功能和快捷键：
撤销：ctrl+z，可以撤销最近 1 次之前的恢复和 input 操作。
恢复：ctrl+y，可以恢复最近1 次之前的撤销操作，但是 input 操作之前的撤销操作不能被恢复。
当然，TonyY 还要往里写东西，操作格式为 input str（str中不含空格，str长度为m，1=<m<=30）。
现在他对 word 玩耍了起来，想知道玩耍完的结果，你可以帮助他吗？*/

/*思路:使用两个栈，其中一个用来模拟写入的操作，一个用来存放撤销的内容，并且当输入恢复指令时将撤销栈中的内容返回到写入栈中*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    if(!(cin >> n)) return 0;
    vector<string> undoSt; 
    vector<string> redoSt; 
    string op, str;
    for(int i = 0; i < n; ++i){
        cin >> op;
        if(op == "input"){
            cin >> str;
            undoSt.push_back(str);
            redoSt.clear();          

        } else if(op == "ctrl+z"){
            if(!undoSt.empty()){ 
                redoSt.push_back(undoSt.back());
                undoSt.pop_back();
            }

        } else if(op == "ctrl+y"){
            if(!redoSt.empty()){           
                undoSt.push_back(redoSt.back());
                redoSt.pop_back();
            }
        }
    }
    if(undoSt.empty()){
        cout << "No output";
        return 0;
    }
    for(size_t i = 0; i < undoSt.size(); ++i){
        if(i) cout << ' ';
        cout << undoSt[i];
    }
    return 0;
}