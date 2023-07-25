#include<bits/stdc++.h>
using namespace std;

//brute fore O(N^2)
int maxProfit(vector<int>& a){
    int max_profit = INT_MIN;
    for(int i=0; i<a.size(); i++){
        for(int j = i+1; j< a.size(); j++){
            int profit = -a[i] + a[j];
            if(max_profit < profit) max_profit = profit;
        }
    }
    return max_profit;
}

//Optimal solution O(N)
int maxProfitOptimal(vector<int>& a){
    int minPrice = INT_MAX;
    int max_profit = 0;
    for(int i=0; i<a.size(); i++){
        if(minPrice > a[i]) {
            minPrice = a[i];
        }
        max_profit = max(max_profit, a[i] - minPrice);
    }
    return max_profit;
}

int main(){

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfitOptimal(prices);
    return 0;
}