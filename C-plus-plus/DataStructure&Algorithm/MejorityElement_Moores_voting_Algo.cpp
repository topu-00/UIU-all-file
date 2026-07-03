#include <iostream>
using namespace std;
int mejorityElement(vector<int> nums) // O(n);
{
    int n = nums.size();
    // Freq count
    int freq = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) // Moore's Voting algo;
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {3, 1, 2, 2, 3, 3, 3, 1, 2, 4, 1, 2, 1, 1, 1, 3, 3, 3, 3, 3, 3};
    cout << mejorityElement(nums) << endl;
}