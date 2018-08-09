//
//  Hangman.cpp
//  Hangperson
//
//  Created by Zachary Duncan on 2/10/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include "Hangman.hpp"
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>
#include <vector>


//private:
//    const int MAX_LIMBS = 6;
//    static const int NAME_SIZE = 5;
//    string nameLib[NAME_SIZE];
//
//    string name;
//    int remainingLimbs;


//public:
Hangman::Hangman(): numberOfLimbs(0) {
    setRandName();
}

    
string Hangman::getName() {
    return name;
}

int Hangman::getNumberOfLimbs() {
    return numberOfLimbs;
}

void Hangman::addLimb() {
    numberOfLimbs++;
}

void Hangman::setRandName() {
    shuffle(nameLib.begin(), nameLib.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    name = nameLib[0];
}

string Hangman::getHangman() {
    string man[6] = { " 0 \n \n", " 0 \n/ \n", " 0 \n/| \n", " 0 \n/|\\ \n", " 0 \n/|\\\n /", " 0 \n/|\\\n /\\" };
        
    if (numberOfLimbs == 0) {
        return "\n \n \n";
    } else {
        return man[numberOfLimbs - 1];
    }
}

void Hangman::resetLimbs() {
    numberOfLimbs = 0;
}

