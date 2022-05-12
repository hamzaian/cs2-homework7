#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

/*******************************************************************************
 *  Function prototypes
*******************************************************************************/

vector<string> tokenize(string);
map<string, set<unsigned>> createMap(ifstream&);

/*******************************************************************************
 *  Description:
 *      Starting point of the program. Opens an existing file chosen by the user
 *      for input. Uses the data in the file to create a map. Displays the
 *      contents of the map.
 * 
 *  Input(s):
 *      N/A
 * 
 *  Output:
 *      An integer that signals the exit code to the operating system (OS)
*******************************************************************************/

int main() {
    // variables
    ifstream inputFile;
    string   filename;

    // open the file
    do {
        cout << "Enter the filename: ";
        getline(cin, filename);
        inputFile.open(filename);
    } while (inputFile.fail());
    inputFile.seekg(0);

    // call the function
    map<string, set<unsigned>> result = createMap(inputFile);

    // close the file
    inputFile.close();

    // TODO: iterate over the map to display the pairs

    // terminate
    return 0;
}

vector<string> tokenize(string){
    
};
map<string, set<unsigned>> createMap(ifstream&){

};