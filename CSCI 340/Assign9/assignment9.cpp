#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include "assignment9.h"
using namespace std;

//Used globally in traverse() function and depth_first() functoin.
vector<int> num_traversal;
vector<pair<int, int> > visit_order;
int increment_order = 0;
vector<int>::iterator it;
list<int>::iterator adj_it;
list<int> temp_list;

//This is the portion that makes the graph of the arary
graph::graph(const char* input)
{
	int temp = 0;
	ifstream infile(input, ios::in);
	char line;
	infile >> line;
	int graph_verticies = line - '0';
	size = graph_verticies;
	for (int i = 0; i < graph_verticies; i++) {

		infile >> line;
		labels.push_back(line);
	}

	for (int k = 0; k < graph_verticies; k++)
	{
		infile >> line;
		for (int j = 0; j < graph_verticies; j++)
		{
			infile >> temp;
			temp_list.push_back(temp);
		}
		adj_list.push_back(temp_list);
		temp_list.erase(temp_list.begin(), temp_list.end());
	}
	infile.close();
}

graph::~graph()
{
}

//This checks the depth of the array and the vertices along witht hat
void graph::depth_first(int v) const
{
	int dist = 0;
	increment_order++;
	num_traversal[v] = increment_order;
	temp_list = adj_list[v];
	for (adj_it = temp_list.begin(); adj_it != temp_list.end(); adj_it++)
	{
		temp_list = adj_list[v];
		dist = distance(temp_list.begin(), adj_it);
		if (*adj_it == 1 && num_traversal[dist] == 0)
		{
			visit_order.push_back(make_pair(v, dist));
			depth_first(dist);
		}
	}
}

//This traverses the graph and all of the vertices
void graph::traverse() const
{
	num_traversal.resize(size);
	it = find(num_traversal.begin(), num_traversal.end(), 0);
	while (it != num_traversal.end())
	{
		depth_first(it - num_traversal.begin());
		it = find(num_traversal.begin(), num_traversal.end(), 0);
	}
	cout << "------- traverse of graph ------" << endl;
	for (int i = 1; i <= size; i++)
	{
		//it = find(num_traversal.begin(), num_traversal.end(), i);
		cout << labels[it - num_traversal.begin()] << " ";
	}
	cout << endl;
	for (unsigned int j = 0; j < visit_order.size(); j++)
	{
		cout << "(" << labels[visit_order[j].first] << ", " << labels[visit_order[j].second] << ") ";
	}
	cout << endl;
	cout << "--------- end of traverse -------" << endl << endl;
}

//This prints out the following parts taht are needed to be displayed
void graph::print() const
{
	int label_counter = 0;
	int edge_counter = 0;
	cout << endl << "Number of vertices in the graph: " << size << endl << endl;
	cout << "-------- graph -------" << endl;
	for (std::vector<std::list<int> >::const_iterator it = adj_list.begin(); it != adj_list.end(); it++)
	{
		cout << labels[label_counter] << ": ";
		std::list<int> li = *it;
		for (std::list<int>::iterator iter = li.begin(); iter != li.end(); iter++)
		{
			if (*iter == 1)
			{
				cout << labels[edge_counter] << ", ";
			}
			edge_counter++;
		}
		cout << endl;
		label_counter++;
		edge_counter = 0;
	}

	cout << "------- end of graph ------" << endl << endl;
}

#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "args: input-file-name\n";
		return 1;
	}

	graph g(argv[1]);

	g.print();

	g.traverse();

	return 0;
}

#endif
