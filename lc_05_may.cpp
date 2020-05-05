/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int index[26] = {0};
        for (char c : s)
            index[c-97]++;

        for(int i=0 ; i <s.length();i++){
            if(index[s[i]-97]==1)
                return i;
        }
        return -1;
    }
};
int main(){

   Solution s;
   cout<<s.firstUniqChar("leetcode");
   cout<<endl;
   cout<<s.firstUniqChar("loveleetcode");
   return 0;
}
