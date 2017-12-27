#ifndef BEEPIANO_RECORDING_H
#define BEEPIANO_RECORDING_H

#include <string>
#include <vector>
#include "Note.h"

class Recording {

/* A recording is a partition
 * it has a name, file path, and notes table
 * and a tempo
 */
private:
    std::string m_name;
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

    // Converts a txt file to a Vector of notes
    void fileToVector();

    // Convert a vector of notes to a txt file
    bool save();

    // Plays a partition
    void play();

    // displays a partition
    void display();
};


#endif //BEEPIANO_RECORDING_H
