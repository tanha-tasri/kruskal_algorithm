Kruskal's Algorithm for Minimum Spanning Tree (MST)
This C++ program implements Kruskal's Algorithm using a priority queue (min-heap) and Disjoint Set Union (DSU) to find the Minimum Spanning Tree (MST) of an undirected, weighted graph.

🔧 Features
Reads number of nodes and edges.
Accepts weighted, undirected edges.
Uses priority queue to sort edges by weight.
Utilizes DSU (with path compression) to avoid cycles.
Outputs the total cost of the MST.
Lists all the edges included in the MST.
🧠 Algorithm Overview
Kruskal's algorithm works as follows:

Sort all edges by increasing weight (min-heap).
Initialize each node to be its own parent (DSU).
For each edge:
Check if the two vertices belong to different components.
If yes:
Add the edge to the MST.
Merge the two components using union-find.
Stop when MST contains n - 1 edges.
📥 Input Format
n m
u1 v1 w1
u2 v2 w2
...
um vm wm

n = number of nodes
m = number of edges
Each of the next m lines contains: u, v, and w representing an edge between nodes u and v with weight w.
📤 Output Format
Total cost of MST: X
Edges in MST:
a1 - b1
a2 - b2
...

Where X is the total weight of the MST, and each ai - bi is an edge in the MST.

🧪 Sample Input
5 6
1 2 2
1 3 3
2 4 5
3 4 7
2 5 8
4 5 6

✅ Sample Output
Total cost of MST: 16
Edges in MST:
1 - 2
1 - 3
2 - 4
4 - 5

🚀 How to Run
Compile the code:
g++ -std=c++11 -o kruskal mst_kruskal.cpp

📚 Code Structure
data class: Holds edge info (u, v, cost) and defines < operator for min-heap.

priority_queue: Stores edges sorted by weight.

vector parent: DSU structure with path compression.

findParent(): Finds the root of a node.

unionSet(): Merges two disjoint sets.

mst_cost: Accumulates the total cost of the MST.

mst_edges: Stores all selected MST edges.

📌 Notes
The graph must be connected to form a valid MST.

If not connected, the algorithm will not include all nodes.

No external libraries used except standard headers.

🧑‍💻 Author
Name: Tanha tasri

Date: [10 july 2025]

Algorithm: Kruskal's Algorithm with DSU

Language: C++
