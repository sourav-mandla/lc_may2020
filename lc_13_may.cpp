/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:

    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
  string removeKdigits(string num , int k){
    string ans = "0";
    leastnumber(num,k,ans);
    int i;
     for( i=0; i<ans.length()-1;i++){
        if(ans[i] != '0')
            break;
    }
    return ans.substr(i,ans.length()-i);

    return ans;
  }
  void leastnumber(string in , int k , string& ans){
    if(k==0){
        ans.append(in);
        return;
    }
    if(k>=in.length()){
        return;
    }
    int minIndex =0;
    for(int i=1; i<=k;i++){
        if(in[i]<in[minIndex])
            minIndex=i;
    }
    ans.push_back(in[minIndex]);
    leastnumber(in.substr(minIndex+1, in.length()-minIndex), k-minIndex,ans);

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
   //string str = "121198";
   //string str = "10200"; int n=1;
   //string str = "1432219"; int n =3;
   string str = "10"; int n =2;

   cout<<s.removeKdigits(str,n);
   return 0;
}
