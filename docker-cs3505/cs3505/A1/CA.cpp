/* 
Name: Vi Cao
Assignment 1: Cellular Automata
Description: The program asks the user for a number (0–255) that represents a rule set.
It uses that rule to create and display 50 rows of a pattern made of '#' and spaces.
The pattern starts with one '#' in the middle of the first row, and each new row is 
calculated based on the row above it.
*/

#include <iostream>
using namespace std;

// Converts a rule set number (0–255) into an 8-element binary array
void convertRuleSetNumberToRuleSetArray(int num, int ruleSet[]) {
    int currInd = 0;
    while (num != 0){
        //checks if even or odd
        if(num % 2 == 0){
            ruleSet[currInd] = 0;
        }
        if(num % 2 == 1){
            ruleSet[currInd] = 1;
            num--;
        }
        currInd++;
        num = num/2;
    }
     while(currInd < 8){
        ruleSet[currInd] = 0;
        currInd++;
    }
}

// Displays the current generation: '#' for 1, ' ' for 0
void displayCurrentGeneration(int generation[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << (generation[i] ? '#' : ' ');
    }
    cout << endl;
}

// Converts three neighbors (left, current, right) into an index 0–7
int convertNeighborhoodToIndex(int left, int current, int right) {
    return left * 4 + current * 2 + right;
}

// Computes the next generation using the current generation and rule set
void computeNextGeneration(int current[], int next[], int length, int ruleSet[]) {
    next[length - 1] = current[length - 1];
    next[0] = current[0];
    for (int i=1; i < length-1; i++){
        int idx = convertNeighborhoodToIndex(current[i - 1], current[i], current[i + 1]);
        next[i] = ruleSet[idx]; // looks it up
    }
}


int main() {
    int ruleNum;

    // 1. Ask user for rule set number
    cout << "Enter a rule set number (0–255): ";
    if (!(cin >> ruleNum) || ruleNum < 0 || ruleNum > 255) {
        cout << "Invalid input. Please enter a number between 0 and 255." << endl;
        return 0;
    }

    // 2. Convert rule number to rule set array
    int ruleSet[8]{};
    convertRuleSetNumberToRuleSetArray(ruleNum, ruleSet);

    // 3. Create starting generation (length 64, 1 in the middle)
    const int LENGTH = 64;
    int current[LENGTH] = {};
    int next[LENGTH] = {};
    current[LENGTH / 2] = 1;

    // 4. Display 50 generations
    for (int gen = 0; gen < 50; gen++) {
        displayCurrentGeneration(current, LENGTH);
        computeNextGeneration(current, next, LENGTH, ruleSet);

        // Copy next into current for next loop
        for (int i = 0; i < LENGTH; i++) {
            current[i] = next[i];
        }
    }

    return 0;
}
