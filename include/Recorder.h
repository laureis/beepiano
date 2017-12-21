//
// Created by L on 19/12/2017.
//

#ifndef BEEPIANO_RECORDER_H
#define BEEPIANO_RECORDER_H

#include <vector>
#include "Keyboard.h"
#include "Recording.h"

class Recorder : public Keyboard {

private:
    std::vector<Recording> m_recList;
    std::vector<Recording> m_appSongs;

public:

    // constructor
    Recorder(int m_octave);
    Recorder();

    // getters
    std::vector<Recording> getRecList() const;
    std::vector<Recording> getAppSongs() const;

    // setters
    void setRecList(const std::vector<Recording> &m_recList);
    void setAppSongs(const std::vector<Recording> &m_appSongs);

    void init();
    void displayFileList();
    void displayAppSongs();
    void record();
    void play() override;
};


#endif //BEEPIANO_RECORDER_H
