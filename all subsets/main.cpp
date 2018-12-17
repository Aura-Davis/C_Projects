#include <iostream>
#include <unordered_set>
#include <string>
#include <math.h>

using namespace std;
int result_itter;

char** All_Subsets(char given_ar[], char subset [], int given_ar_itter, int subset_size,
                  int given_ar_size, char **result)
{
    //Do recursive calls for the subset to include or not include the elements from original array
    if(given_ar_itter < given_ar_size)
    {
        result = All_Subsets(given_ar, subset, given_ar_itter + 1, subset_size, given_ar_size, result);
        subset[subset_size] = given_ar[given_ar_itter];
        result = All_Subsets(given_ar, subset, given_ar_itter + 1, subset_size + 1, given_ar_size, result);
    }
    //When it reaches the end of original array load the elements to the subset array, store in 2d array, and return it
    else if (given_ar_itter == given_ar_size)
    {
        for (int i = 0; i < subset_size && subset[i] != NULL; i++)
        {
            result[result_itter][i] = subset[i];
        }
        result_itter++;
    }

    return result;
}

int main()
{
    // Get the full set and get the size of it
    char given_ar [] = {'l', 'o', 'v', 'e'};
    int given_ar_size = sizeof(given_ar)/sizeof(given_ar[0]);
    // The amount of subset you will have
    int rows = pow(2, given_ar_size);
    //create subsets with the maximum size of the original set
    char subset [given_ar_size];
    //create a 2d array to hold the subsets
    char **result = new char * [rows];

    //Initialize to null
    for (int itter = 0; itter < given_ar_size; itter++) subset[itter] = NULL;

    for (int i = 0; i < rows; i++) result[i] = new char[given_ar_size];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < given_ar_size; j++) result[i][j] = NULL;
    }

    //Call function to get subsets and store it to result variable
    result = All_Subsets(given_ar, subset, 0, 0, given_ar_size, result);

    //Print subsets
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < given_ar_size && result[i][j] != NULL; j++) cout << result[i][j];
        cout << endl;
    }
    return 0;
}
