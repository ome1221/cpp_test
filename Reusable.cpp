#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  strategy1: 
class StartsWith {
    char firstAlp;
public:
    StartsWith(char alp) : firstAlp(alp) {}

    bool check(const string& item) const {
        return !item.empty() && item[0] == firstAlp;
    }
};

//strategy2:


template<typename Strategy>
vector<string> filter(const vector<string>& source, const Strategy& strategy) {
    vector<string> filteredStrings;
    for (const string& item : source) {
        if (strategy.check(item)) {
            filteredStrings.push_back(item);
        }
    }
    return filteredStrings;
}

int main() {
    vector<string> cities = {"New York", "Los Angeles", "Chicago", "New Jersey"};

    // Using strategy1
    char firstAlp = 'L'; // Change as per need
    StartsWith startsWithStrategy(firstAlp);
    vector<string> filteredCitiesByStart = filter(cities, startsWithStrategy);

    cout << "Cities that start with '" << firstAlp << "':" << endl;
    for (const string& city : filteredCitiesByStart) {
        cout << city << endl;
    }

    return 0;
}
