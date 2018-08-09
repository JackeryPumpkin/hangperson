//
//  HangLogic.hpp
//  Hangperson
//
//  Created by Zachary Duncan on 2/10/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef HangLogic_hpp
#define HangLogic_hpp

#include <string>
#include "Hangman.hpp"

using namespace std;


class HangLogic {
private:
    
    
    string message;
    string displayMessage;
    vector<bool> positions;
    char chr;
    string attemptedChars;
    Hangman man;
    
    void setMessage(string); //This is for setting a new message at the beginning of the game
    void setMessage();
    void setPositions();
    void newGame();
    void gameLoop();
    void setChar(); //This can also find instances of the char and set the positions array
    string getMessage(); //This returns the current state of displayMessage
    string getAttemptedChars();
    string getHangman();
    void paint();
    
public:
    HangLogic();
//    HangLogic(string);
    
    void play();
};

#endif /* HangLogic_hpp */
