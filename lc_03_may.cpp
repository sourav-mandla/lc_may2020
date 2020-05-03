/*
Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/
#include <iostream>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    bool isSubString(string ransomNote, string magazine)
    {
        if(ransomNote.length()==0 || magazine.length()==0)
            return false;
        if(ransomNote.length() > magazine.length())
            return false;
        for(int i=0 ; i < magazine.length(); i++)
        {
            int j =0;
            int k;
            if(magazine[i] == ransomNote[j])
            {
                k=i;
                while( (ransomNote[j] != '\0') && (magazine[j] != '\0') && (ransomNote[j] == magazine[i]) )
                {
                    i++;
                    j++;
                }
                if(j == ransomNote.length())
                {
                    cout <<"String found"<<endl;
                    return true;
                }
                else
                {
                    i =k;
                    k=0;
                }
            }

        }
        return false;
    }
    bool canConstruct(string ransomNote, string magazine)
    {
        int lettersCount_magazine[26] = {0};
        for(char c: magazine)
        {
            ++lettersCount_magazine[c-97];
        }
        for(char c: ransomNote)
        {
            if(--lettersCount_magazine[c-97] < 0)
            {
                cout<<"Returning false";
                return false;
            }
        }

        cout<<"Return true !!";
        return true;
    }

};
int main(){

//"fffbfg"
//"effjfggbffjdgbjjhhdegh"
   Solution s;
   s.canConstruct("fffbfg","effjfggbffjdgbjjhhdegh");
   s.canConstruct("a","");
   return 0;
}
