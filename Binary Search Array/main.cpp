#include <iostream>

using namespace std;

//Search for an occurrence of a number and return the index
int Binary_Search (int *arr, int n, int x)
{
    int low = 0, high = n - 1, mid;
    /*Check the number at the midpoint of the array. If it matches return position. Else change range to the
    half of the array the number might be in and repeat. If number not found return -1*/
    while (low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == x) return mid;
        else if (x > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int First_Occurance (int *arr, int n, int x)
{
    int low = 0, high = n - 1, mid, result = -1;
    /*Check the number at the midpoint of the array. If it matches change range to
    beginning position of current range to position with found number and repeat. If no match found return -1*/
    while (low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == x)
        {
            result = mid;
            high = mid - 1;
        }
        else if (x > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int Last_Occurance (int *arr, int n, int x)
{
    int low = 0, high = n - 1, mid, result = -1;
    /*Check the number at the midpoint of the array. If it matches change range to
    position with found number to the end position of current range and repeat. If no match found return -1*/
    while (low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == x)
        {
            result = mid;
            low = mid + 1;
        }
        else if (x > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int All_Occurance (int * arr, int arr_size, int x)
{
    //Get the first occurrence
    int first = First_Occurance(arr, arr_size, x);
    if (first < 0) return 0;
    //If there is an occurrence return the difference between the first and last occurrence
    else return Last_Occurance(arr, arr_size, x) - first + 1;
}

int main()
{
    int arr [] = {2, 5, 7, 9, 9, 9, 15, 17};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int number = 9;

    cout << "An occurrence of " << number << " was found at position: " << Binary_Search(arr, arr_size, 9) << endl;
    cout << "The first occurrence of " << number << " was found at position: " << First_Occurance(arr, arr_size, 9) << endl;
    cout << "The last occurrence of " << number << " was found at position: " << Last_Occurance(arr, arr_size, 9) << endl;
    cout << "There are " << All_Occurance(arr, arr_size, 9) << " occurrences of " << number << endl;
    return 0;
}
