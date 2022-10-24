//
// Created by Oreofe Solarin on 10/18/22.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> solution;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; i < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    solution = {i, j};
                }
            }
        }
        return solution;

    };

};