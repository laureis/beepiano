#ifndef BEEPIANO_BEEPIANO_H
#define BEEPIANO_BEEPIANO_H

#include "Utilities.h"
#include "Recorder.h"
#include "Menu.h"

class Beepiano {


/* MAIN CLASS
 * a keyboard - to play freely or play along
 * a recorder - to record and save songs
 * 3 menus
 * a menu page tracker
 */

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


    /* Application initialization
     * creation of the 3 menus and the choices
     * creation of the keyboard
     * creation of the recorder
     */
    void init();

    /* Application
     * the only method called in the main
     * initialized the app
     * displays the piano and the menu
     * the user navigates in the menus and can play the piano, record songs, listen to it
     */
    void start();

    // Jingle played when the app starts
    void jingle();

    // Displays app logo
    void logo();


    // menus controllers
    void mainMenuController(char);
    void pianoMenuController(char);
    void recMenuController(char);
};


#endif //BEEPIANO_BEEPIANO_H
