#include <iostream>
#include <string>

class CityFilter {
private:
    std::string cities[4] = {"New York", "Los Angeles", "Chicago", "New Jersey"};
    std::string citiesStartingWithN[4];
    int count;

public:
    CityFilter() : count(0) {}

    void filterCities() {
        count = 0;
        int size = sizeof(cities) / sizeof(cities[0]);

        for (int i = 0; i < size; ++i) {
            if (cities[i].front() == 'N' && cities[i].length() > 8 && count < 4) {
                citiesStartingWithN[count] = cities[i];
                count++;
            }
        }
    }

    void printFilteredCities() const {
        std::cout << "Cities starting with 'N' and longer than 8 characters:" << std::endl;
        for (int i = 0; i < count; ++i) {
            std::cout << citiesStartingWithN[i] << std::endl;
        }
    }
};

int main() {
    CityFilter cityFilter;
    cityFilter.filterCities();
    cityFilter.printFilteredCities();

    return 0;
}
