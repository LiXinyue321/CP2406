#ifndef DATABASE_H
#define DATABASE_H

#include "Person.h"
#include <vector>
#include <fstream>
#include <sstream>

class Database {
public:
    void add(const Person& person) {
        m_persons.push_back(person);
    }

    void clear() {
        m_persons.clear();
    }

    void save(const std::string& filename) const {
        std::ofstream file(filename);
        for (const auto& person : m_persons) {
            file << std::quoted(person.getFirstName()) << " "
                 << std::quoted(person.getLastName()) << " "
                 << std::quoted(person.getInitials()) << "\n";
        }
    }

    void load(const std::string& filename) {
        clear();
        std::ifstream file(filename);
        std::string firstName, lastName, initials;
        while (file >> std::quoted(firstName) >> std::quoted(lastName) >> std::quoted(initials)) {
            add(Person(firstName, lastName, initials));
        }
    }

    void outputAll(std::ostream& out) const {
        for (const auto& person : m_persons) {
            person.output(out);
        }
    }

private:
    std::vector<Person> m_persons;
};

#endif // DATABASE_H
