#pragma once
#include <iostream>
#include <string>

void printHello()
{
    std::cout << "Operations Simulator!" << std::endl;
}

bool isInCut(std::vector<double> coordinates, double a){
    //std::cout << "isInCut check" << std::endl;
    //std::cout << coordinates[0] << std::endl;
    //std::cout << coordinates[1] << std::endl;
    return a > coordinates[0] && a < coordinates[1];
}

void scalpel(std::vector<double>* coordinates, bool* wasScalpelUsed)
{
    double a, b;
    std::cout << "Enter coordinates with a space(x y) for scalpel:" << std::endl;
    std::cin >> a >> b;

    if(a < 0 || b < 0)
    {
        std::cout << "The coordinate must be greater than 0" << std::endl;
        return;
    } 
    
    if(a == b)
    {
        std::cout << "The coordinates are the same" << std::endl;
        return;
    } 
    
    (*coordinates)[0] = std::min(a, b);
    (*coordinates)[1] = std::max(a, b);

    *wasScalpelUsed = true;
    std::cout << "The operation is started" << std::endl;
    std::cout << "The scalpel was used on " << std::to_string(a) << " and " << std::to_string(b) << " coordinates" << std::endl;
}

void hemostat(const std::vector<double>* coordinates)
{
    double a; 
    std::cout << "Enter coordinate for hemostat:" << std::endl;
    std::cin >> a;

    if(!isInCut(*coordinates, a))
    {
        std::cout << "The coordinate out of the scalpel's cut" << std::endl;
        return;
    }

    std::cout << "Hemostat was used on " << std::to_string(a) << "coordinate"  << std::endl;
}

void tweezers(const std::vector<double>* coordinates)
{
    double a; 
    std::cout << "Enter coordinate for hemostat:" << std::endl;
    std::cin >> a;

    if(!isInCut(*coordinates, a))
    {
        std::cout << "The coordinate out of the scalpel's cut" << std::endl;
        return;
    }

    std::cout << "Tweezers was used on " << std::to_string(a) << "coordinate"  << std::endl;
}

void suture(const std::vector<double>* coordinates)
{
    double a, b;

    std::cout << "Enter coordinates with a space(x y) for suture:" << std::endl;
    std::cin >> a >> b;

    if((a == (*coordinates)[0] && b == (*coordinates)[1]) || (a == (*coordinates)[1] && b == (*coordinates)[0]))
    {
        std::cout << "The suture was used on " << std::to_string(a) << " and " << std::to_string(b) << " coordinates" << std::endl;
        std::cout << "The operation is complete" << std::endl;
    } else 
    {
        std::cout << "The coordinates must be the same as the scalpel cut" << std::endl;
    }

}