// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define P 7
bool visited[P];
string parent[P];
string path[P];
string nodes[P];
int distanceFinder(int dist[], string city);
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < P; v++)
		if (visited[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void display(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < P; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[P][P], int src, string city)
{
	parent[0]="/";
	int dist[P]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	// Initialize all distances as INFINITE and visited[] as false
	for (int i = 0; i < P; i++)
		dist[i] = INT_MAX, visited[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < P - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist);

		// Mark the picked vertex as visited
		visited[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < P; v++)

			// Update dist[v] only if is not in visited, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
				parent[v]=nodes[u];
			}
	}

	// print the constructed distance array
	display(dist);
	
	cout<<distanceFinder(dist, city)<<endl;
}

void addNodeNames(){
	for(int i=0; i<P; i++){
		cout<<"Enter node "<<i<<" :";
		cin>>nodes[i];
	}
}
int findParentIndex(string s){
for(int i=0; i<P; i++)
	if(nodes[i]==s)
		return i;
}

//a method to find the distance string
string findPathTraveled(string st, string e){
	int index = findParentIndex(e);
	string s = parent[index]+""+e;
	string temp = parent[index];

	while(parent[index]!=st){
		index = findParentIndex(temp);
		s=parent[index]+""+s;
		temp=parent[index];
	}
	return s;
}
int distanceFinder(int dist[], string city){
	for(int i=0; i<P; i++){
		if(nodes[i]==city){
			return dist[i];
		}
	}
}
// driver program to test above function
int main()
{

addNodeNames();
	/* Let us create the example graph discussed above */
	int graph[P][P] = {
	{0,5,1,4,0,0,0},
	{5,0,0,8,0,6,0},
	{1,0,0,3,2,0,0},
	{4,8,3,0,0,8,0},
	{0,0,2,0,0,7,9},
	{0,6,0,8,7,0,0},
	{0,0,0,0,9,0,0}};

	dijkstra(graph, 0, "D");
	string s =findPathTraveled("A","F");
		cout<<s<<endl;

	return 0;
}

// This code is contributed by shivanisinghss2110
