#include <iostream>
#include <fstream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check divisors from 5 to sqrt(n), skipping even numbers
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int countPrimesInFile(const std::string& filename) {
    std::ifstream file(filename);
    int count = 0;
    int number;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return -1;
    }

    while (file >> number) {
        if (isPrime(number)) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    int totalPrimes = countPrimesInFile("NUM.txt");
    
    if (totalPrimes != -1) {
        std::cout << "Total prime numbers found: " << totalPrimes << std::endl;
    }

    return 0;
}
