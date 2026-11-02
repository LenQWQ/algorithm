#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a < b;
}
int main(){
    int n;cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int a;cin >> a;
        nums[i] = a;
    }
    sort(nums.begin(),nums.end(),cmp);
    int ans = 0;
    for(int i=0;i<(int)nums.size();i+=2){
        ans += nums[i+1] - nums[i];
    }
    cout << ans << endl;
    return 0;
}