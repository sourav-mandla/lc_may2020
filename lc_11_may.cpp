/*
 An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Input:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <chrono>
#include <thread>
using namespace std;
//#define DEBUG

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int start_value = image[sr][sc];
        if(start_value == newColor)
            return image;
        int rows = image.size();
        int cols = image[0].size();
        reallyFill(image , rows, cols, sr ,sc , newColor , start_value);
        #ifdef DEBUG
        for(int i=0; i <rows ;i++){
            for(int j=0; j< cols ;j++)
                cout<<image[i][j]<<" ";
            cout<<endl;
        }
        #endif // DEBUG
        return image;
    }
private:
    void reallyFill(vector<vector<int>>& image , int rows , int cols , int sr , int sc ,
                    int newColor , int start_value){

       if(sr < 0 || sr >= rows || sc < 0 || sc >= cols)
                        return ;
       if(image[sr][sc] != start_value)
        return;
        #ifdef DEBUG
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout<<"sr ="<<sr<<", sc="<<sc<<"filling the color"<<endl;
        #endif // DEBUG
        image[sr][sc]= newColor;
       //UP
       reallyFill(image ,rows,cols, sr-1,sc, newColor , start_value);
       // right
       reallyFill(image ,rows,cols, sr,sc+1, newColor , start_value);
       // down
       reallyFill(image ,rows,cols, sr+1,sc, newColor , start_value);
       //left
       reallyFill(image ,rows,cols, sr,sc-1, newColor , start_value);
    }

};

int main()
{
    Solution s;
    std::cout << std::boolalpha;  // set the boolalpha var in std stream to print the string form of booleans

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    //vector<vector<int>> image={{0,0,0},{0,1,1}};  // special case
    vector<vector<int>> filled_Image = s.floodFill(image, 1,1,2);

    int rows = filled_Image.size();
    int cols = filled_Image[0].size();
    for(int i=0; i <rows ; i++)
    {
        for(int j=0; j< cols ; j++)
            cout<<filled_Image[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
