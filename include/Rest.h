//
// Created by L on 19/12/2017.
//

#ifndef BEEPIANO_REST_H
#define BEEPIANO_REST_H


#include "Keyboard.h"

class Rest : public Note {

public:
    Rest(int, double);
    void play() override;

};


#endif //BEEPIANO_REST_H
