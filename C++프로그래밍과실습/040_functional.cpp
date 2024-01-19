#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

struct Champion {
    std::string name;
    int health;
    int attack;
};
auto findChampionMoreThanHealth(std::vector<Champion> champions, int health) {
}
auto findChampionMoreThanAttack(std::vector<Champion> champions, int attack) {
}
auto findChampionWithCondition(std::vector<Champion> champions, std::function<bool(Champion)> condition) {
    std::vector<Champion> result;
    for (auto& c : champions)
        if(condition(c))
            result.push_back(c);
    return result;
}
void printChampion(const std::vector<Champion> champions){
    for(const auto& it: champions) cout << it.name << ' ' << it.health << ' ' << it.attack << endl;
}
std::vector<Champion> createChampion() {
    std::vector<Champion> champions;
    Champion tryndamere {"Tryndamere", 625, 72};
    Champion kled {"Kled", 740, 35};
    Champion garen {"Garen", 620, 66};
    champions.push_back(tryndamere);
    champions.push_back(kled);
    champions.push_back(garen);
    return champions;
}

vector<string> split(string in, string d){
    vector<string> ret;
    int pos;

    while((pos=in.find(d))!=string::npos){
        ret.push_back(in.substr(0, pos));
        in.erase(0, pos+1);
    }
    ret.push_back(in);
    return ret;
}

int main() {
    auto champions = createChampion();
    string input;
    string a;
    int b;
    while (cin >> input) {
        auto vec = split(input, ":");
        a = vec[0];
        b = stoi(vec[1]);
        if (a == "health") {
            function<bool(Champion)> func = [b](Champion c) { return c.health > b; };
            auto res1 = findChampionWithCondition(champions, func);
            printChampion(res1);
        } else {
            function<bool(Champion)> func = [b](Champion c) { return c.attack > b; };
            auto res2 = findChampionWithCondition(champions, func);
            printChampion(res2);
        }
    }
    return 0;
}
