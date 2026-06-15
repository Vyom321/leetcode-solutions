
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.


class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();
        int i = n-1;
        while(i >0 && nums[i-1] <= nums[i]){
            i--;
        }
        if(i == 0 )return true;
        for(int j = i ; j <(i+n)-1;j++){
            if(nums[j%n] > nums[(j+1)%n]){
                return false;
            }
        }
        return true;
    }
};
