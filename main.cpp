#include "counterbox.cpp"
#include "genstack.cpp"
#include "reader.cpp"

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2) {
        cout << "You must specify an input file. " << endl;
        cout << argv[0] << "  <filename>" << endl;
    }
    else {
        bool readNextFile = true;
        string filename = argv[1];

        while (readNextFile) {
            try {
                Reader r(filename);
            }
            catch (const char* msg) {
                cerr << msg;
                cerr << endl;
            }
            catch (string msg) {
                cerr << msg <<  endl;
            }
            catch (...) {
                // default error;
                cerr << "Unkown exception found." << endl;
            }
            
            char tryAgain;
            bool keepLooping = true;

            // Keep asking until the user enters Y or N
            while (keepLooping) {
                cout << "Would you like to analyze another file ? (Y/N)" << endl;
                cin >> tryAgain;
                tryAgain = toupper(tryAgain);

                switch (tryAgain) {
                case 'Y' : 
                    readNextFile = true;
                    keepLooping = false;
                    cout << "Enter the file name." << endl;
                    cin >> filename;
                    break;

                case 'N' :
                    readNextFile = false;
                    keepLooping = false;
                    break;

                default:
                    cout << "Invalid answer, please enter Y or N";
                    keepLooping = true;
                    break;
                }
            }
             
            
        }
    }
    return 0; 
}


