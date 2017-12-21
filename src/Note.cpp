//
// Created by L on 19/12/2017.
//

#include <cmath>
#include <windows.h>
#include "../include/Note.h"
#include "../include/Utilities.h"

Note::Note(char name, int range, int value, double duration) : m_name(name), m_frequence(mapNotes[name] * pow(2, range)), m_range(range), m_value(value), m_duration(duration) {}
Note::Note(char name, int range, int value) : m_name(name), m_frequence(mapNotes[name] * pow(2, range)), m_range(range), m_value(value), m_duration(300) {}
Note::Note() { }

Note::~Note() {}

char Note::getName() const { return m_name; }
double Note::getFrequence() const { return m_frequence; }
int Note::getValue() const { return m_value; }
int Note::getRange() const { return m_range; }
long int Note::getDuration() const { return m_duration; }


void Note::setName(char name) { m_name = name; }
void Note::setRange(int range) { m_range = range; }
void Note::setFrequence(const double freq) { m_frequence = freq; }
void Note::setValue(const int value) { m_value = value; }
void Note::setDuration(long int duration) { m_duration = duration; }

void Note::play() {
    Beep(m_frequence, m_duration);
}

void Note::display() {

    int pos_o = widthRange*m_range;
    int pos_n = mapPosition[m_name]+(widthRange*m_range);
    center();
    for (int i = 0; i < widthRange*3; i++) {
        if (i == pos_o) print("o");
        else if (i == pos_n) print("*");
        else print(" ");
    }
    print("\r");
}