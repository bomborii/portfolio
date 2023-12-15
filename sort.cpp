
/*
    Fill in this block comment before submitting.
    Name: Joshua To
*/

#include <iostream>
#include <stdlib.h>

//min helper function
int findMinIndex(int *arr, int startIndex, int endIndex)
{
    int minIndex = startIndex;
    for (int i = startIndex; i < endIndex; i++)
    {   
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}


// You are not limited to these functions. 
// Write as many helpers as you want
// You might find it useful to overload and
// pass additional arguments, for example.

void selection_sort(int *arr, int n)
{
	// Your code here
    for (int i = 0; i < n; i++)
    {
        //find the index of min element in unsorted portion of array
        int minIndex = findMinIndex(arr, i, n);
        //swap the current element and min element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void merge_sort(int *arr, int n)
{
	// Your code here
    merge_sort_actual(arr, 0, n / 2, n - 1);
}
//I don't know how to do merge sort with only one parameter so I made a new subroutine
void merge_sort_actual(int *arr, int start, int mid, int end)
{
    // Your code here
    if (end - start == 1 || end - start == 0)
    {
        merge(arr, start, mid, end);
    }
    else
    {
        //left half of the array
        merge_sort_actual(arr, start, mid / 2, mid);
        //right half of the array
        merge_sort_actual(arr, mid + 1, mid + (mid / 2), end);
    }
}
//merge helper function
//start is first index of first array, mid is first index of 2nd array, and end is index of last element of 2nd array + 1
void merge(int *arr, int start, int mid, int end)
{
    end++;
    int index1 = start;
    int index2 = mid;
    int mergedArray [end - start] = {};
    for (int i = start; i < end; i++)
    {
        //compare the two current elements from arr1 and arr2 and place the lower value into mergedArray
        if (arr[index1] <= arr[index2])
        {
            mergedArray[i] = arr[index1];
            index1++;
            //if all the values from arr1 have been added to the mergedArray, we're done, and we will
            //add the remaining values from arr2 into mergedArray
            if (index1 == mid)
            {
                //i is the index of mergedArray, and j is the index of the array that still has values to insert into mergedArray
                i++;
                for (int j = index1; j < end; j++, i++)
                {
                    mergedArray[i] = arr[j];
                }
                //exit outer loop
                break;
            }
        }
        else
        {
            mergedArray[i] = arr[index2];
            index2++;
            //if all the values from arr2 have been added to the mergedArray, we're done, and we will
            //add the remaining values from arr1 into mergedArray
            if (index2 == end + 1)
            {
                i++;
                for (int j = index1; j < mid; j++, i++)
                {
                    mergedArray[i] = arr[j];
                }
                //exit outer loop
                break;
            }
        }
    }
    //copy the values from merged array which are now sorted into the real array that was passed in
    //this might be inefficient because I'm performing another linear operation, but I didn't know how to do it otherwise
    for (int i = start; i < end; i++)
    {
        arr[i] = mergedArray[i];
    }
}

void merge_sel_sort(int *arr, int n)
{
    // Your code here
}


int main()
{
    return 0;
}