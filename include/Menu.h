//
// Created by L on 19/12/2017.
//

#ifndef BEEPIANO_MENU_H
#define BEEPIANO_MENU_H

#include <string>
#include <vector>

class Menu {

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

        // Instructions
        void display();

};


#endif //BEEPIANO_MENU_H
