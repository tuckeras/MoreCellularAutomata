#include "automata.h"

#include <iostream>

namespace Automata {

    //This function initializes the array with one true value in the center. Called in main
    void initArray(bool arr[79])
    {
        for (int i = 0; i < 79; i++)
        {
            if (i == 39)
            {
                arr[i] = true;
            }
            else
            {
                arr[i] = false;
            }
        }
    }

    //Loops through every value in the array and prints. Called in main
    void printArray(bool arr[79])
    {
        for (int i = 0; i < 79; i++)
        {
            if (arr[i])
            {
                std::cout << "x";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    /*
    Takes an array of bools and a rule as input.
    Rules input is found in main.
    */
    void updateArray(bool arr[79], int rule)
    {
        // Temp array is created and assigned a value based on a rule
        bool temp[79];



        //Switches through different cases of the rules
        switch (rule)
        {

        case 126: // completed
            for (int i = 0; i < 79; i++)
            {
                //special exceptions where normal logic doesn't apply
                if (i == 0 || i == 78)
                {
                    if (i == 0)
                    {
                        if (arr[i] || arr[i + 1])
                        {
                            temp[i] = true;
                        }
                        else
                        {
                            temp[i] = false;
                        }
                    }
                    else
                    {
                        if (arr[i - 1] || arr[i])
                        {
                            temp[i] = true;
                        }
                        else
                        {
                            temp[i] = false;
                        }
                    }
                }
                else
                    //Checks with normal logic
                {
                    if (arr[i] || arr[i - 1] || arr[i + 1])
                    {
                        if (arr[i] && arr[i - 1] && arr[i + 1])
                        {
                            temp[i] = false;
                        }
                        else
                        {
                            temp[i] = true;
                        }
                    }
                    else
                    {
                        temp[i] = false;
                    }
                }
            }
            break;

        case 30: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 54: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                    arr[i - 1] = false;
                if (i == 78)
                    arr[i + 1] = false;
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 60: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0 || i == 79)
                {
                    if (i == 0)
                    {
                        if (arr[i] || arr[i + 1])
                        {
                            if (arr[i] && arr[i + 1])
                            {
                                temp[i] = false;
                            }
                            else if (arr[i] && !arr[i + 1])
                            {
                                temp[i] = false;
                            }
                            else if (!arr[i] && arr[i + 1])
                            {
                                temp[i] = true;
                            }
                            else if (arr[i] && arr[i + 1])
                            {
                                temp[i] = true;
                            }
                            else if (arr[i] && !arr[i - 1])
                            {
                                temp[i] = true;
                            }
                            else if (!arr[i] && arr[i + 1])
                            {
                                temp[i] = false;
                            }
                        }
                        else
                        {
                            temp[i] = false;
                        }
                    }
                    else
                    {
                        if (arr[i - 1] || arr[i])
                        {
                            if (arr[i - 1] && arr[i])
                            {
                                temp[i] = false;
                            }
                            else if (arr[i - 1] && arr[i])
                            {
                                temp[i] = false;
                            }
                            else if (arr[i - 1] && !arr[i])
                            {
                                temp[i] = true;
                            }
                            else if (!arr[i - 1] && arr[i])
                            {
                                temp[i] = true;
                            }
                            else if (!arr[i - 1] && arr[i])
                            {
                                temp[i] = true;
                            }
                            else if (!arr[i - 1] && !arr[i])
                            {
                                temp[i] = false;
                            }
                        }
                        else
                        {
                            temp[i] = false;
                        }
                    }
                }
                else
                {
                    if (arr[i - 1] || arr[i] || arr[i + 1])
                    {
                        if (arr[i - 1] && arr[i] && arr[i + 1])
                        {
                            temp[i] = false;
                        }
                        else if (arr[i - 1] && arr[i] && !arr[i + 1])
                        {
                            temp[i] = false;
                        }
                        else if (arr[i - 1] && !arr[i] && arr[i + 1])
                        {
                            temp[i] = true;
                        }
                        else if (!arr[i - 1] && arr[i] && arr[i + 1])
                        {
                            temp[i] = true;
                        }
                        else if (!arr[i - 1] && arr[i] && !arr[i - 1])
                        {
                            temp[i] = true;
                        }
                        else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                        {
                            temp[i] = false;
                        }
                    }
                    else
                    {
                        temp[i] = false;
                    }
                }
            }
            break;

        case 62: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 90: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }

                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 94: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 102: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 110: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 122: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 150: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 158: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 182: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 188: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 190: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 220: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 222: // completed
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = false;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        case 250:
            for (int i = 0; i < 79; i++)
            {
                if (i == 0)
                {
                    arr[i - 1] = false;
                }
                if (i == 78)
                {
                    arr[i + 1] = false;
                }
                if (arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && arr[i] && !arr[i + 1])
                    temp[i] = false;
                else if (!arr[i - 1] && !arr[i] && arr[i + 1])
                    temp[i] = true;
                else if (!arr[i - 1] && !arr[i] && !arr[i + 1])
                    temp[i] = false;
            }
            break;

        }
        //For loop that goes through the temp array and assigns it to a corresponding value in original array.
        for (int i = 0; i < 79; i++)
        {
            arr[i] = temp[i];
        }
    }
}//namespace automata