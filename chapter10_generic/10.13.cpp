#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& nums, int left, int right)
{
    if (left >= right) return;

    int pivot = nums[right];
    auto middle = partition(nums.begin() + left, nums.begin() + right + 1,
                            [pivot](int x) { return x < pivot; });
    int pos = distance(nums.begin(), middle);
    // 把 pivot 放到正确位置
    swap(nums[pos], nums[right]);

    quickSort(nums, left, pos-1);
    quickSort(nums, pos+1, right);
}

// 测试代码
int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    
    cout << "排序前: ";
    for (const auto& num : nums) cout << num << " ";
    cout << endl;
    
    quickSort(nums, 0, nums.size() - 1);
    
    cout << "排序后: ";
    for (const auto& num : nums) cout << num << " ";
    cout << endl;
    
    return 0;
}