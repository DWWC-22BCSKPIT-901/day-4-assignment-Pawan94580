Ques 4. Given a 2D image img[][] where each img[i][j] is an integer representing the color of that pixel, also given the location of a pixel (x, y) and a new color newClr, the task is to replace the existing color of the given pixel and all the adjacent same-colored pixels with the given newClr.


Program Code:
#include <vector>
#include <queue>
#include <iostream>

class Solution {
public:
    void floodFillHelper(std::vector<std::vector<int>>& image, int x, int y, int oldColor, int newColor) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != oldColor) {
            return;
        }
        
        image[x][y] = newColor;
        
        floodFillHelper(image, x + 1, y, oldColor, newColor); // down
        floodFillHelper(image, x - 1, y, oldColor, newColor); // up
        floodFillHelper(image, x, y + 1, oldColor, newColor); // right
        floodFillHelper(image, x, y - 1, oldColor, newColor); // left
    }
    
    void floodFill(std::vector<std::vector<int>>& image, int x, int y, int newColor) {
        int oldColor = image[x][y];
        if (oldColor != newColor) {
            floodFillHelper(image, x, y, oldColor, newColor);
        }
    }
};

int main() {
    std::vector<std::vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int x = 1, y = 1, newColor = 2;
    
    Solution().floodFill(image, x, y, newColor);
    
    for (const auto& row : image) {
        for (int color : row) {
            std::cout << color << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
