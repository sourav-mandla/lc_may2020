/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> umap;
        for(int num : nums){
            umap[num]++;
            if(umap[num] > nums.size()/2)
                return num;
        }
        return -1;
    }
    int MV_majorityElement(vector<int>& nums){
        // Using Moore's Voting Algorithm
        // which gets you majority element if it exists
        int majority_element = nums[0];
        int vote =0;
        for(int i=0 ; i <nums.size() ;i++){
            if(nums[i] == majority_element)
                vote++;
            else if(--vote ==0){
                majority_element = nums[i];
                vote =1;
            }
        }
     return majority_element;
    }
};
int main(){

   Solution s;
   vector<int> nums = {2,2,2,1,1,1,2};
   cout<<"Using map:";
   cout<<s.majorityElement(nums);
   cout<<endl;
   cout<<"Using Moore's Voting Algo:";
   cout<<s.MV_majorityElement(nums);
   return 0;
}
