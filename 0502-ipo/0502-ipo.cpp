class Solution {
public:
    int bin_ser(vector<pair<int,int>> vec, int left, int right, int w)
    {
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(vec[mid].first > w)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return left;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // unordered_set<int> left_indexes;
        // two heaps pattern
        priority_queue<int> pq1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;
        int n = profits.size();
        for(int i = 0; i < n; i++)
        {
            if(capital[i]<=w)
                pq1.push(profits[i]);
            else
                pq2.push({capital[i], profits[i]});
        }
        while(pq1.size() > 0 && k--)
        {
            int profit = pq1.top();
            w+=profit;
            pq1.pop();
            // below commented method doesn't work
            // for (auto it = left_indexes.begin(); it != left_indexes.end(); it++) 
            // {
            //     if(capital[*it]<=w){
            //         pq.push(profits[*it]);
            //         left_indexes.erase(it);
            //     }
            // }
            while(pq2.size() > 0)
            {
                auto next_project = pq2.top();
                if(next_project.first > w)
                    break;
                pq2.pop();
                pq1.push(next_project.second);
            }
        }
        return w;
    }
};