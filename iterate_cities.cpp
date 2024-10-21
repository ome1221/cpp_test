#include <iostream>
#include <string>

void filterCitiesStartingWithN(const std::string cities[], int size, std::string results[], int& resultCount) {
    resultCount = 0; // Initialize the count

    for (int i = 0; i < size; ++i) {
        if (cities[i].front() == 'N' && resultCount < 4) { // Check if the first letter is 'N'
            results[resultCount] = cities[i]; // Store in the results array
            resultCount++; // Increment the count
        }
    }
}

int main() {
    // Array of cities
    std::string cities[] = {"New York", "Los Angeles", "Chicago", "New Jersey"};
    
    // Array to store cities starting with 'N'
    std::string citiesStartingWithN[4];
    int count = 0; // To keep track of the number of cities found

    // Get the number of elements in the array
    int size = sizeof(cities) / sizeof(cities[0]);

    // Call the filter function
    filterCitiesStartingWithN(cities, size, citiesStartingWithN, count);

    // Output the results
    std::cout << "Cities starting with 'N':" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << citiesStartingWithN[i] << std::endl;
    }

    return 0;
}
