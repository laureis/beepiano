#ifndef BEEPIANO_NOTE_H
#define BEEPIANO_NOTE_H


class Note {

/* the note has a frequency, a range(octave), value(whole, half, quarter...) and a duration
 * the frequence depends on the range and the duration on the value
 * all the frequences are in Utilities.h
 */

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

    // Calls the Beep() function that makes the sound depending on the note frequency
    virtual void play();

    // displays a note
    void display();

};


#endif //BEEPIANO_NOTE_H
