#include<bits/stdc++.h>
using namespace std;

//brute force TC = O(n^2)
int lengthOfLongestSubArray(vector<int>& a, int k){

    int maxLen = 0;
    for(int i=0; i < a.size(); i++){
        int sum = 0;
        for(int j=i; j<a.size(); j++){
            sum += a[j];
            if(sum == k){
                maxLen = max(maxLen, j-i+1);
            }
        }
    }
    return maxLen;
}

//Better Solution using hashMap TC = O(n) and SC = O(n) this is the optimal solution when there
// negative numbers and 0's in the array
int lengthOfLongestSubArrayHashMap(vector<int>& a, int k){
    int sum = 0;
    int maxLen = 0;
    map<int, int> sumMap;
    for(int i=0; i<a.size(); i++){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }

        int rem = sum - k;
        if(sumMap.find(rem) != sumMap.end()){
            int len = i - sumMap[rem];
            maxLen= max(maxLen, len);
        }
        sumMap[sum] = i;
    }
    return maxLen;
}

//Optimal solution TC = O(2n) and SC = O(1) 
int lengthOfLongestSubArrayTwoPointers(vector<int>& a, int k){
    int low = 0, high = 0;
    int sum = a[0];
    int len = 0;

    while(high < a.size()){
        while(sum > k){
            sum -= a[low];
            low++;
        }
        if(sum == k){
            len = max(len , high-low+1);
        }
        high++;
        if(high < a.size()){
            sum += a[high];
        }
    }
    return len;
}


int main(){

    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    //cout << lengthOfLongestSubArray(nums, 6);
    //cout << lengthOfLongestSubArrayHashMap(nums, 6);
    cout << lengthOfLongestSubArrayTwoPointers(nums, 6);
    return 0;
}