class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(),people.end());
        int minBoats = 0;
        int n = people.size();
        int i=0, j=n-1;
        
        while(i<=j)
        {
            if(i!=j)
            {
                if(people[i]+people[j]<=limit)
                {
                    minBoats++;
                    i++;j--;
                }
                else
                {
                    minBoats++;
                    j--;
                }
            }
            else
            {
                minBoats++;
                i++;
            }
        }
        return minBoats;
    }
};