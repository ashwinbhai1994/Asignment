int minUnfairness(int k, int n, int* arr) 
{
    int i=0;
    int j=0;
    int min=9999;
    int temp=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }     
    }
    for(i=0;i<=n-k;i++)
    {
        temp = arr[i+k-1]-arr[i];
        if(temp < min)
        {
            min = temp;   
        }
    }
    return min;
}
