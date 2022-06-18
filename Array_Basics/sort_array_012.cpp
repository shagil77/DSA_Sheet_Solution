// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    int zeroes=0, ones=0, twos=0;
    for(int i=0; i<n; i++) {
        if(a[i]==0) zeroes++;
        else if(a[i]==1) ones++;
        else twos++;
    }
    for(int i=0; i<zeroes; i++) a[i]=0;
    for(int i=zeroes; i<ones+zeroes; i++) a[i]=1;
    for(int i=ones+zeroes; i<ones+zeroes+twos; i++) a[i]=2;
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends