//
//  Hangman.hpp
//  Hangperson
//
//  Created by Zachary Duncan on 2/10/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef Hangman_hpp
#define Hangman_hpp

#include <string>
#include <vector>

using namespace std;


class Hangman {
private:
    string name;
    int numberOfLimbs;
    vector<string> nameLib = {"Geralt", "Tom", "Matilda", "Madellox", "Lidia", "Daniel", "Arnold", "Javier", "Emilie", "Katie", "Zachary", "Humbold", "King Dripper", "Flip-Master Fancy", "Olive", "Bob's Your Uncle", "Jack the Ripper", "Leonardo", "Jensen", "Dean", "Sam", "Negan", "Daenerys Stormborn", "Kingslayer", "Nymeria", "Marsha", "John Jacob Jingleheimer Schmidt", "Rudolph", "Pikachu", "Thanos", "Rocket R", "Peter Quill", "Jason Vorhees", "Freddy Krueger", "Tyrion", "Cersei", "Ned", "Riker", "Benji", "Picard", "Deanna Troi", "Beverly", "Data", "Divinci", "Elon Musk", "Sergie Brin", "Steve Jobs", "Tim Cook", "Bitcoin Bob", "Foreigner", "System of a Down", "Linkin Park", "Tyler, the Creator", "Logic", "Khalid"
    };
    
public:
    Hangman();
    
    const int MAX_LIMBS = 6;
    
    string getName();
    int getNumberOfLimbs();
    void addLimb();
    void setRandName();
    string getHangman();
    void resetLimbs();
};

#endif /* Hangman_hpp */

