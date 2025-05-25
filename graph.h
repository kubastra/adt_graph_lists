#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class FlexibleGraph {
private:
    std::unordered_map<int, std::vector<int>> adjList;

public:
    void addVertex(int v) {
        if (adjList.find(v) == adjList.end()) {
            adjList[v] = std::vector<int>();
        }
    }

    void removeVertex(int v) {
        if (adjList.find(v) == adjList.end()) return;

        for (auto& [key, neighbors] : adjList) {
            neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), v), neighbors.end());
        }

        adjList.erase(v);
    }

    void addEdge(int u, int v) {
        addVertex(u);
        addVertex(v);

        if (!adjacent(u, v)) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void removeEdge(int u, int v) {
        if (!adjacent(u, v)) return;

        auto& neighborsU = adjList[u];
        auto& neighborsV = adjList[v];

        neighborsU.erase(std::remove(neighborsU.begin(), neighborsU.end(), v), neighborsU.end());
        neighborsV.erase(std::remove(neighborsV.begin(), neighborsV.end(), u), neighborsV.end());
    }

    bool adjacent(int u, int v) {
        if (adjList.find(u) == adjList.end()) return false;

        for (int neighbor : adjList[u]) {
            if (neighbor == v) return true;
        }
        return false;
    }

    std::vector<int> neighbours(int v) {
        if (adjList.find(v) == adjList.end()) return {};
        return adjList[v];
    }

    int getEdgeValue(int u, int v) {
        return adjacent(u, v) ? 1 : 0;
    }

    void setEdgeValue(int u, int v) {
        addEdge(u, v);
    }

    void print() {
        for (const auto& [vertex, neighbors] : adjList) {
            std::cout << vertex << ": ";
            for (int neighbor : neighbors) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif

// #ifndef GRAPH_H
// #define GRAPH_H
//
// #include <vector>
// #include <iostream>
//
// class AdjacencyGraph {
// private:
//     std::vector<std::vector<int>> adjaMatrix;
//     std::vector<int> vertexValues;
//
// public:
//
//     void addVertex(int vertex){
//         int newSize = adjaMatrix.size() + 1;
//         adjaMatrix.push_back(std::vector<int>(newSize));
//
//         for (int i = 0; i < newSize - 1; i++) {
//             adjaMatrix[i].push_back(0);
//         }
//
//         vertexValues.push_back(vertex);
//     }
//
//     void removeVertex(int vertex) {
//         int index = getIndex(vertex);
//
//         if (index == -1) return;
//
//         adjaMatrix.erase(adjaMatrix.begin() + index);
//
//         for (auto &row : adjaMatrix) {
//             row.erase(row.begin() + index);
//         }
//
//         vertexValues.erase(vertexValues.begin() + index);
//
//     }
//
//     bool adjacent(int x, int y) { return adjaMatrix[x][y] != 0; }
//
//     std::vector<int> neighbours(int vertex) {
//         std::vector<int> neighbours;
//         int index = getIndex(vertex);
//
//         for (int i = 0; i < adjaMatrix.size(); i++) {
//             if (adjaMatrix[i][index] == 1) {
//                 neighbours.push_back(vertexValues[i]);
//             }
//         }
//         return neighbours;
//     }
//     int getIndex(int vertex) {
//         int index = -1;
//         for (int i = 0; i < vertexValues.size(); i++) {
//             if (vertexValues[i] == vertex) {
//                 index = i;
//                 return index;
//             }
//         }
//     }
//     void addEdge(int x, int y) {
//         int index_x = getIndex(x);
//         int index_y = getIndex(y);
//
//         adjaMatrix[index_x][index_y] = 1;
//         adjaMatrix[index_y][index_x] = 1;
//     }
//
//     void removeEdge(int x, int y) {
//         int index_x = getIndex(x);
//         int index_y = getIndex(y);
//
//         adjaMatrix[index_x][index_y] = 0;
//         adjaMatrix[index_y][index_x] = 0;
//     }
//
//     int getEdgeValue(int x, int y) {
//         int index_x = getIndex(x);
//         int index_y = getIndex(y);
//
//         return adjaMatrix[index_x][index_y];
//     }
//
//     void setEdgeValue(int x, int y) {
//         int index_x = getIndex(x);
//         int index_y = getIndex(y);
//         adjaMatrix[index_x][index_y] = 1;
//         adjaMatrix[index_y][index_x] = 1;
//     }
//
//     void print() {
//
//         std::cout << "    ";
//         for (int val : vertexValues) {
//             std::cout << val << " ";
//         }
//         std::cout << std::endl;
//
//         for (size_t i = 0; i < adjaMatrix.size(); ++i) {
//             std::cout << vertexValues[i] << " ";
//             if (vertexValues[i] < 10) std::cout << " ";
//
//             for (size_t j = 0; j < adjaMatrix[i].size(); ++j) {
//                 std::cout << " " << adjaMatrix[i][j];
//             }
//             std::cout << std::endl;
//         }
//     }
//
// };
//
// #endif