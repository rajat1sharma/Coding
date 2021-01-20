void zigZag(int arr[], int n) {
	    // code here
	    bool flag=false;
	    for(int i=0;i<n-1;i++)
	    {
	        if(flag)
	        {
	            if(arr[i]<arr[i+1])
	            {
	                swap(arr[i],arr[i+1]);
	            }
	        }
	        else
	        {
	            if(arr[i]>arr[i+1])
	            {
	                swap(arr[i],arr[i+1]);
	            }
	        }
	        flag=!flag;
	    }
	    return;
	}