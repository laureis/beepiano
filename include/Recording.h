//
// Created by L on 19/12/2017.
//

#ifndef BEEPIANO_RECORDING_H
#define BEEPIANO_RECORDING_H

#include <string>
#include <vector>
#include "Note.h"

class Recording {

private:
    std::string m_name; // Recording name is equivalent to file name
    std::string m_path;
    std::vector<Note*> m_notes;
    int m_tempo;

public:

    // constructors
    Recording(std::string name, std::string path);
    Recording();

    // destructor
    virtual ~Recording();

    // getters
    std::string getName() const;
    std::string getPath() const;
    const std::vector<Note*> &getNotes() const;
    int getTempo() const;

    // setters
    void setName(std::string name);
    void setPath(std::string path);
    void setNotes(const std::vector<Note*>& notes);
    void setTempo(int tempo);

    // convert a txt file to a a Note vector
    std::vector<Note*> fileToVector();

    // save to file
    bool save();

    // plays a partition
    void play();

    // displays a partition
    void display();
};


#endif //BEEPIANO_RECORDING_H
