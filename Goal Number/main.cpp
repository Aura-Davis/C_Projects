#include <iostream>
#include <math.h>

using namespace std;

int ** print (int *** mem, int goal, int * wallet, int wallet_index, int ** result, int * subset, int &result_row, int subset_col)
{
    //If goal reaches 0 then the full subset of numbers needed to make the goal number has been found
    if (goal == 0)
    {
        //Set a row of the result array equal to the subset found, and increment the result row index
        for(int i = 0; i < subset_col; i++) result[result_row][i] = subset[i];
        result_row++;
    }

    if (goal >= 1)
    {
        //If current_sum is greater than 0 then the number in the current index of wallet belongs in the subset
        if (mem[goal][wallet_index][1] > 0)
        {
            //Add the current number in the index of wallet to the subset then call recurse with goal reduced by the number in
            //wallet index and subset_col incremented
            subset[subset_col] = wallet[wallet_index];
            print(mem, goal - wallet[wallet_index], wallet, wallet_index, result, subset, result_row, subset_col + 1);
        }

        //If prev_sum is greater than 0 then the number in the previous index of wallet should be included in subset
        if (mem[goal][wallet_index][2] > 0)
            //recurse with wallet_index decremented
            print(mem, goal, wallet, wallet_index - 1, result, subset, result_row, subset_col);

    }

    //Return the created 2d array containing subsets that add up to goal
    return result;
}

int goal_num (int wallet[], int goal, int wallet_size)
{
    int temp_goal, prev_sum, current_sum, wallet_index;
    //3d array for memoized results
    int *** mem = new int **[goal + 1];
    for (int i = 0; i <= goal; i++) mem[i] = new int * [wallet_size];
    for (int i = 0; i <= goal; i++)
    {
        for (int j = 0; j < wallet_size; j++) mem[i][j] = new int [3];
    }

    //Set the first index for each number in the wallet equal to 1 for base condition.
    //When temp_goal is decreased to 0 there is 1 combination to get goal number
    for (int i = 0; i < wallet_size; i++)
        mem[0][i][0] = 1;
    //Fill up memoized array from 1 to goal
    for (temp_goal = 1; temp_goal <= goal; temp_goal++)
    {
        //For each number in wallet set the amount of set the amount of ways to get goal by including or excluding that number
        for (wallet_index = 0; wallet_index < wallet_size; wallet_index++)
        {
            //Ways to get to temp_goal by adding the current number
            if (temp_goal - wallet[wallet_index] >= 0)
                current_sum = mem[temp_goal - wallet[wallet_index]][wallet_index][0];
            else
                current_sum = 0;
            //Ways to get to temp_goal not adding the current number
            if (wallet_index > 0)
                prev_sum = mem[temp_goal][wallet_index - 1][0];
            else
                prev_sum = 0;
            //Add sum of including and excluding ways together and fill memoized array with results
            mem[temp_goal][wallet_index][0] = current_sum + prev_sum;
            mem[temp_goal][wallet_index][1] = current_sum;
            mem[temp_goal][wallet_index][2] = prev_sum;
            //print current results
            cout << "current sum: " << mem[temp_goal][wallet_index][1] << " prev sum: " << mem[temp_goal][wallet_index][2] << " mem [temp_goal][number]: " << temp_goal << " " << wallet[wallet_index] << endl;
        }
    }

    //create result_row variable here so that it can be passed by reference to print function
    int result_row = 0;
    //create subset array here to put in stopping condition for printing
    int subset [goal];
    for (int i = 0; i < goal; i++) subset[i] = -1;
    //2d array to store the combinations of numbers from wallet that add up to goal
    int ** result = new int *[mem[goal][wallet_size - 1][0]];
    for (int i = 0; i < mem[goal][wallet_size - 1][0]; i++) result[i] = new int [goal];
    for (int i = 0; i < mem[goal][wallet_size - 1][0]; i++)
    {
        for (int j = 0; j < goal; j++) result[i][j] = NULL;
    }

    result = print(mem, goal, wallet, wallet_size - 1, result, subset, result_row, 0);

    for (int i = 0; i < mem[goal][wallet_size - 1][0]; i++)
    {
        for (int j = 0; result[i][j] != NULL; j++) cout << result[i][j] << " ";
        cout << endl;
    }
    //return sum of including and excluding ways to get to goal
    return mem[goal][wallet_size - 1][0];
}


int main()
{
    //number you want the subset to add up to
    int goal = 7;
    //array of numbers to use to create subsets that add up to goal
    int wallet [] = {3, 1, 2};
    //size of wallet array
    int wallet_size = sizeof(wallet)/sizeof(wallet[0]);
    cout << goal_num(wallet, goal, wallet_size) << endl;
    return 0;
}
