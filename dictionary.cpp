#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // Create a map that stores int keys and string values
    map<int, string> deviceCodeMap;
    deviceCodeMap[1] = "D1";
    deviceCodeMap[2] = "D2";
    deviceCodeMap[3] = "D3";
    deviceCodeMap[4] = "D4";

    // Access a specific value using key 2
    string deviceName = deviceCodeMap[2];
    cout << "Accessed device: " << deviceName << endl; // output: D2

    // Dump all the items from the map
    cout << "Key : Value" << endl;
    for (const auto& pair : deviceCodeMap) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Store map entries in a vector as pairs
    vector<pair<int, string>> deviceVector(deviceCodeMap.begin(), deviceCodeMap.end());

    // Output the vector content
    cout << "\nDump from vector:" << endl;
    cout << "Key : Value" << endl;
    for (const auto& pair : deviceVector) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
