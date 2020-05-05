/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
*/
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int no_of_bits = log2(num);
        cout<<no_of_bits<<"sizeof int "<<sizeof(int)<<endl;
        int mask = 1<<no_of_bits;
        mask = mask | (mask -1);
        cout<<"mask = "<<mask;
        return num^mask;
    }
};
int main(){

   Solution s;
   //cout<<s.findComplement(2147483647);
   cout<<s.findComplement(0);
   return 0;
}
