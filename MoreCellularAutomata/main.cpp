//STD
#include <iostream>
#include <string>

//H files
#include "automata.h"

//Defines rules that are allowed to be used
//000 returns a list of rules
const int ruleCount = 19;
int listOfRules[ruleCount] = { 000, 30, 54, 60, 62, 90, 94, 102, 110, 122, 126, 150, 158, 182, 188, 190, 220, 222, 250 };

int main()
{
    //used to check if the user wants to repeat
    int repeat = 0;
    //Will execute this until the user inputs the value to stop the loop
    do {
        int rule;
        bool array[79];
        Automata::initArray(array);

        do 
        {
            std::cout << "Please enter a rule for the cellular automata: ";
            std::cin >> rule;
            if (repeat > 0)
                std::cout << std::endl;
            bool ruleIsValid = false;
            for (int i = 0; i < ruleCount; i++)
            {
                if (listOfRules[i] == rule)
                {
                    ruleIsValid = true;
                    break;
                }
            }
            if (!ruleIsValid)
            {
                rule = -1;
                std::cout << std::endl << "The rule you entered is not valid. Enter 000 for a list of all available rules." << std::endl << std::endl;
            }
            if (rule == 0)
            {
                std::cout << "The list of available rules is: " << std::endl << std::endl;
                for (int i = 1; i < ruleCount; i++)
                {
                    std::cout << listOfRules[i] << std::endl;
                }
                std::cout << std::endl;
            }
        } while (rule <= 0);

        int count;

        do
        {
            std::cout << std::endl << "Please enter a number of rows you would like to be printed: ";
            std::cin >> count;

            if (count < 0)
            {
                std::cout << std::endl << "Please enter a value greater then 0" << std::endl;
            }
            if (count > 100)
            {
                std::cout << std::endl << "100 rows it the maximum." << std::endl;
            }
        } while (count < 0 || count > 100);

        for (int i = 0; i < count-1; i++)
        {
            Automata::printArray(array);
            Automata::updateArray(array, rule);
        }

        std::cout << std::endl << "Would you like to repeat? Enter 1 to repeat or enter 0 to end to program: ";
        std::cin >> repeat;
        std::cout << std::endl;

    } while (repeat > 0);
    
    std::cout << std::endl << std::endl << "Thank you for using the program!" << std::endl << "Created by Alexander Tucker. Purdue 2024";
}