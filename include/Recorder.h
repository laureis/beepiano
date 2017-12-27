#ifndef BEEPIANO_RECORDER_H
#define BEEPIANO_RECORDER_H

#include <vector>
#include "Keyboard.h"
#include "Recording.h"

class Recorder : public Keyboard {

/* A recorder is a Keyboard that can stocks
 * recording, so it inherits from the Keyboard class
 * it has a recording list containing the user's recordings
 * and in-app recordings list that
 * are provided with the application
 */

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

    /* Initializes the recorder by addind the recordings to the
     * two vectors
     * It goes throught the Recording directory, converts the file to the recording and
     * adds it to its following vector
     */
    void init();

    // display the user's recordings list
    void displayFileList();

    // display the in-app songs liste
    void displayAppSongs();

    /* Allows the user to record a song
     * the user chooses a name to its recording and
     * the notes are pushed back in a vector
     * that is converted into a file and
     * added to the Recording directory
     */
    void record();

    // returns a new Recording name if it already exists
    std::string existingRecordingName(std::string);

    /* Allows the user to listen to his recordings
     * he chooses the recording he wants to listen to
     * and it plays the notes of the recording
     */
    void play() override;
};


#endif //BEEPIANO_RECORDER_H
