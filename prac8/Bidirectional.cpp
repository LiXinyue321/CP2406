#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <stdexcept>

using namespace std;

void changeNumberForID(string_view filename, int id, string_view newNumber) {
    fstream ioData{filename.data(), ios::in | ios::out};
    if (!ioData) {
        throw runtime_error("Error while opening file " + string(filename));
    }

    // Loop until the end of file
    while (ioData) {
        int idRead;
        ioData >> idRead;
        if (!ioData)
            break;

        if (idRead == id) {
            ioData.seekp(ioData.tellg() - static_cast<streamoff>(sizeof(int))); 
            ioData << " " << newNumber << endl; // Ensure the file is correctly updated
            return;
        }

        string number;
        ioData >> number; // Read the current number to advance the stream
    }
    throw logic_error("ID not found");
}

int main() {
    try {
        changeNumberForID("data.txt", 263, "415-555-3333");
        cout << "Number changed successfully." << endl;
    } catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
    }

    try {
        changeNumberForID("data.txt", 999, "999-999-9999"); // ID does not exist, should trigger logic_error
    } catch (const logic_error& e) {
        cerr << "Logic error: " << e.what() << endl;
    }

    return 0;
}
