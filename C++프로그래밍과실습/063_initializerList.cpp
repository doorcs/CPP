#include <iostream>
#include <string>
#include <map>
#include <initializer_list>
#include <utility>
using namespace std;

class Phonebook {
private:
    map<string, int> contacts;
public:
    Phonebook(initializer_list <pair<string, int>> lst){
        for(auto it: lst) contacts.insert({it.first, it.second});
    }
    void print() const {
        for(auto it: contacts) cout << it.first << ' ' << it.second << endl;
    }
};

int main() {
    Phonebook p = {{"Kim", 24}, {"Lee", 21}};
    p.print();
    return 0;
}
