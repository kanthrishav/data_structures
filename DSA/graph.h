#include <iostream>
#define MAX 20

typedef struct NWNode {
	int vertex;
	NWNode* next;
};

typedef struct WNode {
	int vertex;
	int weight;
	NWNode* next;
};

class NonWeightedGraph {
public:
	NWNode* adj[MAX];
	int size;
	void create(int n) {
		if (n <= MAX) {
			for (int i = 0; i < n; i++)
				adj[i] = nullptr;
			size = n;
		}
	}
	void enterGraphInfo(int* arr) {
		NWNode* ptr, * last;
		int i, j, m, val;
		for (i = 0; i < size; i++) {
			last = nullptr;
			for (j = 0; j < m; j++) {
				ptr = new NWNode;
				ptr->vertex = arr[i];

			}
		}
	}
};

class WeightedGraph {
public:
	WNode* adj[MAX];
	int size;
	void create(int n) {
		if (n <= MAX) {
			for (int i = 0; i < n; i++)
				adj[i] = nullptr;
			size = n;
		}
	}
};

class Graph {
public:

	// Insertion
	// Deletion
	// BreadthFirstSearch (BFS)
	// DepthFirstSearch (DFS)
	// Minimum Spanning Tree (MST) - Prim's Algo
	// Shortest Path Algo - Dijkstra's Algo
};