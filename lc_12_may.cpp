/*
 You are given a sorted array consisting of only integers where every element appears exactly twice,
 except for one element which appears exactly once. Find this single element that appears only

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans =0;
        for(int i : nums){
            ans = ans^i;
        }
        return ans;
    }
};
static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
int main(){
   Solution s;
   std::cout << std::boolalpha;  // set the boolalpha var in std stream to print the string form of booleans
   vector<int> nums = {3,3,7,7,10,11,11};
   cout<<"\nPrint the odd number"<<endl;
   cout<<s.singleNonDuplicate(nums);

   return 0;
}
