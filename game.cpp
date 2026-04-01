#include <iostream>
#include <vector>
#include <algorithm>

struct Game {
   int deadline;
   int penalty;
   int id;

   Game(int d, int p, int i) : deadline(d), penalty(p), id(i) {}
};

bool compareGames(const Game& a, const Game& b) {
   return a.penalty > b.penalty;
}

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);

   long long m;
   std::cin >> m;

   int n;
   std::cin >> n;

   std::vector<int> deadlines(n);
   for (int i = 0; i < n; ++i) {
       std::cin >> deadlines[i];
   }

   std::vector<int> penalties(n);
   for (int i = 0; i < n; ++i) {
       std::cin >> penalties[i];
   }

   std::vector<Game> games;
   games.reserve(n);
   for (int i = 0; i < n; ++i) {
       games.emplace_back(deadlines[i], penalties[i], i + 1);
   }

   std::sort(games.begin(), games.end(), compareGames);

   std::vector<bool> time_slots_used(n + 1, false);

   long long total_penalty_incurred = 0;

   for (const auto& game : games) {
       bool scheduled = false;
       for (int s = game.deadline; s >= 1; --s) {
           if (!time_slots_used[s]) {
               time_slots_used[s] = true;
               scheduled = true;
               break;
           }
       }

       if (!scheduled) {
           total_penalty_incurred += game.penalty;
       }
   }

   long long max_money = m - total_penalty_incurred;

   std::cout << max_money << std::endl;

   return 0;
}
