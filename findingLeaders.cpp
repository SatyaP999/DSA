#include<bits/stdc++.h>
using namespace std;

//better approach TC = O(n) SC = O(n)
int findingLeaders(vector<int>& nums){
    map<int, int> numMap;
    int n = nums.size();

    for(int i=0; i<n; i++){
        numMap[nums[i]] += 1;
    }

    for(int i=0; i<n; i++){
        if(numMap[nums[i]] > n/2){
            return nums[i];
        }
    }
    return -1;

}
//Optimal approach TC O(N)
int findingLeadersMooresAlgo(vector<int>& a){
    int ele;
    int cnt = 0;

    for(int i=0; i<a.size(); i++){
        if(cnt == 0){
            cnt = 1;
            ele = a[i];
        }
        else if(a[i] == ele) cnt++;
        else cnt --;
    }
    int leadercnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] == ele) leadercnt++;
        if(leadercnt > a.size()/2) return ele; 
    }
    return -1;
}



int main(){

    vector<int> a = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    cout << findingLeadersMooresAlgo(a);
    return 0;
}