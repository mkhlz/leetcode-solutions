#include <bits/stdc++.h>
using namespace std;

// custom comparator for the set of cuising
// higher rating first, for equal rating, lexicograhically smaller name first
struct FoodComp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first != b.first) return a.first > b.first; // higher rating -> comes earlier
        return a.second < b.second; // lexicographically smaller -> earlier
    }
};

class FoodRatings {
private:
    // map food -> pair(cuisine, rating)
    unordered_map<string, pair<string, int>> foodInfo;
    // map cuisine -> set of (rating, foodName) w the FoodComp comparator
    unordered_map<string, set<pair<int, string>, FoodComp>> cuisineSets;
public:
    // constructor to load list of foods, their cuisines, initial ratings
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            const string &food = foods[i];
            const string &cuisine = cuisines[i];
            int rating = ratings[i];
            // store info so we can find cuisine/rating by food name
            foodInfo[food] = {cuisine, rating};
            // insert into the cuisine's ordered set
            cuisineSets[cuisine].insert({rating, food});
        }
    }
    // change food rating - remove old food pair and insert new one
    void changeRating(string food, int newRating) {
        auto &info = foodInfo[food];
        string cuisine = info.first;
        int oldRating = info.second;

        // remove old entry
        auto &s = cuisineSets[cuisine];
        s.erase({oldRating, food});
        // insert new one
        s.insert({newRating, food});
        info.second = newRating;
    }
    // function to return highest rated food (if tie -> lexicographically smallest)
    string highestRated(string cuisine) {
        auto &s = cuisineSets[cuisine];
        // first element in our ordering is desired food
        return s.begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */