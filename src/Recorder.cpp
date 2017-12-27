#include <conio.h>
#include <ctime>
#include "../include/Recorder.h"
#include "../include/Utilities.h"
#include "../include/Rest.h"


Recorder::Recorder(int octave) : Keyboard(octave) {}
Recorder::Recorder() {}

std::vector<Recording> Recorder::getRecList() const { return m_recList; };
std::vector<Recording> Recorder::getAppSongs() const { return m_appSongs; }

void Recorder::init() {

    setOctave(1);
    std::vector<std::string> fileList = getFileList("../Recordings");
    for (int i = 0; i<fileList.size(); i++) {
        Recording *r  = new Recording(fileList[i].substr(4, (fileList[i].length()-4)-4), "../Recordings/"+fileList[i]);
        r->fileToVector();
        m_recList.push_back(*r);
    }

    std::vector<std::string> songsList = getFileList("../Recordings/PlayAlong");
    for (int i = 0; i<songsList.size(); i++) {
        Recording *r  = new Recording(songsList[i].substr(4, (songsList[i].length()-4)-4), "../Recordings/PlayAlong/"+songsList[i]);
        r->fileToVector();
        m_appSongs.push_back(*r);
    }
}

void Recorder::play() {
    displayFileList();returnLine();
    char choice;
    try {
        choice = selectChoice('1', intToChar(m_recList.size()), true);
    }
    catch (int t){
    }
    if (choice==27) return;
    drawPiano();
    m_recList[charToInt(choice)-1].play();
}

void Recorder::displayFileList() {
    returnLine();
    center();
    print("- - - - - - - - YOUR RECORDINGS");
    for (int i = 0; i < m_recList.size(); i++) {
        returnLine();
        returnLine();
        center();
        print(i + 1);
        print(" "+m_recList[i].getName());
        returnLine();
    }
}

void Recorder::displayAppSongs() {
    returnLine();
    center();
    print("- - - - - - - - TUTORIALS");
    for (int i = 0; i < m_appSongs.size(); i++) {
        returnLine();
        returnLine();
        center();
        print(i + 1);
        print(" "+m_appSongs[i].getName());
        returnLine();
    }
}

void Recorder::record() {
    returnLine();
    center();
    std::vector<Note*> partition;
    print("Set the name of your new recording and press enter to start recording : ");
    std::string s = "";
    while (s.empty()) getline(std::cin, s);
    Recording *r = new Recording(existingRecordingName(s), "../Recordings/rec_"+existingRecordingName(s)+".txt");
    recordInstructions();
    drawPiano();
    displayOctave();
    bool play = true;
    while(play) {
        int start = clock();
        Note *note;
        char c_note = getch();
        int press = clock();
        int time_diff = (press-start)/double(CLOCKS_PER_SEC)*1000;
        if (time_diff > (120000/r->getTempo())) {
            Rest *rest;
            if (time_diff/(120000/r->getTempo()) > 9) rest = new Rest(9, time_diff);
            else rest = new Rest(time_diff/(120000/r->getTempo()), time_diff);
            partition.push_back(rest);
        }
        if (c_note == 27) play = false;
        if (c_note == 'x') changeOctave(1);
        if (c_note == 'w') changeOctave(0);
        if (mapKeys.find(c_note)!=mapKeys.end()) {
            note = new Note(mapKeys.find(c_note)->second, getOctave(), 2, 60000/r->getTempo());
            note->display();
            note->play();
            partition.push_back(note);
        }
    }
    r->setNotes(partition);
    r->save();
    m_recList.push_back(*r);
}


std::string Recorder::existingRecordingName(std::string rec) {

    std::string newname = rec;
    for (int i = 0; i< m_recList.size(); i++) {
        if (rec == m_recList[i].getName()) newname+="_newversion";
    }
    return newname;
}

void Recorder::setRecList(const std::vector<Recording> &m_recList) {
    Recorder::m_recList = m_recList;
}

void Recorder::setAppSongs(const std::vector<Recording> &m_appSongs) {
    Recorder::m_appSongs = m_appSongs;
}
