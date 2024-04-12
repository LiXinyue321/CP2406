#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

class Database {
public:
    void add(Person person);
    void clear();
    void save(string_view filename) const;
    void load(string_view filename);
    void outputAll(ostream& output) const;

private:
    vector<Person> m_persons;
};

void Database::add(Person person) {
    m_persons.push_back(move(person));
}

void Database::clear() {
    m_persons.clear();
}

void Database::save(string_view filename) const {
    ofstream outFile{ filename.data(), ios_base::trunc };
    if (!outFile) {
        throw runtime_error("Cannot open file: " + string(filename));
    }

    for (const auto& person : m_persons) {
        outFile << quoted(person.getFirstName())
                << quoted(person.getLastName())
                << quoted(person.getInitials()) << endl;
    }
}

void Database::load(string_view filename) {
    ifstream inFile{ filename.data() };
    if (!inFile) {
        throw runtime_error("Cannot open file: " + string(filename));
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        istringstream inLine{ line };
        string firstName, lastName, initials;
        inLine >> quoted(firstName) >> quoted(lastName) >> quoted(initials);
        if (inLine.fail()) {
            throw logic_error("Error reading person. Ignoring.");
        }
        m_persons.push_back(Person{ move(firstName), move(lastName), move(initials) });
    }
}

void Database::outputAll(ostream& output) const {
    for (const auto& person : m_persons) {
        person.output(output);
    }
}

int main() {
    Database db;
    try {
        db.load("valid_data.txt");  // Assume this file exists and is correct
        db.outputAll(cout);
    } catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
    } catch (const logic_error& e) {
        cerr << "Logic error: " << e.what() << endl;
    }

    return 0;
}
