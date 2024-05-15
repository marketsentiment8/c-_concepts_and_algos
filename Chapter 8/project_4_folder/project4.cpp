#include <iostream>
#include <vector>

bool firstLast2(const std::vector<int>& nums) {
    if (!nums.empty() && (nums.front() == 2 || nums.back() == 2)) {
        return true;
    }
    return false;
}

int main() {
    // Test cases
    std::vector<int> nums1 = {2, 3, 4, 5};
    std::vector<int> nums2 = {1, 3, 4, 5, 2};
    std::vector<int> nums3 = {1, 2, 3, 4, 5};
    std::vector<int> nums4 = {1, 3, 4, 5};
    std::vector<int> nums5 = {2};
    std::vector<int> nums6 = {};

    std::cout << "Test Case 1: " << firstLast2(nums1) << std::endl;
    std::cout << "Test Case 2: " << firstLast2(nums2) << std::endl;
    std::cout << "Test Case 3: " << firstLast2(nums3) << std::endl;
    std::cout << "Test Case 4: " << firstLast2(nums4) << std::endl;
    std::cout << "Test Case 5: " << firstLast2(nums5) << std::endl;
    std::cout << "Test Case 6: " << firstLast2(nums6) << std::endl;

    return 0;
}
