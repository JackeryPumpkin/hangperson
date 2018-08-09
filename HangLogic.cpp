//
//  HangLogic.cpp
//  Hangperson
//
//  Created by Zachary Duncan on 2/10/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include <iostream>
#include "HangLogic.hpp"

using namespace std;


HangLogic::HangLogic() {}


void HangLogic::play() {
    newGame();
    cout << "*********************************************" << endl;
    cout << "Ready? " << man.getName() << " stands at the gallows." << endl;
    cout << "*********************************************" << endl << endl << endl;
    
    setMessage();
    gameLoop();
}
    
void HangLogic::gameLoop() {
    if (man.getNumberOfLimbs() == man.MAX_LIMBS) {
        cout << string(1000, '\n');
        cout << "*********************************************" << endl;
        cout << man.getName() << " has died. You killed them because " << endl << "you couldn't guess '" << message << "'. It's not that hard." << endl;
        cout << " 0 \n/|\\\n /\\" << endl;
        cout << "*********************************************" << endl;
        
        newGame();
        cout << "Would you like to conspire to kill " << man.getName() << "?" << endl;
        cout << "Type: Y for yes or: N for no." << endl;
        cin >> chr;
        
        if (tolower(chr) == 'y') {
            setMessage();
            paint();
        }
    } else {
        bool allTrue = true;
        
        for (int i = 0; i < message.length(); i++) {
            if (!positions[i]) {
                allTrue = false;
            }
        }
        
        if (allTrue) {
            cout << string(1000, '\n');
            cout << "*********************************************" << endl;
            cout << "You Saved " << man.getName() << "!" << endl;
            cout << "I guess '" << message << "' was too easy." << endl;
            cout << "*********************************************" << endl << endl << endl << endl;
            
            newGame();
            cout << "Would you like to conspire to kill " << man.getName() << "?" << endl;
            cout << "Type: Y for yes or: N for no." << endl;
            cin >> chr;
            
            if (tolower(chr) == 'y') {
                setMessage();
                paint();
            }
        } else {
            paint();
        }
    }
}

void HangLogic::paint() {
    cout << string(1000, '\n');
    cout << "It's up to you to save " << man.getName() << " from being killed." << endl;
    cout << man.getHangman() << endl << endl;
    
    cout << "Guess the word: " << getMessage() << endl;
    
    cout << "You have already used these letters:" << endl;
    cout << attemptedChars << endl << endl;
    
    setChar();
}

void HangLogic::setChar() {
    cout << "Guess a letter: ";
    cin >> chr;
    
    attemptedChars.append(1, ' ');
    attemptedChars.append(1, toupper(chr));
    setPositions();
    
    cin.clear();
}

void HangLogic::setPositions() {
    bool found = false;
    
    for (int i = 0; i < message.length(); i++) {
        if (toupper(message[i])  == chr || tolower(message[i])  == chr) {
            positions[i] = true;
            found = true;
        }
    }
    
    if (!found) {
        man.addLimb();
    }
    
    gameLoop();
}

void HangLogic::newGame() {
    man.setRandName();
    man.resetLimbs();
    attemptedChars = "";
}

string HangLogic::getAttemptedChars() {
    return attemptedChars;
}

string HangLogic::getMessage() {
    displayMessage = message;
    
    for (int i = 0; i < message.length(); i++) {
        if (positions[i]) {
            displayMessage[i] = message[i];
        } else {
            displayMessage[i] = '_';
        }
    }
    
    return displayMessage;
}

void HangLogic::setMessage() {
    cout << "Type a word for someone else to guess:" << endl;
    cin >> message;
    
    positions.clear();
    for (int i = 0; i < message.length(); i++) {
        positions.push_back(false);
    }
}

void HangLogic::setMessage(string message) {
    this->message = message;
    positions.clear();
    for (int i = 0; i < message.length(); i++) {
        positions.push_back(false);
    }
}

string HangLogic::getHangman() {
    return man.getHangman();
}




