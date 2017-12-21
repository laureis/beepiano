//
// Created by L on 19/12/2017.
//

#ifndef BEEPIANO_NOTE_H
#define BEEPIANO_NOTE_H


class Note {

private:
    char m_name;
    double m_frequence;
    int m_range;
    int m_value;
    double m_duration;

public:

    //constructor
    Note();
    Note(char m_name, int range, int m_value, double duration);
    Note(char m_name, int range, int m_value);

    // destructor
    virtual ~Note();

    //getters
    char getName() const;
    double getFrequence() const;
    int getValue() const;
    int getRange() const;
    long int getDuration() const;

    //setters
    void setRange(int);
    void setName(char);
    void setFrequence(double);
    void setValue(int);
    void setDuration(long int);

    //methods
    virtual void play();
    void display();
    void frequencyFromOctave(int);

};


#endif //BEEPIANO_NOTE_H
