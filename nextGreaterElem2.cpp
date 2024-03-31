class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        for(int i=2*n-1; i>=0; i--)
        {
            // we pop out all elements smaller than current element
            while(!s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }
            // if stack is empty means no greater element is there
            // if not empty we make answer at that index equal to top element
            if(!s.empty() && i<n)
            ans[i]=s.top();
            s.push(nums[i%n]);
        }
        return ans;
        
        // int n = nums.size();
        // std::set<int> clone(nums.begin(), nums.end()); // set already sorts it
        // std::vector<int> res(n, 0);
        // // std::sort(clone.begin(), clone.end());

        // for (int i = 0; i < n; i++) {
        //     // look for the bigger number in clone
        //     auto it = std::find(clone.begin(), clone.end(), nums[i]);
        //     auto nextElem = std::next(it, 1);
        //     if (nextElem != clone.end()) {
        //         res[i] = *nextElem;
        //     } else {
        //         res[i] = -1;
        //     }
        // }

        // return res;
    }
};
