//
// Created by L on 19/12/2017.
//

#ifndef BEEPIANO_KEYBOARD_H
#define BEEPIANO_KEYBOARD_H


#include <vector>
#include "Recording.h"

class Keyboard {

private:
    int m_octave;

public:

    // constructors
    Keyboard(int m_octave);
    Keyboard();

    // destructor
    virtual ~Keyboard();

    // getters
    int getOctave() const;

    // setters
    void setOctave(int);

    // methods
    virtual void play();
    void playAlong(Recording);

    // octave
    void changeOctave(int);
    void displayOctave();
};


#endif //BEEPIANO_KEYBOARD_H
