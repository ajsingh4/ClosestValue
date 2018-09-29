//
//  main.cpp
//  ClosestValue
//
//  Created by Aj Gill on 9/29/18.
//  Copyright © 2018 Aj Gill. All rights reserved.
//
// Create a command line C++ application that will run in Windows. 1. It should take a string of integers separated by commas (contains only valid signed integers with commas as separators, such as "1,2,0,-5") 2. It should prompt me to enter a number 3. It should tell me what number in the input list is closest to the number I entered. For example, for the input string "1,2,0,-5", if the user enters 3, the answer should be 2; if the user enters -57, the answer should be -5. State any assumptions you decide to make in the text field.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <math.h>


using namespace std;

int main() {
    cout << "Please enter a string of integers seperated by commas\n";
    string listNum;
    getline(cin, listNum);
    vector<string> vecString;
    
    
    stringstream ss(listNum);
    
    while(ss.good()){
        string substr;
        getline(ss, substr, ',');
        vecString.push_back(substr);
    }
    
    int size = int(vecString.size());
    set<int> hTable;
    
    for(int i=0; i<size; i++){
        hTable.insert(stoi(vecString[i]));
    }
    
    int retrieveNum;
    cout << "Please enter the number to find\n";
    cin >> retrieveNum;
    
    set<int>::iterator value = hTable.find(retrieveNum), iter;
    if(value == hTable.end()){
        int smallestDistance = INT_MAX, currentDistance = 0, finalAnswer = 0;
        for(iter = hTable.begin(); iter != hTable.end(); ++iter){
            currentDistance = abs(*iter - retrieveNum);
            if(currentDistance < smallestDistance){
                smallestDistance = currentDistance;
                finalAnswer = *iter;
            }
        }
        cout << finalAnswer << "\n";
    }
    else{
        cout << *value << "\n";
    }
}
