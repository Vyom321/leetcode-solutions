Intuition
Using a hash set to count unique elements and comparing with the allowed limit.
Approach
Find the number of unique candy types using a set, and calculate how many candies Alice is allowed to eat (n/2).
Return the minimum of both — because she can't eat more unique types than her quota, and she can't eat more than what's available in unique types.
Complexity
Time complexity: O(N)

Code:

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> unique(candyType.begin() , candyType.end());
        int allowed = n/2;
        return min((int)unique.size(), allowed);
    }
};
