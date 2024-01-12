#include <iostream>
#include <map>

void addItem(std::map<std::string, int>& inventory, std::string item, int count) {
    auto search = inventory.find(item);
    if (search != inventory.end()) inventory[item] += count;
    else inventory.insert({item, count});
}

void addItem(std::map<std::string, int>& inventory, std::string item, float money) {
    // your code here
    auto search = inventory.find(item);
    if (search != inventory.end()) inventory[item] += 1;
    else inventory.insert({item, 1});
    inventory.insert({item, 1});

    search = inventory.find("MONEY");
    if (search != inventory.end()) inventory["MONEY"] += money;
    else inventory.insert({"MONEY", money});
}

int main(){
    std::map<std::string, int> inventory;
    addItem(inventory, "sword", 1);
    addItem(inventory, "shield", 2);
    addItem(inventory, "shield", 5.0F);
    addItem(inventory, "armor", 3.0F);

    for (const auto &[key, value] : inventory)
        std::cout << key << " " << value << std::endl;
}
