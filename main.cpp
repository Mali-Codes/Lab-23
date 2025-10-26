#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);

int main_menu();

int main_menu() {
    int choice;

    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "choice: ";
    cin >> choice;
}

int main() {
    srand(time(0));
    bool again;
   
    // ****TESTING IGNORE****
    // Goat g1;                        
    // Goat g2("Billy");               
    // Goat g3("Nanny", 5);           
    // Goat g4("Gruff", 7, "Brown");  

    // cout << "Goat 1: " << g1.get_name() << " (should be empty)" << endl;
    // cout << "Goat 2: " << g2.get_name() << endl;
    // cout << "Goat 3: " << g3.get_name() << ", age " << g3.get_age() << endl;
    // cout << "Goat 4: " << g4.get_name() << ", age " << g4.get_age() 
    //      << ", color " << g4.get_color() << endl;
    
    // return 0;



    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();


    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();


    list<Goat> group;

    if (choice == 1) {
        add_goat(group, names, colors);
    } else if (choice == 2) {
        delete_goat(group);
    } else if (choice == 3) {
        display_trip(group);
    }

    return 0;
}
