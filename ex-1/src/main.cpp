#include <iostream>
#include <string>
#include <vector>
#include "instruments.h"

int main(){
    printHello();

    bool wasScalpelUsed = false;
    std::vector<double> coordinates = {-1, -1};
    std::string inputComand;

    while(true)
    {
        std::cout << "Enter comand(scalpel, hemostat, tweezers or suture):" << std::endl;
        std::cin >> inputComand;

        if(inputComand == "scalpel") scalpel(&coordinates, &wasScalpelUsed);
        else if (wasScalpelUsed && inputComand == "hemostat") hemostat(&coordinates);
        else if (wasScalpelUsed && inputComand == "tweezers") tweezers(&coordinates);
        else if(wasScalpelUsed && inputComand == "suture") 
        {
            suture(&coordinates);
            break;
        }
        else std::cout << "The scalpel was NOT used" << std::endl;
    }

}
    