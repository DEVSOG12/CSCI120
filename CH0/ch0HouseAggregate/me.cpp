//
// Created by Oreofe Solarin on 9/10/22.
//
#include <vector>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // let's have two for loops
        // int len = *(&nums + 1) - nums;
        std::vector<int> ans;
        for(int i; i < nums.size(); i++ ){
            for(int j; i < nums.size(); j++) {
                if(nums[i] + nums[j] == target){
                    if (i < j){
                        ans = {i,j};

                    }else{
                        ans = {j, i};
                    }
                }
            }

        }

        return ans;
    }
};