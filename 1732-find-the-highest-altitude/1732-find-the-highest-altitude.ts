function largestAltitude(gain: number[]): number {
    var ans = 0,sum=0;
    for(var i=0;i<gain.length;i++)
        {
            sum += gain[i];
            if(sum>ans)ans=sum;
        }
    return ans;
};