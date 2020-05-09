/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.
*/
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long square =1;
        int i=1;
        while(square <= num)
        {
            square = i*i;
            if(square ==num)
                return true;
            i++;
        }
        return false;
    }
};
int main()
{
    Solution s;
    std::cout<<std::boolalpha;
    cout<<"25: "<<s.isPerfectSquare(25);
    cout<<endl;
    cout<<"14: "<<s.isPerfectSquare(14);
    return 0;

}
