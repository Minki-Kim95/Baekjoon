#include <iostream>
#include <set>

using namespace std;
set<int> node, indegree;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase = 1;
	
	while (true) {

		bool is_tree = true;
		int p_node, c_node;

		int num_edge = 0;
		//int num_node = 0;

		node.clear();
		indegree.clear();

		while ((cin >> p_node >> c_node), (p_node || c_node)) {
			if (p_node == -1 && c_node == -1) {
				return 0;
			}
			num_edge++;

			if (node.find(p_node) == node.end()) {
				node.insert(p_node);
			}

			if (node.find(c_node) == node.end()) {
				node.insert(c_node);
			}

			if (indegree.find(c_node) == indegree.end()) {
				indegree.insert(c_node);
			}
			else {
				is_tree = false;
			}

		}
		if (num_edge > 0 && node.size() != num_edge + 1) {
			is_tree = false;
		}

		if (is_tree) {
			cout << "Case " << testCase << " is a tree.\n";
		}
		else {
			cout << "Case " << testCase << " is not a tree.\n";
		}
		testCase++;



	}
	




}