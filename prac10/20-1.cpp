
#include <iostream>
#include <map>
#include <tuple>

int main() {
    std::map<int, int> perimeters;
    int result = 0;
    int max_number_of_solutions = 0;

    // Loop through all perimeters up to 1000
    for (int p = 2; p <= 1000; p += 2) {
        int number_of_solutions = 0;

        // For every perimeter, try all possible integral side lengths a and b
        for (int a = 2; a < (p / 3); ++a) {
            if (p * (p - 2 * a) % (2 * (p - a)) == 0) {
                int b = p * (p - 2 * a) / (2 * (p - a));
                int c = p - a - b;
                
                if (a * a + b * b == c * c) {
                    ++number_of_solutions;
                }
            }
        }

        if (number_of_solutions > max_number_of_solutions) {
            max_number_of_solutions = number_of_solutions;
            result = p;
        }
    }

    std::cout << "The perimeter with the most solutions is: " << result << " with " << max_number_of_solutions << " solutions." << std::endl;
    return 0;
}
