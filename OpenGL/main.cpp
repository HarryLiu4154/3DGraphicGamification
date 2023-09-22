// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GameController.h"
#include <cmath>

static void AddVectors()
{
    
   
}

static void Task1()
{
    float sX, sY, sZ;
    float dX, dY, dZ;
    float speed;

    try {
        cout << "Please enter the source coordinates." << endl;
        cout << "X: ";
        cin >> sX;
        cout << "Y: ";
        cin >> sY;
        cout << "Z: ";
        cin >> sZ;

        cout << "Please enter the destination coordinates." << endl;
        cout << "X: ";
        cin >> dX;
        cout << "Y: ";
        cin >> dY;
        cout << "Z: ";
        cin >> dZ;

        cout << "Please enter the travel speed per step: ";
        cin >> speed;
    }
    catch (...) {
        cout << "Input error";
    }

    glm::vec3 sVect = { sX, sY, sZ };
    glm::vec3 dVect = { dX, dY, dZ };

    float steps = glm::distance(sVect, dVect) / speed;

    cout << "It will take the character " << steps << " steps to reach the destination.";
}

static void Task2()
{
    float aX, aY, aZ;
    float bX, bY, bZ;
    float cX, cY, cZ;
    float speed;

    try {
        cout << "Please enter the coordinates of object A." << endl;
        cout << "X: ";
        cin >> aX;
        cout << "Y: ";
        cin >> aY;
        cout << "Z: ";
        cin >> aZ;

        cout << "Please enter the coordinates of object B." << endl;
        cout << "X: ";
        cin >> bX;
        cout << "Y: ";
        cin >> bY;
        cout << "Z: ";
        cin >> bZ;

        cout << "Please enter the coordinates of object C." << endl;
        cout << "X: ";
        cin >> cX;
        cout << "Y: ";
        cin >> cY;
        cout << "Z: ";
        cin >> cZ;
    }
    catch (...) {
        cout << "Input error" << endl;
    }

    glm::vec3 aVect = { aX, aY, aZ };
    glm::vec3 bVect = { bX, bY, bZ };
    glm::vec3 cVect = { cX, cY, cZ };

    float abDistance = glm::distance(aVect, bVect);
    float bcDistance = glm::distance(bVect, cVect);
    float caDistance = glm::distance(cVect, aVect);

    float perimeter = abDistance + bcDistance + caDistance;
    
    float SHeron = perimeter / 2; // Heron's Formula
    float area = sqrt(SHeron * (SHeron - abDistance) * (SHeron - bcDistance) * (SHeron - caDistance));

    cout << "The perimeter is " << perimeter << " units." << endl;
    cout << "The area is " << area << " units^2." << endl;
}

static void Task3() 
{

}

int main(void)
{
    /*GameController::GetInstance().Initialize();
    GameController::GetInstance().RunGame();*/

    Task1();

    return 0;
}
