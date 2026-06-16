//Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
//Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
//The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

//Approach for this  

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                for(int j = i+1;j<n-1;j++){
                    nums[j]=nums[j+1];
                }
                n--;
                i--;
            }
        }
        return n;
    }
};

//raverse the sorted array and check for adjacent duplicates. Whenever a duplicate is found, remove it by left-shifting all subsequent elements by one position.
//Decrease the effective size of the array and recheck the current index. Continue until all duplicates are removed. 
//The final size of the array represents the count of unique elements.
Time Complexity: O(n²) (due to repeated left shifts)
Space Complexity: O(1) (in-place modification)
