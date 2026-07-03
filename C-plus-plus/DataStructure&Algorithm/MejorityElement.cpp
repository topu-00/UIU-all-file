#include <iostream>
using namespace std;
int mejorityElement(vector<int> nums) // O(nlogn);
{
    int n = nums.size();
    // sort
    sort(nums.begin(), nums.end());

    // Freq count
    int freq = 1;
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
        }
        if (freq >= n / 2)
            return nums[i];
    }
}
int main()
{
    vector<int> nums = {3, 1, 2, 2};
    cout << mejorityElement(nums) << endl;
}