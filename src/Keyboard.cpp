#include <conio.h>
#include "../include/Keyboard.h"
#include "../include/Utilities.h"

Keyboard::Keyboard(int m_octave) : m_octave(m_octave) {}
Keyboard::Keyboard() {}

Keyboard::~Keyboard() {}

int Keyboard::getOctave() const { return m_octave; }

void Keyboard::setOctave(const int octave) { m_octave = octave; }

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
            note = new Note(mapKeys.find(c_note)->second, m_octave, 1, 300);
            note->display();
            note->play();
            delete note;
        }
    }
}

void Keyboard::playAlong(Recording rec) {

    playInstructions();
    drawPiano();
    int i = 0;
    std::vector<Note*> notes = rec.getNotes();
    while (i < notes.size()) {
        notes[i]->display();
        char n = getch();
        if (n == 27) return;
        if (notes[i]->getName() == 'r') notes[i]->play();
        else {
            while (notes[i]->getName() != mapKeys.find(n)->second) n = getch();
            notes[i]->play();
        }
        i++;
    }
}

void Keyboard::changeOctave(int type) {

    if ((type == 1) && (m_octave < 2)) m_octave++;
    else if ((type == 0) && (m_octave > 0)) m_octave--;
    displayOctave();
}

void Keyboard::displayOctave() {

    center();
    int totalWidth = widthRange * 3;
    for (int i = 0; i < widthRange*m_octave; i++) print(" ");
    print("o");
    for (int i = 0; i < totalWidth - (widthRange*m_octave); i++) print(" ");
    print("\r");
}
