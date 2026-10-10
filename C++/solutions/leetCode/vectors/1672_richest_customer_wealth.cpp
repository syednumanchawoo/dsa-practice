/*
Problem : 1672
Link: https://leetcode.com/problems/richest-customer-wealth/
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth = 0;
        for(const auto &customer : accounts){
            int current_wealth = 0;
            for(int amount : customer){
                current_wealth += amount;
            }
            wealth = std::max(wealth, current_wealth);
        }
        return wealth;
    }
};
