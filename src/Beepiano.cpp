//
// Created by L on 19/12/2017.
//

#include <conio.h>
#include <afxres.h>
#include "../include/Beepiano.h"

Beepiano::Beepiano() {}
Beepiano::~Beepiano() {}

const std::vector<Menu> &Beepiano::getMenus() const { return m_menus; }

void Beepiano::setMenus(const std::vector<Menu> &m_menus) { Beepiano::m_menus = m_menus; }

const Keyboard &Beepiano::getPiano() const { return m_piano; }

void Beepiano::setPiano(const Keyboard &m_piano) { Beepiano::m_piano = m_piano; }

const Recorder &Beepiano::getRec() const { return m_rec; }

void Beepiano::setRec(const Recorder &m_rec) { Beepiano::m_rec = m_rec; }

int Beepiano::getCurrentPage() const {
    return m_currentPage;
}

void Beepiano::setCurrentPage(int m_currentPage) {
    Beepiano::m_currentPage = m_currentPage;
}


void Beepiano::logo() {
    returnLine();
    center();print("  _                       _");     returnLine();
    center();print(" | |__   ___   ___  _ __ (_) __ _ _ __   ___  ");   returnLine();
    center();print(R"( | '_ \ / _ \ / _ \| '_ \| |/ _` | '_ \ / _ \ )");returnLine();
    center();print(" | |_) |  __/|  __/| |_) | | (_| | | | | (_) |");returnLine();
    center();print(R"( |_.__/ \___| \___|| .__/|_|\__,_|_| |_|\___/)");returnLine();
    center();print("                   |_|  ");returnLine();
    returnLine();
    returnLine();
    returnLine();
}

void Beepiano::init() {
    m_currentPage = 0;

    // INITALISATION DU MENU PRINCIPAL
    std::vector<std::string> choices;
    choices.push_back("play the piano");
    choices.push_back("view recordings");
    Menu mainMenu = Menu("MAIN MENU", choices);
    m_menus.push_back(mainMenu);

    // MENU PIANO
    std::vector<std::string> choices2;
    choices2.push_back("play freely");
    choices2.push_back("play along");
    Menu pianoMenu = Menu("PLAY", choices2);
    m_menus.push_back(pianoMenu);

    // MENU RECORDINGS
    std::vector<std::string> choices3;
    choices3.push_back("create a new recording");
    choices3.push_back("listen to your recordings");
    Menu recMenu = Menu("RECORD", choices3);
    m_menus.push_back(recMenu);

    // INITIALISATION DU PIANO
    m_piano = Keyboard(1);
    // INITIALISAITION DES ENREGISTREMENTS
    m_rec = Recorder(1);
    m_rec.init();
}

void Beepiano::start() {

    init();
    bool play = true;
    char next;
    jingle();
    while (play) {
        clear();
        logo();
        switch (m_currentPage) {
            case -1 : clear(); jingle(); clear();
                play = false;
                break;
            case 0: m_menus[m_currentPage].display();
                try {
                    next = selectChoice('1', '2', true);
                }
                catch (int t) {
                    m_currentPage = 0;
                    break;
                }
                mainMenuController(next);
                break;

            case 1: m_menus[m_currentPage].display();
                try {
                    next = selectChoice('1', '2', true);
                }
                catch (int t) {
                    m_currentPage = 1;
                    break;
                }
                pianoMenuController(next);
                break;

            case 2: m_menus[m_currentPage].display();
                try {
                    next = selectChoice('1', '2', true);
                }
                catch (int t) {
                    m_currentPage = 2;
                    break;
                }
                recMenuController(next);
                break;

            default: m_currentPage = 0;
        }
    }
}

void Beepiano::mainMenuController(char next) {
    clear();
    logo();
    if (next == 27) m_currentPage = -1;
    else m_currentPage = charToInt(next);
}

void Beepiano::pianoMenuController(char next) {
    clear();
    logo();
    if (next == 27) m_currentPage = 0;
    else if (charToInt(next) == 1) m_piano.play();
    else if (charToInt(next) == 2) {
        m_rec.displayAppSongs();
        returnLine();center();print("press ESC to go back");returnLine();
        char choice;
        try {
            choice = selectChoice('1', intToChar(m_rec.getAppSongs().size()), true);
        }
        catch (int t){
            return;
        }
        if (choice==27) return;
        clear();
        logo();
        m_piano.playAlong(m_rec.getAppSongs()[charToInt(choice)-1]);
    }
}


void Beepiano::recMenuController(char next) {
    clear();
    logo();
    if (next == 27) m_currentPage = 0;
    else if (charToInt(next) == 1) {
        clear();
        logo();
        m_rec.record();
    }
    else if (charToInt(next) == 2) {
        clear();
        logo();
        m_rec.play();
    }
}

void Beepiano::jingle() {

    if (m_rec.getAppSongs().empty()) {
        clear();
        drawNote(1);
        Beep(440, 300);
        clear();
        drawNote(2);
        Beep(494, 300);
        clear();
        drawNote(1);
        Beep(523, 300);
        clear();
        drawNote(2);
        Beep(440, 300);
        clear();
    }
    else {
        for (int i = 0, d=0; i < m_rec.getAppSongs()[0].getNotes().size(); i++, d++) {
            clear();
            drawNote(d);
            m_rec.getAppSongs()[0].getNotes()[i]->play();
        }
    }
}