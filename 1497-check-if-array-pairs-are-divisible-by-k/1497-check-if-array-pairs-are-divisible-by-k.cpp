class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            mp[((arr[i]%k) + k) % k]++;
        if(mp.count(0) && mp[0]%2!=0)
            return false;
        int i = 1, j = k - 1;
        while(i <= j){
            if(mp[i]!=mp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};