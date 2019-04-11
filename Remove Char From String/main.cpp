#include <iostream>

using namespace std;

string Remove_Char (string input, char removeChar)
{
    //Size of input string
    int inputSize = input.length();
    //Temporary variable to hold a char value for swapping
    char tempChar;
    //Number of characters to be removed
    int removeCount = 0;
    //Check all characters of input for character to be removed
    for (int i = 0; i < inputSize; i++)
    {
        //Update amount characters to be removed
        if (input[i] == removeChar) removeCount++;
        //Swap characters to keep with first occurring unwanted character if there is an unwanted character
        if (input[i] != removeChar && removeCount > 0)
        {
            //Search for first unwanted character
            for (int j = 0; j < i; j++)
            {
                //If unwanted character found swap and break loop
                if (input[j] == removeChar)
                {
                    tempChar = input[i];
                    input[i] = input[j];
                    input[j] = tempChar;
                    break;
                }
            }
        }
    }
    //New string size is the old string size minus the amount of unwanted characters
    int newSize = inputSize - removeCount;

    //Return truncated string
    return input.substr(0, newSize);
}

int main()
{
    //Test with unwanted characters in the middle of the string
    string input = "apple pie";
    char removeChar = 'p';
    cout << "Input is: " << input << endl << "With " << removeChar << " removed input is: ";
    cout << Remove_Char(input, removeChar) << endl << endl;

    //Test with unwanted characters at the beginning of the string
    input = "555number";
    removeChar = '5';
    cout << "Input is: " << input << endl << "With " << removeChar << " removed input is: ";
    cout << Remove_Char(input, removeChar) << endl << endl;

    //Test with unwanted characters at the end of the string
    input = "1234 abc %%%";
    removeChar = '%';
    cout << "Input is: " << input << endl << "With " << removeChar << " removed input is: ";
    cout << Remove_Char(input, removeChar) << endl << endl;

    //Test with empty string
    input = "";
    removeChar = 'h';
    cout << "Input is: " << input << endl << "With " << removeChar << " removed input is: ";
    cout << Remove_Char(input, removeChar) << endl;
    return 0;
}
