#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAX_CITIES = 1000;
const int MAX_ROADS = 1000;

struct City {
    string name;
    string country;
};

struct Edge {
    int cityIndex;
    int weight;
};

City cities[MAX_CITIES];
Edge graph[MAX_CITIES][MAX_CITIES];
int cityCount = 0;

void addCity(const City& city) {
    cities[cityCount++] = city;
}

void addRoad(int cityIndex1, int cityIndex2) {
    graph[cityIndex1][cityIndex2] = { cityIndex2, 100 };
    graph[cityIndex2][cityIndex1] = { cityIndex1, 100 };
}

void findShortestPath(int startCityIndex, const string& cityName) {
    int n = cityCount;
    int distances[MAX_CITIES];
    int parents[MAX_CITIES];

    bool visited[MAX_CITIES];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        distances[i] = INT_MAX;
        parents[i] = -1;
    }

    distances[startCityIndex] = 0;

    for (int i = 0; i < n - 1; i++) {
        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) {
            break;
        }

        visited[minIndex] = true;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[minIndex][j].cityIndex != -1) {
                int newDistance = distances[minIndex] + graph[minIndex][j].weight;
                if (newDistance < distances[j]) {
                    distances[j] = newDistance;
                    parents[j] = minIndex;
                }
            }
        }
    }

    int cityIndex = -1;
    for (int i = 0; i < cityCount; i++) {
        if (cities[i].name == cityName) {
            cityIndex = i;
            break;
        }
    }

    if (cityIndex == -1) {
        cout << "City not found" << endl;
        return;
    }

    int capitalCityIndex = -1;
    for (int i = 0; i < cityCount; i++) {
        if (isupper(cities[i].name[0])) {
            capitalCityIndex = i;
            break;
        }
    }

    cout << cities[cityIndex].country << endl;

    int currentCityIndex = cityIndex;
    while (currentCityIndex != capitalCityIndex) {
        cout << cities[currentCityIndex].name << " -> ";
        currentCityIndex = parents[currentCityIndex];
    }
    cout << cities[currentCityIndex].name << endl;

    cout << distances[cityIndex] << " km" << endl;
}

int main() {
    int e;
    cin >> e;

    memset(graph, -1, sizeof(graph));

    for (int i = 0; i < e; i++) {
        string X, Y, Z;
        cin >> X >> Y >> Z;

        City city1 = { X, Z };
        City city2 = { Y, Z };

        int cityIndex1 = -1, cityIndex2 = -1;

        for (int j = 0; j < cityCount; j++) {
            if (cities[j].name == city1.name) {
                cityIndex1 = j;
                break;
            }
        }
        if (cityIndex1 == -1) {
            addCity(city1);
            cityIndex1 = cityCount - 1;
        }

        for (int j = 0; j < cityCount; j++) {
            if (cities[j].name == city2.name) {
                cityIndex2 = j;
                break;
            }
        }
        if (cityIndex2 == -1) {
            addCity(city2);
            cityIndex2 = cityCount - 1;
        }

        graph[cityIndex1][cityIndex2] = { cityIndex2, 100 };
        graph[cityIndex2][cityIndex1] = { cityIndex1, 100 };
    }

    string cityName;
    cin >> cityName;

    int capitalCityIndex = -1;
    for (int i = 0; i < cityCount; i++) {
        if (isupper(cities[i].name[0])) {
            capitalCityIndex = i;
            break;
        }
    }

    findShortestPath(capitalCityIndex, cityName);

    return 0;
}

