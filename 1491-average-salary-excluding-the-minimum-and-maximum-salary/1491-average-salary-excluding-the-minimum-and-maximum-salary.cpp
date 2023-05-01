class Solution {
public:
    double average(vector<int>& salary) {
        
        double avg = 0.0;
        int n = salary.size(), sum=0;
        sort(salary.begin(),salary.end());
        for(int i=1;i<n-1;i++)sum+= salary[i];
        
        avg = sum/(double)(n-2);
        return avg;
    }
};