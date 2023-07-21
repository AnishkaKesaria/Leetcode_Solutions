//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int index = i;
      int leftIndex = 2*i + 1;
      int rightIndex = 2*i + 2;
      
      int largest = index;
      
      if(leftIndex<n && arr[largest]<arr[leftIndex])
          largest = leftIndex;
    
        if(rightIndex<n && arr[largest]<arr[rightIndex])
            largest = rightIndex;
        
        if(largest!=index)
        {
            swap(arr[largest], arr[index]);
            heapify(arr, n, largest);
        }
        
        return;
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i=n/2 - 1; i>=0; i--)
            heapify(arr, n, i);
        return;
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        while(n>0)
        {
            swap(arr[0], arr[n-1]);
            heapify(arr, n-1, 0);
            n--;
        }
        return;
        
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends