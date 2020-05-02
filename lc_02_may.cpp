#include <iostream>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        int counter =0;
        for(char c : J){
            jewels.insert(c);
        }
        for(char c: S){

            if(jewels.find(c) != jewels.end())
                counter++;
        }
     return counter;
    }
    int better_numJewelsInStones(string J , string S){
       int jewel[128] = {0};
       for (char c : J){
        jewel[c]++;
       }
       int ans =0;
       for (char c : S){
       ans += jewel[c];
       }
       return ans;
    }
};
int main(){

   Solution s;
   cout<<"Jewels are "<<s.numJewelsInStones("aA", "aAAbbbb");
   cout<<endl;
   cout<<"Jewels are "<<s.numJewelsInStones("z", "ZZ");
   cout<<"\n A Better Approach \n";
   cout<<"Jewels are "<<s.better_numJewelsInStones("aA", "aAAbbbb");
   cout<<endl;
   cout<<"Jewels are "<<s.better_numJewelsInStones("z", "ZZ");
   return 0;
}
