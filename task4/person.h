#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <iomanip> // For std::quoted in C++17

class Person {
public:
    Person() = default;
    Person(std::string firstName, std::string lastName, std::string initials = "")
        : m_firstName(std::move(firstName)),
          m_lastName(std::move(lastName)),
          m_initials(initials.empty() ? std::string(1, firstName[0]) + lastName[0] : std::move(initials)) {}

    // Accessors and mutators
    const std::string& getFirstName() const { return m_firstName; }
    void setFirstName(std::string firstName) { m_firstName = std::move(firstName); }

    const std::string& getLastName() const { return m_lastName; }
    void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

    const std::string& getInitials() const { return m_initials; }
    void setInitials(std::string initials) { m_initials = std::move(initials); }

    void output(std::ostream& out) const {
        out << getFirstName() << " " << getLastName() << " (" << getInitials() << ")\n";
    }

private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_initials;
};

#endif // PERSON_H
