//
// Created by L on 19/12/2017.
//

#include <conio.h>
#include "../include/Keyboard.h"
#include "../include/Utilities.h"

// CONSTRUCTORS
Keyboard::Keyboard(int m_octave) : m_octave(m_octave) {}
Keyboard::Keyboard() {}

// DESTRUCTOR
Keyboard::~Keyboard() {}

// GETTERS
int Keyboard::getOctave() const { return m_octave; }

// SETTERS
void Keyboard::setOctave(const int octave) { m_octave = octave; }

/* PLAY FREELY METHOD
 * interaction with the keyboard
 * the user presses a key and a note is played
 */
void Keyboard::play() {

    playInstructions();
    drawPiano();
    bool play = true;
    while(play) {
        Note *note;
        char c_note = getch();
        if (c_note == 27) play = false;
        if (c_note == 'x') changeOctave(1);
        if (c_note == 'w') changeOctave(0);
        if (mapKeys.find(c_note)!=mapKeys.end()) {
            note = new Note(mapKeys.find(c_note)->second, m_octave, 1);
            note->display();
            note->play();
            delete note;
        }
    }
}

/* PLAY FREELY METHOD
 * interaction with the keyboard
 * tutorial/play along bonus
 * the note the user has to hit is displayed
 * and played only if he presses the right key
 */
void Keyboard::playAlong(Recording rec) {

    playInstructions();
    drawPiano();
    int i = 0;
    std::vector<Note*> notes = rec.getNotes();
    while (i < notes.size()) {
        notes[i]->display();
        char n = getch();
        if (n == 27) return;
        while (notes[i]->getName() != mapKeys.find(n)->second) n = getch();
        notes[i]->play();
        i++;
    }
}

/* OCTAVE CHANGING METHOD
 * in this app, only three octaves are available
 */
void Keyboard::changeOctave(int type) {

    if ((type == 1) && (m_octave < 2)) m_octave++;
    else if ((type == 0) && (m_octave > 0)) m_octave--;
    displayOctave();
}

/* OCTAVE DISPLAYING METHOD
 * the octave is displayed so it makes it easier for the player to find what note he plays
 */
void Keyboard::displayOctave() {

    center();
    int totalWidth = widthRange * 3;
    for (int i = 0; i < widthRange*m_octave; i++) print(" ");
    print("o");
    for (int i = 0; i < totalWidth - (widthRange*m_octave); i++) print(" ");
    print("\r");
}
