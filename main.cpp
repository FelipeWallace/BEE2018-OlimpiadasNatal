#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct pais {
    int ouro = 0, prata = 0, bronze = 0;
};

struct Compare {
    bool operator()(const pair<int, pair<int, pair<int, string>>>& a, const pair<int, pair<int, pair<int, string>>>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        if (a.second.first != b.second.first) {
            return a.second.first < b.second.first;
        }
        if (a.second.second.first != b.second.second.first) {
            return a.second.second.first < b.second.second.first;
        }
        return a.second.second.second > b.second.second.second;
    }
};

int main() {
    string prova, p;
    map<string, pais> medalhas;

    priority_queue<pair<int, pair<int, pair<int, string>>>, vector<pair<int, pair<int, pair<int, string>>>>, Compare> aux;

    while (getline(cin, prova) && !prova.empty()) {
        getline(cin, p);
        medalhas[p].ouro++;
        getline(cin, p);
        medalhas[p].prata++;
        getline(cin, p);
        medalhas[p].bronze++;
    }

    for (auto x : medalhas)
        aux.push({x.second.ouro, {x.second.prata, {x.second.bronze, x.first}}});

    cout << "Quadro de Medalhas" << endl;
    while (!aux.empty()) {
        cout << aux.top().second.second.second << " " << aux.top().first << " " << aux.top().second.first << " " << aux.top().second.second.first << endl;
        aux.pop();
    }

    return 0;
}
