#ifndef BEEPIANO_REST_H
#define BEEPIANO_REST_H


#include "Keyboard.h"

class Rest : public Note {

/* When a user records a song
 * he may wants his breaks to be saved
 * when he listens to his recording, it will
 * sound exactly like the way he played it
 */

public:
    Rest(int, double);

    // Calls the sleep() method to pause the app
    void play() override;

};


#endif //BEEPIANO_REST_H
