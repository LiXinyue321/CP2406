
#include <iostream>
#include <vector>
#include <iterator> 

int main() {
    std::vector<int> values = {2, 5};
    
    // Use 'insert()' to insert 3 and 4 into the 'values' vector at the correct place
    auto it = std::begin(values) + 1; // Iterator to the position after the first element
    values.insert(it, 3);             
    values.insert(it + 1, 4);       

    std::vector<int> initial = {0, 1};
    
    // Insert the contents of 'initial' at the beginning of 'values'
    values.insert(std::begin(values), std::begin(initial), std::end(initial));
    
    std::vector<int> reversed;
    
    for (auto rit = values.rbegin(); rit != values.rend(); ++rit) {
        reversed.push_back(*rit);
    }
    
    for (const auto& value : reversed) {
        std::cout << value << " ";
    }
    
    return 0;
}
