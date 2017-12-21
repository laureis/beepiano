//
// Created by L on 19/12/2017.
//

#include "../include/Rest.h"
#include <windows.h>

Rest::Rest(int value, double duration): Note('r', 1, value, duration) {}

void Rest::play() {
    Sleep(getDuration());
}