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
        std::cout << "Please enter the source coordinates." << endl;
        std::cout << "X: ";
        cin >> sX;
        std::cout << "Y: ";
        cin >> sY;
        std::cout << "Z: ";
        cin >> sZ;

        std::cout << "Please enter the destination coordinates." << endl;
        std::cout << "X: ";
        cin >> dX;
        std::cout << "Y: ";
        cin >> dY;
        std::cout << "Z: ";
        cin >> dZ;

        std::cout << "Please enter the travel speed per step: ";
        cin >> speed;
    }
    catch (...) {
        std::cout << "Input error";
    }

    glm::vec3 sVect = { sX, sY, sZ };
    glm::vec3 dVect = { dX, dY, dZ };

    float steps = glm::distance(sVect, dVect) / speed;

    std::cout << "It will take the character " << steps << " steps to reach the destination.";
}

static void Task2()
{
    float aX, aY, aZ;
    float bX, bY, bZ;
    float cX, cY, cZ;

    try {
        std::cout << "Please enter the coordinates of object A." << endl;
        std::cout << "X: ";
        cin >> aX;
        std::cout << "Y: ";
        cin >> aY;
        std::cout << "Z: ";
        cin >> aZ;

        std::cout << "Please enter the coordinates of object B." << endl;
        std::cout << "X: ";
        cin >> bX;
        std::cout << "Y: ";
        cin >> bY;
        std::cout << "Z: ";
        cin >> bZ;

        std::cout << "Please enter the coordinates of object C." << endl;
        std::cout << "X: ";
        cin >> cX;
        std::cout << "Y: ";
        cin >> cY;
        std::cout << "Z: ";
        cin >> cZ;
    }
    catch (...) {
        std::cout << "Input error" << endl;
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

    std::cout << "The perimeter is " << perimeter << " units." << endl;
    std::cout << "The area is " << area << " units^2." << endl;
}

static string vec2_to_string(glm::vec2& v) {
    return "vec2(" + to_string(v.x) + ", " + to_string(v.y) + ")";
}

static string vec3_to_string(glm::vec3& v) {
    return "vec3(" + to_string(v.x) + ", " + to_string(v.y) + ", " + to_string(v.z) + ")";
}

static string mat4_to_string(glm::mat4 m) {
    string output = "";
    output += "mat4x4(";
    
    for (int i = 0; i < 4; ++i) {
        output += "(";
        for (int j = 0; j < 4; ++j) {
            output += to_string(m[i][j]);
            if (j != 3) {
                output += ", ";
            }
        }
        if (i != 3) {
            output += "), ";
        } 
    }
    output += "))";

    return output;
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
    std::cout << vec2_to_string(c) << endl;

    glm::vec3 d = { 3, 5, 1 };
    glm::vec3 e = { 2, -1, -1 };
    glm::vec3 f = d + e;
    std::cout << vec3_to_string(f) << endl;
}

static void SubtractVectors()
{
    glm::vec2 a = { 3, 5 };
    glm::vec2 b = { 2, -1 };
    glm::vec2 c = b - a;
    glm::vec2 d = a - b;

    std::cout << vec2_to_string(c) << "\tMagnitude: " << glm::length(c) << endl;
    std::cout << vec2_to_string(d) << "\tMagnitude: " << glm::length(d) << endl;
}

static void MultiplyVectors()
{
    glm::vec3 pos = { 0, 0, 0 };
    glm::vec3 dest = { 1, 0, 0 };
    glm::vec3 dir = dest - pos;
    dir = glm::normalize(dir);
    pos += (dir * 0.1f);
    std::cout << vec3_to_string(pos) << endl;
}

static glm::vec3 pos = { 2, 2, 2 };
static void MultiplyVectors2()
{
    glm::vec3 dest = { 1, 0, 0 };
    glm::vec3 dir = dest - ::pos;
    dir = glm::normalize(dir);
    ::pos += (dir * 0.1f);
    std::cout << vec3_to_string(pos) << endl;
}

static void Distance()
{
    glm::vec3 p1 = { 1, 1, 0 };
    glm::vec3 p2 = { 2, 1, 2 };
    float distance = glm::distance(p1, p2);
    std::cout << "Distance = " << distance << endl;
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
    std::cout << "Dot = " << dot << endl;
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
    std::cout << "Cross = " << vec3_to_string(cross) << endl;
}

static void MatrixAddition() {
    glm::mat4 matrix1 =
    {
        { 1, 1, 1, 1 }, { 2, 2, 2, 2 },
        { 3, 3, 3, 3 }, { 4, 4, 4, 4 }
    };
    glm::mat4 matrix2 =
    {
        { 5, 5, 5, 5 }, { 6, 6, 6, 6 },
        { 7, 7, 7, 7 }, { 8, 8, 8, 8 }
    };
    std::cout << "Matrix1: " << mat4_to_string(matrix1) << endl;
    std::cout << "Matrix2: " << mat4_to_string(matrix2) << endl;
    std::cout << "Add M1 to M2: " << mat4_to_string(matrix1 + matrix2) << endl;
}

static void MatrixSubtraction() {
    glm::mat4 matrix1 =
    {
        { 1, 1, 1, 1 }, { 2, 2, 2, 2 },
        { 3, 3, 3, 3 }, { 4, 4, 4, 4 }
    };
    glm::mat4 matrix2 =
    {
        { 5, 5, 5, 5 }, { 6, 6, 6, 6 },
        { 7, 7, 7, 7 }, { 8, 8, 8, 8 }
    };
    std::cout << "Matrix1: " << mat4_to_string(matrix1) << endl;
    std::cout << "Matrix2: " << mat4_to_string(matrix2) << endl;
    std::cout << "Subtract M2 from M1: " << mat4_to_string(matrix1 - matrix2) << endl;
}

static void MatrixMultiplication() {
    glm::mat4 matrix1 =
    {
        { 1, 1, 1, 1 }, { 2, 2, 2, 2 },
        { 3, 3, 3, 3 }, { 4, 4, 4, 4 }
    };
    glm::mat4 matrix2 =
    {
        { 5, 5, 5, 5 }, { 6, 6, 6, 6 },
        { 7, 7, 7, 7 }, { 8, 8, 8, 8 }
    };
    std::cout << "Matrix1: " << mat4_to_string(matrix1) << endl;
    std::cout << "Matrix2: " << mat4_to_string(matrix2) << endl;
    std::cout << "Multiply M1 and M2: " << mat4_to_string(matrix1 * matrix2) << endl;
}

static void MatrixMultiplicationNonCommutative() {
    glm::mat4 matrix1 =
    {
        { 1, 1, 1, 1 }, { 2, 2, 2, 2 },
        { 3, 3, 3, 3 }, { 4, 4, 4, 4 }
    };
    glm::mat4 matrix2 =
    {
        { 5, 5, 5, 5 }, { 6, 6, 6, 6 },
        { 7, 7, 7, 7 }, { 8, 8, 8, 8 }
    };
    std::cout << "Matrix1: " << mat4_to_string(matrix1) << endl;
    std::cout << "Matrix2: " << mat4_to_string(matrix2) << endl;
    std::cout << "Multiply M2 and M1: " << mat4_to_string(matrix2 * matrix1) << endl;
}

static void MatrixMultiplicationCommutative() {
    glm::mat4 matrix1 = glm::mat4(1.0f);
    glm::mat4 matrix2 =
    {
        { 5, 5, 5, 5 }, { 6, 6, 6, 6 },
        { 7, 7, 7, 7 }, { 8, 8, 8, 8 }
    };
    std::cout << "Matrix1: " << mat4_to_string(matrix1) << endl;
    std::cout << "Matrix2: " << mat4_to_string(matrix2) << endl;
    std::cout << "Multiply M1 and M2: " << mat4_to_string(matrix1 * matrix2) << endl;
    std::cout << "Multiply M2 and M1: " << mat4_to_string(matrix2 * matrix1) << endl;
}

static void MatrixTranslate() {
    glm::mat4 matrix1 = glm::mat4(1.0f);
    glm::vec3 pos1 = { 0, 0, 0 };
    matrix1 = glm::translate(matrix1, pos1);
    std::cout << "Transformation Matrix 1: " << mat4_to_string(matrix1) << endl;

    glm::mat4 matrix2 = glm::mat4(1.0f);
    glm::vec3 pos2 = { 1, 2, 3 };
    matrix1 = glm::translate(matrix2, pos2);
    std::cout << "Transformation Matrix 2: " << mat4_to_string(matrix2) << endl;
}

static void MatrixScale()
{
    glm::mat4 matrix = glm::mat4(1.0f);
    glm::vec3 scale = { 2, 2, 2 };
    matrix = glm::scale(matrix, scale);
    std::cout << "Scale matrix: " << mat4_to_string(matrix) << endl;
}

static void MatrixRotation()
{
    glm::mat4 matrix = glm::mat4(1.0f);
    float angle = 0.1f;
    glm::vec3 axis = { 0, 1, 0 };
    matrix = glm::rotate(matrix, angle, axis);
    std::cout << "Rotation matrix: " << mat4_to_string(matrix) << endl;
}

int main(void)
{
    /*GameController::GetInstance().Initialize();
    GameController::GetInstance().RunGame();*/

    //Task1();
    //Task2();
    //Task3();

    /*AddVectors();
    SubtractVectors();
    MultiplyVectors();
    
    for (int count = 0; count < 10; ++count) {
        MultiplyVectors2();
    }

    Distance();
    DotProduct();
    CrossProduct();*/

    MatrixAddition();
    MatrixSubtraction();
    MatrixMultiplication();
    MatrixMultiplicationNonCommutative();
    MatrixMultiplicationCommutative();
    MatrixTranslate();

    return 0;
}
