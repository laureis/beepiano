//
// THIS FILE CONTAINS ALL THE METHODS THAT CAN BE USEFUL TO ANY CLASS
//

#ifndef BEEPIANO_UTILITIES_H
#define BEEPIANO_UTILITIES_H

#include <dirent.h>
#include <iostream>
#include <vector>
#include <map>
#include <conio.h>

// converts a number between 0 and 9 from char type to int type
static int charToInt(char c) {
    int e = 1 - '1';
    return c + e;
}

// converts a number between 0 and 9 from int type to char type
static char intToChar(int i) {
    int e = '1' - 1;
    return i + e;
}

// returns true if a char is a note false if note
static bool isNote(char n) {

    char notes[12] = { 'c', 'C', 'd', 'D', 'e', 'f', 'F', 'g', 'G', 'a', 'A', 'b' };
    for (int i = 0; i < 12; i ++) {
        if (n == notes[i]) return true;
    }
    return false;
}

/* map storing the notes frequencies
 * eg : if we want to get the C note frequency --> mapNotes['C']
 */
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

/* Map that links the computer's keyboard keys to the note
 * used when the playerd hits a key, so we know which note he wants to play
 */
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

/* Note position on the keyboard
 * used when we display the notes
 */
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

// widthRange used for displaying the piano
static int widthRange = 28;

static bool isValue(char v) {

    char values[4] = { '1', '2', '4', '8' };
    for (int i = 0; i < 4; i ++) {
        if (v == values[i]) return true;
    }
    return false;
}

static bool isInRange(char r) {

    return (r >= '0') && (r <= '2');
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

/* get into a directory and get the files
 * containing 'rec' in their names
 */
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

/* makes sure that the users chooses a number between min and max
 * or esc (to quit)
 */
static char selectChoice(char min, char max, bool esc) {

    char choice = getch();
    if ((choice == 27) && (esc)) return choice;
    if ((choice < min) || (choice > max)) {
        throw int(1);
    }
    else return choice;
}



#endif //BEEPIANO_UTILITIES_H
