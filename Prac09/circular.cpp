#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

std::vector<bool> sieve_of_eratosthenes(int limit) {
    std::vector<bool> prime(limit + 1, true);
    prime[0] = prime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= limit; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

std::vector<int> get_primes(int limit) {
    std::vector<bool> is_prime = sieve_of_eratosthenes(limit);
    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

bool is_circular_prime(int n, const std::unordered_set<int>& primes_set) {
    std::string s = std::to_string(n);
    for (size_t i = 0; i < s.length(); ++i) {
        std::rotate(s.begin(), s.begin() + 1, s.end());
        if (primes_set.find(std::stoi(s)) == primes_set.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    const int MAX_N = 1000000;
    auto primes = get_primes(MAX_N);
    std::unordered_set<int> primes_set(primes.begin(), primes.end());
    
    int count = 0;
    for (int prime : primes) {
        if (is_circular_prime(prime, primes_set)) {
            count++;
            std::cout << "n=" << prime << ", count=" << count << std::endl;
        }
    }
    std::cout << "Total circular primes below " << MAX_N << ": " << count << std::endl;

    return 0;
}
