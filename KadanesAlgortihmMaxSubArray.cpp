#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& a){
   int maxSum = INT_MIN;
        if(a.size() == 1) return a[0];
        for(int i=0; i<a.size(); i++){
            int sum = 0;
            for(int j = i; j<a.size(); j++){
                sum += a[j];
                maxSum = max(maxSum, sum);
            }
        }
    return maxSum;
}

int kadanesAlgorithm(vector<int>& a){
    int max1 = INT_MIN, sum = 0;
    int start = 0, ansStart = -1, ansEnd = -1;
    for(int i=0; i<a.size(); i++){
        if(sum == 0) start = i;
        sum += a[i];
        if(sum > max1){
            max1 = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    //to consider the sum of an empty sub array
    // if(max1 < 0) max1 = 0;

    for(int i = ansStart; i <=ansEnd; i++){
        cout << " " << a[i];
    }
    cout << endl;
    return max1;
}

int main(){

    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int finalSum = kadanesAlgorithm(nums);
    std::cout << finalSum;
    return 0;
}

