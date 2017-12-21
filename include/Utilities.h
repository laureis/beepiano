//
// Created by L on 19/12/2017.
//

#ifndef BEEPIANO_UTILITIES_H
#define BEEPIANO_UTILITIES_H

#include <dirent.h>
#include <iostream>
#include <vector>
#include <map>
#include <conio.h>

// MAP NOTES
// If we can access to the frequency of a note with the map
// do | c, do# | C, re | d, re# | D, mi | e, fa | f, fa# | F, sol | g, sol# | G, la | a, la# | A, si | b

static bool isNote(char n) {

    char notes[12] = { 'c', 'C', 'd', 'D', 'e', 'f', 'F', 'g', 'G', 'a', 'A', 'b' };
    for (int i = 0; i < 12; i ++) {
        if (n == notes[i]) return true;
    }
    return false;
}

static std::map<char, double> createMapNotes() {

    std::map<char, double> mapNotes;
    double a = 1.059463;
    double freq = 262;
    char index[12] = { 'c', 'C', 'd', 'D', 'e', 'f', 'F', 'g', 'G', 'a', 'A', 'b' };
    for (char i : index) {
        mapNotes[i] = freq;
        freq *= a;
    }
    return mapNotes;
}


static std::map<char,double> mapNotes = createMapNotes();

// LINKING THE KEYS TO THE NOTES

static std::map<char, char> createMapKeys() {

    std::map<char, char> mapKeys;
    mapKeys['q'] = 'c';
    mapKeys['z'] = 'C';
    mapKeys['s'] = 'd';
    mapKeys['e'] = 'D';
    mapKeys['d'] = 'e';
    mapKeys['f'] = 'f';
    mapKeys['t'] = 'F';
    mapKeys['g'] = 'g';
    mapKeys['y'] = 'G';
    mapKeys['h'] = 'a';
    mapKeys['u'] = 'A';
    mapKeys['j'] = 'b';
    return mapKeys;
}
static std::map<char, char> mapKeys = createMapKeys();

// POSITION ON KEYBOARD

static std::map<char, int> createMapPosition() {

    std::map<char, int> mapKeys;
    char index[12] = { 'c', 'C', 'd', 'D', 'e', 'f', 'F', 'g', 'G', 'a', 'A', 'b' };
    int pos = 2;
    for (char i : index) {
        mapKeys[i] = pos;
        if (i=='e')pos+=2;
        pos+=2;
    }
    return mapKeys;
}
static std::map<char, int> mapPosition = createMapPosition();


static int widthRange = 28;

static int charToInt(char c) {
    int e = 1 - '1';
    return c + e;
}

static char intToChar(int i) {
    int e = '1' - 1;
    return i + e;
}

template<typename Type>
static void print(Type s) {
    std::cout << s;
}

template<typename Type>
static Type scan(Type s) {
    getline(std::cin, s);
    return s;
}

static void returnLine() {

    std::cout << std::endl;
}

static void clear() {

    system("cls");
}

static void center() {
    print("\t\t");
}

static void playInstructions() {
    returnLine();returnLine();
    center(); print("press ESC to go back           press w to - octave            press x to + octave");
}

static void recordInstructions() {
    returnLine(); returnLine();
    center(); print("press ESC to save recording           press w to - octave            press x to + octave");
}

static void drawPiano() {

    returnLine(); returnLine();
    center(); print(" ___________________________________________________________________________________");returnLine();
    center(); print("|  ### ###  |  ### ### ###  |  ### ###  |  ### ### ###  |  ### ###  |  ### ### ###  |");returnLine();
    center(); print("|  ### ###  |  ### ### ###  |  ### ###  |  ### ### ###  |  ### ###  |  ### ### ###  |");returnLine();
    center(); print("|  ### ###  |  ### ### ###  |  ### ###  |  ### ### ###  |  ### ###  |  ### ### ###  |");returnLine();
    center(); print("|  #z# #e#  |  #t# #y# #u#  |  #z# #e#  |  #t# #y# #u#  |  #z# #e#  |  #t# #y# #u#  |");returnLine();
    center(); print("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |");returnLine();
    center(); print("| q | s | d | f | g | h | j | q | s | d | f | g | h | j | q | s | d | f | g | h | j |");returnLine();
}


static std::vector<std::string> getFileList(const char* sdir) {
    std::vector<std::string> fileList;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (sdir)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::string str = ent->d_name;
            if (str.find("rec")!=std::string::npos) fileList.push_back(str);
        }
        closedir (dir);
    }
    return fileList;
}


static char selectChoice(char min, char max, bool esc) {

    char choice = getch();
    if ((choice == 27) && (esc)) return choice;
    if ((choice < min) || (choice > max)) {
        throw int(1);
    }
    else return choice;
}

static void drawNote(int type) {

    if (type%2==0) {
        returnLine(); returnLine();
        center();center(); print("     ;");returnLine();
        center();center();print("     ;;");returnLine();
        center();center();print("     ;';.");returnLine();
        center();center();print("     ;  ;;");returnLine();
        center();center();print("     ;   ;;");returnLine();
        center();center();print("     ;    ;;");returnLine();
        center();center();print("     ;    ;;");returnLine();
        center();center();print("     ;   ;'");returnLine();
        center();center();print("     ;  ' ");returnLine();
        center();center();print(",;;;,; ");returnLine();
        center();center();print(";;;;;;");returnLine();
        center();center();print("`;;;;'");returnLine();
    }
    else {
        returnLine(); returnLine();
        center(); print("     ;;;;;;;;;;;;;;;;;;;");returnLine();
        center(); print("     ;;;;;;;;;;;;;;;;;;;");returnLine();
        center(); print("     ;                 ;");returnLine();
        center(); print("     ;                 ;");returnLine();
        center(); print("     ;                 ;");returnLine();
        center(); print("     ;                 ;");returnLine();
        center(); print("     ;                 ;");returnLine();
        center(); print("     ;                 ;");returnLine();
        center(); print("     ;                 ;");returnLine();
        center(); print(",;;;;;            ,;;;;;");returnLine();
        center(); print(";;;;;;            ;;;;;;");returnLine();
        center(); print("`;;;;'            `;;;;'");returnLine();
    }
}

#endif //BEEPIANO_UTILITIES_H
