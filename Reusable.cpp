#include <iostream>
#include <string>
#include <vector>
using namespace std;

//predicate
bool checkStringStartWithN(const string& item){
		return  !item.empty() && item.substr(0, 1) == "N";
}

bool checkStringStartWithL(const string& item){
		return  !item.empty() && item.substr(0, 1) == "L";
}

vector<string> filter(vector<string> source,bool(*predicate)(const string&)){
       std::vector<std::string> filteredStrings;
		for (const string& item : source) {
        // Check if the city starts with "New"
			if (predicate(item)) {
            filteredStrings.push_back(item);
		}
    }
    return filteredStrings;
}


int main() {
    // Create an array of cities
    vector<std::string> cities = {"New York", "Los Angeles", "Chicago", "New Jersey"};

    // Create a vector to hold cities that start with "New"
  vector<string> newCities=filter(cities,&checkStringStartWithL);
  //std::cout << "Cities that start with 'N':" << std::endl;
  std::cout << "Cities that start with 'L':" << std::endl;
    for (const string& newCity : newCities) {
        std::cout << newCity << std::endl;
    }

    return 0;
}
