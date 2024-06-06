class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)
            return false;
        sort(hand.begin(), hand.end());
        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[hand[i]]++;
        for(int i = 0; i < n; i++){
            if(mp[hand[i]]==0)
                continue;
            mp[hand[i]]--;
            for(int j = 0; j < groupSize - 1; j++)
            {
                int find = hand[i] + j + 1;
                if(!mp.count(find)||mp[find]==0)
                    return false;
                mp[find]--;
            }
        }
        return true;
    }
};