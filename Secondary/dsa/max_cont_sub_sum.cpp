
int kadane(int a[],int n)
{
    int mi=a[0],mi_g=a[0];
    for(int i=1;i<n;i++)
    {
        mi=max(a[i],mi+a[i]);
        mi_g=max(mi_g,mi);
    }
    return mi_g;
}
int circularSubarraySum(int arr[], int num){
    
    // your code here
    
    int ans=kadane(arr,num);
    int sum=0;
    int flag=1;
    for(int i=0;i<num;i++)
    {
        if(arr[i]>0)/// very important if all negative elements then answer is max_kadane
        flag=0;
        sum+=arr[i];
        arr[i]*=-1;
    }
    int ans1=kadane(arr,num);
    //cout<<ans<<" "<<sum<<" "<<ans1<<endl;
    if(flag==1)
    return ans;
    else
    return max(ans,sum+ans1);
    
}