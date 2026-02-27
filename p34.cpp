#include <vector>

using namespace std;
/*
34. Find First and Last Position of Element in Sorted Array
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findleft(nums, target);
        int right = findright(nums, target);
        return {left, right};
    }
private:
    int findleft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int res = -1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                res = mid;
                right = mid -1; 
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid -1;
            }
        }
        return res;
    }
    int findright(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int res = -1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                res = mid;
                left = mid + 1; 
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid -1;
            }
        }
        return res;
    }
};