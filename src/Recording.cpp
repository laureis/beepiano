#include <fstream>
#include "../include/Recording.h"
#include "../include/Rest.h"
#include "../include/Utilities.h"

Recording::Recording(std::string name, std::string path) : m_name(name), m_path(path), m_tempo(120) {}
Recording::Recording() {}

Recording::~Recording() {}

std::string Recording::getPath() const { return m_path; }
std::string Recording::getName() const { return m_name; }
int Recording::getTempo() const { return m_tempo; }
const std::vector<Note*> &Recording::getNotes() const { return m_notes; }

void Recording::setName(std::string name) { m_name = name; }
void Recording::setTempo(int tempo) { m_tempo = tempo; }
void Recording::setPath(std::string path) { m_path = path; }
void Recording::setNotes(const std::vector<Note*> &notes) { m_notes = notes; }

void Recording::fileToVector() {

    std::vector<Note*> rec;
    std::fstream file;
    file.open(m_path, std::ios::binary | std::ios::out | std::ios::in);
    if (!file.is_open()) {
        std::ofstream outfile(m_path);
        outfile.close();
    } else {
        std::string tmp;
        file.seekg(0);
        getline(file, tmp);
        if ((atoi(tmp.c_str()) < 25) || (atoi(tmp.c_str()) > 250)) {
            print((atoi(tmp.c_str())));
            setTempo(120);
        }
        else setTempo(atoi(tmp.c_str()));
        while (!file.eof()) {
            getline(file, tmp);
            if ((tmp[0] == 'r') && (isInRange(tmp[1]) && (isValue(tmp[2])))) {
                Rest *r = new Rest(charToInt(tmp[2]), (120000/m_tempo)/charToInt(tmp[2]));
                rec.push_back(r);
            }
            else {
                if ((isNote(tmp[0])) && (isInRange(tmp[1]) && (isValue(tmp[2])))) {
                    Note *n = new Note(tmp[0], charToInt(tmp[1]), charToInt(tmp[2]),(120000/m_tempo)/charToInt(tmp[2]));
                    rec.push_back(n);
                }
            }
        }
        file.close();
    }
    m_notes = rec;
}

bool Recording::save() {

    std::fstream file(m_path, std::ios::binary | std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::ofstream outfile(m_path);
        outfile << m_tempo << std::endl;
        for (int i = 0; i<m_notes.size(); i++)
            outfile << m_notes[i]->getName() << m_notes[i]->getRange() << m_notes[i]->getValue() << std::endl;
        outfile.close();
    } else {
        file << m_tempo << std::endl;
        for (int i = 0; i<m_notes.size(); i++)
            file << m_notes[i]->getName() << m_notes[i]->getRange() << m_notes[i]->getValue() << std::endl;
        file.close();
        return 1;
    }
}

void Recording::display() {

    for (int i = 0; i<m_notes.size(); i++) m_notes[i]->display();
}

void Recording::play() {

    for (int i = 0; i<m_notes.size(); i++) {
        m_notes[i]->display();
        m_notes[i]->play();
    }
}
