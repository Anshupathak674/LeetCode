class Solution {
public:

// Given that we have only three distinct elements at most, it's evident that the smallest element will invariably occupy the first index, while the largest element will inevitably be positioned at the last index.

// Dividing our final array into three segments, we distinguish them as the smallest segment, the middle segment, and the largest segment. Employing swaps, we relocate the smallest elements to the first segment and the largest elements to the last segment, ensuring the middle segment remains unchanged. This holds true when the number of distinct elements is less than 3.

// This swapping approach may reduce the need for additional counting variables, thereby improving the space complexity to O(1). We can use while loop to achieve 1-pass.

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, i = 0;
        for(int i = 0; i < n; i++)
        {
            while(i >= left && i <= right && (nums[i]==0 || nums[i]==2))
            {
                if(nums[i]==0)
                    swap(nums[i], nums[left++]);
                else if(nums[i]==2)
                    swap(nums[i], nums[right--]);
            }
        }
    }
};