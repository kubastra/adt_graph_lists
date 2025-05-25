#include <chrono>
#include "graph.h"
#include <fstream>

#define REPEATS 10
#define MAX_ITER 10000
std::ofstream file("time.dat");

void test() {
    FlexibleGraph graph;
    graph.addVertex(5);
    graph.addVertex(7);
    graph.addVertex(19);

    graph.print();
    std::cout << "Po usunieciu 7: " << std::endl;
    graph.removeVertex(7);
    graph.print();

    std::cout << "Dodanie krawedzi 5, 19" << std::endl;
    graph.addEdge(5, 19);
    graph.print();

    std::cout << "Sprawdzenie czy maja krawedz: " << std::endl;
    std::cout << graph.adjacent(5, 19) << std::endl;

    std::cout << "Usuniecie krawedzi 5, 19: " << std::endl;
    graph.removeEdge(5, 19);
    graph.print();
}

void time_measure() {
    //rozmiar problemu: rosnaca ilosc sasiadow wraz z rosnaca iloscia wierzcholkow
    FlexibleGraph graph;
    graph.addVertex(0);
    for (int i = 1; i < MAX_ITER; i++) {
        graph.addVertex(i);
        auto dur = 0;
        for (int j = 0; j < REPEATS; j++) {
            auto start = std::chrono::high_resolution_clock::now();
            graph.addEdge(0, i);
            auto end = std::chrono::high_resolution_clock::now();
            dur += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            graph.removeEdge(0, 1);
        }
        graph.addEdge(0, i);

        dur = dur / REPEATS;

        file << i - 1 << " " << dur << "\n";
    }
}
int main(){

    if (!file.is_open()) {
        return -1;
    }

    //test();

    time_measure();
    file.close();

    return 0;
}


// #include <chrono>
// #include "graph.h"
// #include <fstream>
//
// #define REPEATS 10
// #define MAX_ITER 10000
// std::ofstream file("time.dat");
//
// void test() {
//     AdjacencyGraph graph;
//     graph.addVertex(5);
//     graph.addVertex(7);
//     graph.addVertex(19);
//
//     graph.print();
//
//     graph.removeVertex(7);
//     graph.print();
// }
//
// void time_measure() {
//     AdjacencyGraph graph;
//     graph.addVertex(0);
//
//     for (int i = 1; i < MAX_ITER; i++) {
//         auto dur = 0;
//         graph.addVertex(i);
//         for (int j = 0; j < REPEATS; j++) {
//             auto start = std::chrono::high_resolution_clock::now();
//             graph.addEdge(0, i );
//             auto end = std::chrono::high_resolution_clock::now();
//             dur += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
//             graph.removeEdge(0, i);
//         }
//         graph.addEdge(0, i);
//         dur = dur / REPEATS;
//
//         file << i - 1 << " " << dur << "\n";
//     }
// }
// int main(){
//
//     if (!file.is_open()) {
//         return -1;
//     }
//
//     time_measure();
//
//     file.close();
//
//     return 0;
// }