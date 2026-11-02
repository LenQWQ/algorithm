#include<bits/stdc++.h>
using namespace std;

deque<int> nums;

int main(){
    int n,m,x;
    cin >> n >> m >> x;
    for(int i=1;i<=n;i++){
        nums.push_back(i);  
    }
    while(m--){
        int D;cin >> D;
        reverse(nums.begin()+D-1,nums.begin()+n-D+1);
    }
    cout << *(nums.begin() + x -1) << endl;
    return 0;
}