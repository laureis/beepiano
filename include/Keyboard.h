#ifndef BEEPIANO_KEYBOARD_H
#define BEEPIANO_KEYBOARD_H


#include <vector>
#include "Recording.h"

class Keyboard {

/* The keyboard will allow the user to play the piano
 */

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

    /* allows the user to play freely
     * it expects a char typed by the user that corresponds to a note
     * by calling the mapKeys and mapNotes in Utilities.h
     * the plays and displays it
     */
    virtual void play();

    /* tutorial or play along method
     * the user has to follow the notes that the app shows
     * expects a char and plays it if it corresponds to the shown note
     */
    void playAlong(Recording);

    /* Octave controller
     * the user can go through 3 octaves
     */
    void changeOctave(int);
    void displayOctave();
};


#endif //BEEPIANO_KEYBOARD_H
