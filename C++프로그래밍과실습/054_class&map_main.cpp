#include "054_class&map.h"

void addContact(map<string, Person>& phoneBook, const string& name, const string& number) {
    phoneBook[name] = Person(name, number);
}

void deleteContact(map<string, Person>& phoneBook, const string& name) {
    phoneBook.erase(name);
}

void modifyContact(map<string, Person>& phoneBook, const string& name, const string& newNumber) {
    auto it = phoneBook.find(name);
    if (it != phoneBook.end()) {
        it->second.modifyNumber(newNumber);
    }
}

void findContact(const map<string, Person>& phoneBook, const string& name) {
    auto it = phoneBook.find(name);
    if (it != phoneBook.end()) {
        it->second.print();
    }
}

void printAllContacts(const map<string, Person>& phoneBook) {
    for (const auto& entry : phoneBook) {
        entry.second.print();
    }
}

int main() {
    map<string, Person> phoneBook;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string name, number;
        cin >> name >> number;
        addContact(phoneBook, name, number);
    }

    string command, name, number;
    while (true) {
        cin >> command;
        if (command == "ADD") {
            cin >> name >> number;
            addContact(phoneBook, name, number);
        } else if (command == "DEL") {
            cin >> name;
            deleteContact(phoneBook, name);
        } else if (command == "MOD") {
            cin >> name >> number;
            modifyContact(phoneBook, name, number);
        } else if (command == "FIN") {
            cin >> name;
            findContact(phoneBook, name);
        } else if (command == "QUI") {
            break;
        }
    }
    printAllContacts(phoneBook);
    return 0;
}
