class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int mxArea = 0;
        int i=0, j =height.size()-1;
        while(i<=j)
{
    // compute Area for each (i,j)
    int h = min(height[i],height[j]), w = j-i;
    mxArea = max(mxArea, h*w);
        
    // 8,7 
    
    if(height[i]>height[j])
    {
        
        j--;
    }
    else
    {
        i++;
    }
}
//         for(int i=0;i<height.size();i++)
//         {
//             for(int j=i+1;j<height.size();j++)
//             {
                
//                 // i to j: 
//                 int w = j-i, h = min(height[i],height[j]);
//                 int area = w*h;
//                 mxArea = max(mxArea, area);
//             }
//         }
        return mxArea;
    }
};

//i=0; => [(1,0)]
//i=1; 8,1 [(8,1)] => 7
//i=2; 6,2 [(8,1)] => 6
// i=3 2,3 [(8,1)] => 4
// i=4 5,4 [(8,1)] => 15
// i=5 4,5 [(8,1)] => 16
// i=6 9,6 [(9,6)] => 40
// i=7 3,7 [(9,6)] => 3
// i=8 7,8 [(9,6)] => 14



