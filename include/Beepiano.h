//
// Created by L on 19/12/2017.
//

#ifndef BEEPIANO_BEEPIANO_H
#define BEEPIANO_BEEPIANO_H

#include "Utilities.h"
#include "Recorder.h"
#include "Menu.h"

class Beepiano {

private:

    std::vector<Menu> m_menus;
    Keyboard m_piano;
    Recorder m_rec;
    int m_currentPage;

public:

    // constructor
    Beepiano();
    // destructor
    virtual ~Beepiano();

    // getters
    const std::vector<Menu> &getMenus() const;
    const Keyboard &getPiano() const;
    const Recorder &getRec() const;
    int getCurrentPage() const;

    // setters
    void setMenus(const std::vector<Menu> &m_menus);
    void setPiano(const Keyboard &m_piano);
    void setRec(const Recorder &m_rec);
    void setCurrentPage(int m_currentPage);

    // app initialization
    void logo();
    void init();
    void start();
    void jingle();

    // menus controllers
    void mainMenuController(char);
    void pianoMenuController(char);
    void recMenuController(char);
};


#endif //BEEPIANO_BEEPIANO_H
