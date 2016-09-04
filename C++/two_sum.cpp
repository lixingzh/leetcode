class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> ump; // <val, index>
        //multimap<int, int> ump; // <val, index>
        // multimap cost more time than unordered_multimap while doing equal_range
        vector<int> ret;
        for(int loop = 0; loop < nums.size(); ++loop)
        {
            ump.insert(make_pair(nums[loop], loop));
        }
        
        for(int loop = 0; loop < nums.size(); ++loop)
        {
            //auto iter = ump.find(target - nums[loop]);
            //if(ump.end() != iter)
            {
                auto iter_pair = ump.equal_range(target - nums[loop]);
                for(auto iterator = iter_pair.first; iterator != iter_pair.second; ++iterator)
                {
                    if(iterator->second != loop)
                    {
                        ret.push_back(loop);
                        ret.push_back(iterator->second);
                        break;
                    }
                }
            }
            
            if(ret.size() > 0)
            {
                break;
            }
        }
        return ret;
    }
};

// Sort + Binary Search
// manipulaiton of multimap is more expensive than array manipulation
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> nums2(nums);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums2.size(); i ++) {
            bool found = false;
            if (binary_search(nums.begin(), nums.end(), target - nums2.at(i))) {
                for (int j = 0; j < nums2.size(); j ++) {
                    if (nums2.at(j) == target - nums2.at(i) and j != i) {
                        result.push_back(i);
                        result.push_back(j);
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
        }
        return result;
    }
};

// corner case:
// 1) select element itself
// 2) duplication exists