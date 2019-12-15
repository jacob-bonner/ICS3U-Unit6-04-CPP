// Copyright (c) 2019 Jacob Bonner All rights reserved.
//
// Created by: Jacob Bonner
// Created on: Dec 2019
// This program calculates the average of an array of numbers

#include <iostream>
#include <ctime>

template <int rows, int cols>
float calculate(float(&arrayOfNumbers)[rows][cols]) {
    // This function calculates the average of all numbers in a 2D array

    // Variables
    float sum = 0;
    float averageDivider = 0;
    float numberAverage;

    // Process
    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement) {
            sum = sum + arrayOfNumbers[rowElement][columnElement];
            averageDivider += 1;
        }
    }

    numberAverage = sum/averageDivider;
    return numberAverage;
}


int main() {
    // This function generates random numbers then prints the average

    // Variables
    float randomNumber;
    const int rows = 3;
    const int columns = 2;
    float numberArray[rows][columns];
    float average;

    // Random number seed
    unsigned int seed = time(NULL);

    // Process
    for (int rowElement = 0; rowElement < rows; rowElement++) {
        std::cout << "Row " << rowElement + 1 << ":" << std::endl;
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            randomNumber = rand_r(&seed) % 50;
            numberArray[rowElement][columnElement] = randomNumber;
            std::cout << randomNumber << std::endl;
        }
        std::cout << "" << std::endl;
    }

    average = calculate(numberArray);

    // Output
    std::cout << "The sum of all the numbers is: " << average << std::endl;
}
