/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2)
            return true;
        vector<int> pt1 = coordinates[0];
        vector<int> pt2 = coordinates[1];
        float slope;
        bool vertical =false;
        int y2_y1 = pt2[1]-pt1[1];
        int x2_x1 = pt2[0]-pt1[0];

        if(x2_x1 != 0){
            slope = abs((float)(y2_y1)/(x2_x1));
            //cout<<"initial slope ="<<slope<<endl;
        }else{
            vertical = true;
        }

        for(int i =1; i < coordinates.size();i++){
            pt1=coordinates[i-1];
            pt2=coordinates[i];
            //cout<<pt1[0]<<" "<<pt1[1]<<endl;
            //cout<<pt2[0]<<" "<<pt2[1]<<endl;


            if(vertical){
                if(pt2[0] - pt1[0] != 0){
                    //cout<<"it is not a vertical line"<<endl;
                    return false;
                }
                continue;
            }
            else {
                y2_y1 = pt2[1]-pt1[1];
                x2_x1 =pt2[0]-pt1[0];
                float slope2 = abs((float)(y2_y1)/(x2_x1));
                if (slope != slope2){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){

   Solution s;
   std::cout<<std::boolalpha;

   //vector< vector<int> > cordinates = {{1,2} , {2,3},{3,4},{4,5},{5,6},{6,7}};
   //vector< vector<int> > cordinates = {{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};
   vector< vector<int> > cordinates = {{-2,12},{2,-8},{6,-28},{-10,52},{-7,37},{4,-18},{7,-33},{1,-3},{-1,7},{8,-38}};
   cout<<s.checkStraightLine(cordinates);
   return 0;
}
