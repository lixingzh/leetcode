// 1) remember apis of HashMap
// 2) remember how to new HashMap
// 3) int[].length instead of int[].length()

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<> ();
        for( int loop = 0; loop < nums.length; ++loop)
        {
            if(false == map.containsKey(nums[loop]))
            {
                map.put(target - nums[loop], loop);
            }
            else
            {
                return new int[] {map.get(nums[loop]), loop};
            }
        }
        return null;
    }
}