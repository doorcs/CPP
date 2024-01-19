#include <iostream>
#include <string>
#include <map>
using namespace std;

enum class Genre { Action, Comedy, Drama, Romance, SciFi };
enum class Rating { OneStar = 1, TwoStars, ThreeStars, FourStars, FiveStars };

int main(){
    map<string, Genre> genre;
    map<string, pair<int, int>> rating;
    string movie;
    int g, r;

    while(true){
        getline(cin, movie);
        if(movie == "q")
            break;
        cin >> g >> r;
        cin.ignore();
        genre[movie] = static_cast<Genre>(g);
        auto find = rating.find(movie);

        if(find == rating.end()) rating[movie] = {1, r};
        else{
            rating[movie].first++;
            rating[movie].second += r;            
        }
    }
    for(auto it = genre.begin(); it != genre.end(); it++){        
        cout << it->first << ": " << rating[it->first].first << " ratings, average rating " << rating[it->first].second /  rating[it->first].first << " stars, genre: " <<  static_cast<int>(it->second) << endl;
    }
}
