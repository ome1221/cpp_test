#include <iostream>
#include <string>
#include <vector>

using namespace std;

//predicate
bool checkStringStartWith(const string& item, char firstAlp){
		return !item.empty() && item[0] == firstAlp;
}

vector<string> filter(const vector<string>& source, bool(*predicate)(const string&, char), char firstAlp) {
    vector<string> filteredStrings;
    for (const string& item : source) {
        if (predicate(item, firstAlp)) {
            filteredStrings.push_back(item);
        }
    }
    return filteredStrings;
}


int main() {
    vector<std::string> cities = {"New York", "Los Angeles", "Chicago", "New Jersey"};

    char firstAlp = 'L'; // Change as per NEed
    vector<string> filteredCities = filter(cities, &checkStringStartWith, firstAlp);

    cout << "Cities that start with '" << firstAlp << "':" << endl;
    for (const string& city : filteredCities) {
        cout << city << endl;
    }

    return 0;
}
