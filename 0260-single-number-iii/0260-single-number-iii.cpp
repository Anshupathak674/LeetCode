class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, n = nums.size(), bucket1 = 0, bucket2 = 0;
        for(int i = 0; i < n; i++)
            x^=nums[i];
        int rightMostSetBit = 1;
        for(int i = 0; i < 32; i++)
        {
            if(rightMostSetBit & x)
                break;
            rightMostSetBit <<= 1;
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] & rightMostSetBit)
                bucket1^=nums[i];
            else
                bucket2^=nums[i];
        }
        return {bucket1, bucket2};
    }
};