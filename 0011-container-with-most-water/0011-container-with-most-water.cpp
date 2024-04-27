class Solution {
public:
    int maxArea(vector<int>& height)
    {
          int area = 0;
        
          int i=0, j= size(height)-1;
          
          while(i<j)
          {
              int tmp = min(height[i],height[j]) * (j-i);
              area = max(area, tmp);
              
              if(height[i]<height[j])
                  i++;
              else
                  j--;
          }
        return area;
    }
};