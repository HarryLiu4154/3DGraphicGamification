// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GameController.h"
#include <cmath>
#include <string>

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

static string vec2_to_string(glm::vec2& v) {
    return "vec2(" + to_string(v.x) + ", " + to_string(v.y) + ")";
}

static string vec3_to_string(glm::vec3& v) {
    return "vec3(" + to_string(v.x) + ", " + to_string(v.y) + ", " + to_string(v.z) + ")";
}

static void Task3() 
{
    /*float aX, aY, aZ;
    float bX, bY, bZ;
    float cX, cY, cZ;
    float speed;

    try {
        cout << "Please enter the coordinates of point A." << endl;
        cout << "X: ";
        cin >> aX;
        cout << "Y: ";
        cin >> aY;
        cout << "Z: ";
        cin >> aZ;

        cout << "Please enter the coordinates of point B." << endl;
        cout << "X: ";
        cin >> bX;
        cout << "Y: ";
        cin >> bY;
        cout << "Z: ";
        cin >> bZ;

        cout << "Please enter the coordinates of point C." << endl;
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

    glm::vec3 sideAB = glm::vec3(bX, bY, bZ) - glm::vec3(aX, aY, aZ);
    glm::vec3 sideAC = glm::vec3(aX, aY, aZ) - glm::vec3(cX, cY, cZ);
    glm::vec3 sideBC = glm::vec3(cX, cY, cZ) - glm::vec3(bX, bY, bZ);
    
    glm::vec3 sideAAprime = glm::cross(sideAB, sideBC);
    glm::vec3 sideAD = glm::cross(sideAB, sideAAprime);
    glm::vec3 sideBBprime = glm::cross(sideAB, sideBC);

    cout << vec3_to_string(sideBBprime) << endl;
    */
    // We will decide to use sideAB as the "middle" each time
    
}

static void AddVectors()
{
    glm::vec2 a = { 3, 5 };
    glm::vec2 b = { 2, -1 };
    glm::vec2 c = a + b;
    cout << vec2_to_string(c) << endl;

    glm::vec3 d = { 3, 5, 1 };
    glm::vec3 e = { 2, -1, -1 };
    glm::vec3 f = d + e;
    cout << vec3_to_string(f) << endl;
}

static void SubtractVectors()
{
    glm::vec2 a = { 3, 5 };
    glm::vec2 b = { 2, -1 };
    glm::vec2 c = b - a;
    glm::vec2 d = a - b;

    cout << vec2_to_string(c) << "\tMagnitude: " << glm::length(c) << endl;
    cout << vec2_to_string(d) << "\tMagnitude: " << glm::length(d) << endl;
}

static void MultiplyVectors()
{
    glm::vec3 pos = { 0, 0, 0 };
    glm::vec3 dest = { 0, 0, 0 };
    glm::vec3 dir = dest - pos;
    dir = glm::normalize(dir);
    pos += (dir * 0.1f);
    cout << vec3_to_string(pos) << endl;
}

static glm::vec3 pos = { 2, 2, 2 };
static void MultiplyVectors2()
{
    glm::vec3 dest = { 1, 0, 0 };
    glm::vec3 dir = dest - ::pos;
    dir = glm::normalize(dir);
    ::pos += (dir * 0.1f);
    cout << vec3_to_string(pos) << endl;
}

static void Distance()
{
    glm::vec3 p1 = { 1, 1, 0 };
    glm::vec3 p2 = { 2, 1, 2 };
    float distance = glm::distance(p1, p2);
    cout << "Distance = " << distance << endl;
}

static void DotProduct()
{
    glm::vec3 source = { 0, 0, 0 };
    glm::vec3 a = { 0, 2, 0 };
    glm::vec3 b = { 1, 1, 0 };
    glm::vec3 aVec = a - source;
    glm::vec3 bVec = b - source;
    aVec = glm::normalize(aVec);
    bVec = glm::normalize(bVec);
    float dot = glm::dot(aVec, bVec);
    cout << "Dot = " << dot << endl;
}

static void CrossProduct()
{
    glm::vec3 source = { 0, 0, 0 };
    glm::vec3 a = { 0, 2, 0 };
    glm::vec3 b = { 1, 1, 0 };
    glm::vec3 aVec = a - source;
    glm::vec3 bVec = b - source;
    glm::vec3 cross = glm::cross(aVec, bVec);
    cross = glm::normalize(cross);
    cout << "Cross = " << vec3_to_string(cross) << endl;
}

int main(void)
{
    /*GameController::GetInstance().Initialize();
    GameController::GetInstance().RunGame();*/

    //Task1();
    //Task2();
    //Task3();

    AddVectors();
    SubtractVectors();
    MultiplyVectors();
    
    for (int count = 0; count < 10; ++count) {
        MultiplyVectors2();
    }

    Distance();
    DotProduct();
    CrossProduct();

    return 0;
}
