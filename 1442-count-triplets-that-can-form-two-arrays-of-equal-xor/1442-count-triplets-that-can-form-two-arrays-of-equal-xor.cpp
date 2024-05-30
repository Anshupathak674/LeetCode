class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int x = 0, n = arr.size(), a, b, ans = 0;
        // vector<int> arrayXor;
        // for(int i = 0; i < n; i++){
        //     x^=arr[i];
        //     arrayXor.push_back(x);
        // }
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = i + 1; j < n; j++)
        //     {
        //         for(int k = j; k < n; k++)
        //         {
        //             int a, b;
        //             if(i-1<0)
        //                 a = arrayXor[j-1];
        //             else 
        //                 a = arrayXor[i-1]^arrayXor[j-1];
        //             b = arrayXor[k]^arrayXor[j-1];
        //             if(a==b)
        //                 ans++;
        //         }
        //     }
        // }
        for(int i = 0; i < n - 1; i++)
        {
            int p = arr[i];
            for(int j = i + 1; j < n; j++)
            {
                p^=arr[j];
                if(p==0)
                    ans+=(j-i);
            }
        }
        return ans;
    }
};