#include <iostream>
#include <exception>
#include <vector>

using namespace std;

// Throws a logic_error exception if the number of elements
// in the given dataset is not even.
void verifyDataSize(const vector<int>& data)
{
    if (data.size() % 2 != 0)
        throw logic_error("Number of data points must be even.");
}

// Throws a domain_error exception if one of the datapoints is negative.
void processData(const vector<int>& data)
{
    // Verify the size of the given dataset.
    try {
        verifyDataSize(data);
    } catch (const logic_error&) {
        cerr << "Invalid number of data points in dataset. Aborting." << endl;
        throw;
    }

    // Verify for negative datapoints.
    for (auto& value : data) {
        if (value < 0)
            throw domain_error("Negative datapoints not allowed.");
    }
    // Process data ...
}

int main()
{
    try {
        vector<int> data_negative{1, 2, 3, -5, 6, 9};  // Triggers domain_error
        processData(data_negative);
    } catch (const domain_error& caughtException) {
        cerr << "domain_error: " << caughtException.what() << endl;
    }

    try {
        vector<int> data_odd{1, 2, 3, 4, 5};  // Triggers logic_error
        processData(data_odd);
    } catch (const logic_error& caughtException) {
        cerr << "logic_error: " << caughtException.what() << endl;
    }

    return 0;
}
