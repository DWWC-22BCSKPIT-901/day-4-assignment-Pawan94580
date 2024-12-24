Ques 3 Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Program Code:
#include <vector>

class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        prefix_sums.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sums[i + 1] = prefix_sums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sums[right + 1] - prefix_sums[left];
    }

private:
    std::vector<int> prefix_sums;
};

#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    std::cout << numArray.sumRange(0, 2) << std::endl; 
    std::cout << numArray.sumRange(2, 5) << std::endl; 
    std::cout << numArray.sumRange(0, 5) << std::endl; 

    return 0;
}
