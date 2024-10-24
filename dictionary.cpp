#include <iostream>
#include <vector>
using namespace std;

template<typename K, typename V>
class Dictionary {
private:
    vector<pair<K, V>> items;

public:
    void add(K key, V value) {
        for (auto& item : items) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }
        items.push_back(make_pair(key, value));
    }

    V& operator[](K key) {
        for (auto& item : items) {
            if (item.first == key) {
                return item.second;
            }
        }
        items.push_back(make_pair(key, V()));
        return items.back().second;
    }

    friend ostream& operator<<(ostream& os, const Dictionary& dictionary) {
        os << "Key : Value" << endl;
        for (const auto& item : dictionary.items) {
            os << item.first << " : " << item.second << endl;
        }
        return os;
    }
};

int main() {
    Dictionary<int, string> deviceCodeMap;

    deviceCodeMap.add(1, "D1");
    deviceCodeMap.add(2, "D2");
    deviceCodeMap.add(3, "D3");
    deviceCodeMap.add(4, "D4");

    string deviceName = deviceCodeMap[2];
    cout << deviceName << endl;

    cout << deviceCodeMap;

    return 0;
}
