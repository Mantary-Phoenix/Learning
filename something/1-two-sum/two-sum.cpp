class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j, len, t;
        int flag = 1;
        vector<int> l;
        len = nums.size();
        //cout << nums[0] + nums[1];
        /*for(j=1; j<len; j++)
        {
            if(nums[i] + nums[j] >= target)
            {
                break;
            }
        }
        //cout << j;
        if(j==1)
            t = j;
        else
            t = j-1;*/
        for(i=0; i<len-1; i++)
        {
            for(j = 1; j<len; j++)
            {
                if(i==j) continue;
                if(nums[i] + nums[j] == target)
                {
                    l.push_back(i);
                    l.push_back(j);
                    flag = 0;
                    break;
                }
            }
            if(!flag)
                break;
        }
        return l;
    }
};