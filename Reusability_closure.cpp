#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

std::function<bool(const string&)> checkStringStartWithAny(const string& startWith) {
    std::function<bool(const string&)> predicate = [startWith](const string& item) {
        return !item.empty() && item.substr(0, startWith.size()) == startWith;
    };
    return predicate;
}

template <typename T>
vector<T> filter(const vector<T>& source, std::function<bool(const T&)> predicateFunObj) {
    vector<T> filteredItems;
    for (const T& item : source) {
        if (predicateFunObj(item)) {
            filteredItems.push_back(item);
        }
    }
    return filteredItems;
}

int main() {
    vector<string> cities = {"New York", "Los Angeles", "Chicago", "New Jersey"};

    std::function<bool(const string&)> predicate = checkStringStartWithAny("N");
    vector<string> newCities = filter(cities, predicate);
    std::cout << "Cities that start with 'N':" << std::endl;
    for (const string& newCity : newCities) {
        std::cout << newCity << std::endl;
    }

    predicate = checkStringStartWithAny("C");
    newCities = filter(cities, predicate);
    std::cout << "Cities that start with 'C':" << std::endl;
    for (const string& newCity : newCities) {
        std::cout << newCity << std::endl;
    }

    return 0;
}
