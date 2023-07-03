#User function Template for python3
class Solution:

	def maxIndexDiff(self,arr,n):
		#code here
		mnl=[0]*n
		mxl=[0]*n
# 		print(mnl)
# 		print(mxl)
		mn = arr[0]
		for i in range(0,n):
		    mn=min(mn,arr[i])
		    mnl[i]=mn
		mx = arr[n-1]
		i=n-1
		while(i>=0):
		    mx=max(mx,arr[i])
		    mxl[i]=mx
		    i=i-1
		mx_len = 0
		i=0
		j=0
		while(j<n and i<n):
		    if(mnl[i]<=mxl[j]):
		        mx_len=max(mx_len,j-i)
		        j=j+1
		    else:
		        i=i+1
		return mx_len
        #return 0 

#{ 
 # Driver Code Starts
if __name__ == "__main__":
	t = int(input())
	while(t>0):
		num = int(input())
		arr = [int(x) for x in input().strip().split()]
		ob = Solution()
		print(ob.maxIndexDiff(arr,num))
		t-=1
# } Driver Code Ends