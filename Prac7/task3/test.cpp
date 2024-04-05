import person;
import <iostream>;
import <sstream>;
import <fstream>;

using namespace std;

int main()
{
    Person person{ "John", "Doe" };

    // Output to the standard console
    person.output(cout);

    // Output to a stringstream
    stringstream ss;
    person.output(ss);
    cout << "StringStream Output: " << ss.str();

    // Output to a file
    ofstream file("PersonDetails.txt");
    person.output(file);
    file.close();

    cout << "Details written to PersonDetails.txt\n";
}
