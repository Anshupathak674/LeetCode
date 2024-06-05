class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            int charCount = INT_MAX;
            for(int i = 0; i < n; i++)
            {
                int count = 0;
                for(char cr: words[i])
                {
                    if(cr == ch)
                        count++;
                }
                charCount = min(charCount, count);
            }
            for(int j = 0; j < charCount; j++)
            {
                string s(1, ch);
                ans.push_back(s);
            }
        }
        return ans;
    }
};