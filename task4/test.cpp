#include "Person.h"
#include "Database.h"
#include <iostream>

int main() {
    Database db;
    db.add(Person{ "John", "Doe" });
    db.add(Person{ "Marc", "Gregoire", "Mg" });
    db.add(Person{ "Peter", "Van Weert", "PVW" });

    std::cout << "Initial database contents:\n";
    db.outputAll(std::cout);

    db.save("person.db");

    db.clear();
    std::cout << "\nDatabase contents after clearing:\n";
    db.outputAll(std::cout);

    std::cout << "\nLoading database from file...\n";
    db.load("person.db");
    std::cout << "\nDatabase contents after loading from file:\n";
    db.outputAll(std::cout);
}
