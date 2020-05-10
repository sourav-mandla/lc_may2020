/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> arr(N+1,0);
        int potential_judge = N+1;
        for(int i =0; i < trust.size();i++){
            if(++arr[trust[i][1]] == N-1){
                 potential_judge = trust[i][1];
            }
        }
        if(potential_judge != N+1){

            for(int i=0; i < trust.size();i++){
                if(trust[i][0] == potential_judge)
                    return -1;
            }
            return potential_judge;
        }
        return -1;
    }

};

int main(){
   Solution s;
   std::cout << std::boolalpha;  // set the boolalpha var in std stream to print the string form of booleans
   //vector<vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
   vector<vector<int>> trust ={{1,3},{2,3},{3,1}};
   cout<<s.findJudge(4, trust);
   return 0;
}
