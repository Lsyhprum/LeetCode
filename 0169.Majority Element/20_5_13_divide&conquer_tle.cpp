# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return find(nums, 0, nums.size() - 1);
    }

private:
    int find(vector<int> nums, int start, int end){
        //base case
        if(start == end) return nums[start];

        int mid = (end - start) / 2 + start;
        int val1 = find(nums, start, mid);
        int val2 = find(nums, mid + 1, end);

        if(val1 == val2){
            return val1;
        }else{
            int countLeft = 0;
            int countRight = 0;
            for (int i = start; i <= end; i++)
                if(nums[i] == val1)
                    countLeft ++;
                else if (nums[i] == val2)
                    countRight ++;

            if(countLeft >= countRight)
                return val1;
            else
                return val2;
        }

    }
};

int main(){
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    cout << sol.majorityElement(v) << endl;
    return 0;
}