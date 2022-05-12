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

vector<string> tokenize(string input){
    vector<string> tokens;
    char space = ' ';
    // for(int i=0; i<string::npos; i++){
    //     if (input[i] == space){
    //         tokens.push_back(input.substr(0,i));  //or maybe it should end at i-1 since you don't wanna include spaces
    //         input.erase(0,i);
    //     }
    // }
    int i = 0;
    while(i!=string::npos){
        i = input.find(space);  //maybe convert space back to  " " quotes
        tokens.push_back(input.substr(0,i));  //or maybe it should end at i-1 since you don't wanna include spaces
        input.erase(0,i);
    }

};
map<string, set<unsigned>> createMap(ifstream& file){
    map<string, set<unsigned>> output;
    map<string, set<unsigned>>::iterator it;
    string line;
    vector<string> tokens;
    int line_num = 1;
    while(getline(file, line)){
        tokens = tokenize(line);
        for(string word : tokens){
            it = output.find(word);
            if(it!= output.end()){
                it->second.insert(line_num);
            }
            else{
                output.insert(pair<string, set<unsigned>>(word, set<unsigned>()));
                it = output.find(word);
                if(it!= output.end()){
                    it->second.insert(line_num);
                }
                else{
                    cout << "error adding key\n";
                }
                // pair.second.insert(line_num);
            }
        }

        line_num++;
    }

    //create ordered map??
    //use getline
    //call tokenize
    //update appropriate value(set of line #s), for the appropriate string key
};