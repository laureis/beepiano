#ifndef BEEPIANO_MENU_H
#define BEEPIANO_MENU_H

#include <string>
#include <vector>

class Menu {

    /* a menu has a title and choices
     * it organizes the app so the user know what he can do with the application
     * and until it stops running
     */

    private:
        std::string m_title;
        std::vector<std::string> m_choices;

    public:

        // constructor
        Menu(const std::string &m_title, const std::vector<std::string> &m_choices);

        // destructor
        virtual ~Menu();

        // getters
        std::string getTitle() const;
        const std::vector<std::string> &getChoices() const;

        // setters
        void setTitle(std::string);
        void setChoices(const std::vector<std::string> &m_choices);tChoice();

        // display the choices
        void display();

};


#endif //BEEPIANO_MENU_H
