class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        int ans = 0, maxim = 0;
        for(auto ch: s)
            mp[ch]++;
        for(auto itr: mp)
        {
            if(itr.second%2==0)
                ans+=itr.second;
            else
            {
                ans+=(itr.second - 1);
                maxim = max(maxim, itr.second);
            }
        }
        if(maxim!=0)
            ans++;
        return ans;
    }
};