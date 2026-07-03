#include <iostream>
using namespace std;
vector<int> pairSum(vector<int> nums, int target)
{
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    vector<int> ans;
    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum < target)
        {
            i++;
        }
        else if (pairSum > target)
        {
            j--;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}
int main()
{
    int target = 26;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = pairSum(nums, target);
    cout << "pairSum: " << ans[0] << "," << ans[1] << endl;
}