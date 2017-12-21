//
// Created by L on 19/12/2017.
//

#include "../include/Menu.h"
#include "../include/Utilities.h"


Menu::Menu(const std::string &m_title, const std::vector<std::string> &m_choices) : m_title(m_title), m_choices(m_choices) {}
Menu::~Menu() {}

std::string Menu::getTitle() const { return m_title; }
const std::vector<std::string> &Menu::getChoices() const { return m_choices; }

void Menu::setChoices(const std::vector<std::string> &m_choices) { Menu::m_choices = m_choices; }
void Menu::setTitle(std::string title) { m_title = title; }

void Menu::display() {

    returnLine();
    center(); print("---------- "); print(m_title);returnLine();returnLine();
    for (int i = 0; i< m_choices.size(); i++) {
        center();
        print("press ");
        print(i + 1);
        print(" to ");
        print(m_choices[i]);
        returnLine();
        returnLine();
    }
    center();print("press ESC to go back");
}
