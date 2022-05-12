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
    map<string, set<unsigned>>::iterator it_print = result.begin();
    for(it_print; it_print != result.end(); it_print++){
        cout << "printing key" << it_print->first << " ";//<< " " << it->second <<
        set<unsigned>::iterator it_set = it_print->second.begin();
        for(it_set; it_set != it_print->second.end(); it_set++){
            cout << *it_set << " ";
        };
        cout << endl;

    }
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
    while(true){
        cout << "hi\n";
        i = input.find(space);  //maybe convert space back to  " " quotes
        cout << i << endl;
        if(i==string::npos){
            cout << "--" << input <<"--" << endl;
            cout << "here\n";

            tokens.push_back(input); 
            cout << "here\n";

            return tokens; 
        }
        cout << "here\n";
        tokens.push_back(input.substr(0,i));  //or maybe it should end at i-1 since you don't wanna include spaces
        cout << "||" << input <<"||" << endl;
        input.erase(0,i+1);
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
            cout << "1\n";
            it = output.find(word);
                        cout << "2\n";

            if(it!= output.end()){
                            cout << "3\n";

                it->second.insert(line_num);
                            cout << "4\n";

            }
            else{
                            cout << "5\n";

                output.insert(pair<string, set<unsigned> >(word, set<unsigned>()));
                cerr << "6\n";
                cerr << "7\n";

                // it = output.find(word);
                cout << "7\n";

                if(it!= output.end()){
                    cout << "8\n";

                    it->second.insert(line_num);
                }
                else{
                    cout << "error adding key\n";
                }
                // pair.second.insert(line_num);
            }
        };

        line_num++;
    }
    cout << "end\n";
    return output;

    //create ordered map??
    //use getline
    //call tokenize
    //update appropriate value(set of line #s), for the appropriate string key
};