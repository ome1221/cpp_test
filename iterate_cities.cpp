#include <iostream>
#include <string>
#include <vector>

int main() {
    // Array of cities
    std::string cities[] = {"New York", "Los Angeles", "Chicago", "New Jersey"};
    
    // Vector to store cities starting with 'N'
    std::vector<std::string> citiesStartingWithN;

    // Get the number of elements in the array
    int size = sizeof(cities) / sizeof(cities[0]);

    // Iterate through the array and check for cities starting with 'N'
    for (int i = 0; i < size; ++i) {
        if (cities[i].front() == 'N') { // Check if the first letter is 'N'
            citiesStartingWithN.push_back(cities[i]); // Add to the vector
        }
    }

    // Output the results
    std::cout << "Cities starting with 'N':" << std::endl;
    for (const auto& city : citiesStartingWithN) {
        std::cout << city << std::endl;
    }

    return 0;
}
