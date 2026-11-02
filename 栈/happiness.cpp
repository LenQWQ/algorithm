/*题目描述:这一天是小V 的生日，他收到了朋友们送给他的礼物。
现在，小V 有n 件礼物，他将这n 件礼物排成一排，依次编号为1 到n，每件礼物都有一个满意值w[i]。
现在小V 要从中选取连续编号的礼物（即选取[l, r]内的礼物），使得获得的 happiness 最大。
[l, r]内的 happiness 定义为：（[l, r]内所有礼物满意值的最小值）*（[l, r]内所有礼物满意值的和）
小V 想知道他能获得的 happiness 最大是多少，你能帮帮他吗？*/

/*思路：单调栈+前缀和，单调栈用来记录一个数在什么范围内是最小的数，最后遍历求出答案*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    vector<int> nums(n);
    stack<int> s;
    vector<int> right(n,n-1),left(n);
    for(int i=0;i<n;i++){
        int a;cin >> a;
        nums[i] = a;
    }
    for(int i=0;i<n;i++){
        while(!s.empty() && nums[i] <= nums[s.top()]){
            right[s.top()] = i-1;
            s.pop();
        }
        if(!s.empty()){
            left[i] = s.top()+1;
        }
        s.push(i);
    }
    long long ans = 0;
    vector<long long> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + nums[i-1];
    }
    for(int i=0;i<n;i++){
        ans = max(ans,(pre[right[i]+1]-pre[left[i]])*nums[i]);
    }
    cout << ans << endl;
    return 0;
}