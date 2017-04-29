#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <string.h>
#include <vector>
#include <sstream>


using namespace std;

void printMatrix(vector<vector<int>> &matrix) {
	// output vector based on vertical and horizontal sizes
	for (unsigned int y = 0; y < matrix.size(); y++) {
		//cout << y << ":";
		printf("%i:",y);
		for (unsigned int x = 0; x < matrix[y].size(); x++) {
			//cout << " " << matrix[y][x];
			printf(" %i",matrix[y][x]);
		}
		//cout << '\n';
		printf("\n");
	}
}
template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

vector<int> return_element_arraypos_stack_pos(int a, vector<vector<int>> &m) {

	vector<int> v;
	auto elementindex = -1;
	unsigned int arrayindex = -1;
	for (unsigned int i = 0; i < m.size(); i++) {
		auto it = std::find(m[i].begin(), m[i].end(), a);
		if (it == m[i].end()) {
			continue;
		} else {
			elementindex = std::distance(m[i].begin(), it);
			arrayindex = i;
			v.push_back(arrayindex);
			v.push_back(elementindex);
			break;
		}
	}

	return v;
}

void move_a_onto_b(int a, int b, vector<vector<int>> &m) {

//	where a and b are block numbers, puts block
//	a onto block b after returning any blocks that are
//	stacked on top of blocks a and b to their initial positions

	// find where is block a and block b
	vector<int> tmpa, tmpb;
	tmpa = return_element_arraypos_stack_pos(a, m);
	tmpb = return_element_arraypos_stack_pos(b, m);

	int arrayindexa = tmpa[0];
	int arrayindexb = tmpb[0];
	int element_index_a = tmpa[1];
	int element_index_b = tmpb[1];

	if (arrayindexa != arrayindexb) {
		if (m[arrayindexa].size() > 1) {
			std::vector<int>::iterator it = m[arrayindexa].begin()
					+ element_index_a + 1;
			while (it != m[arrayindexa].end()) {
				m[*it].push_back(*it);
				it = m[arrayindexa].erase(it);
			}
		}
		if (m[arrayindexb].size() > 1) {
			std::vector<int>::iterator it = m[arrayindexb].begin()
					+ element_index_b + 1;
			while (it != m[arrayindexb].end()) {
				m[*it].push_back(*it);
				it = m[arrayindexb].erase(it);
			}
		}

		m[arrayindexb].push_back(m[arrayindexa].back());
		m[arrayindexa].pop_back();
	}

}

void move_a_over_b(int a, int b, vector<vector<int>> &m) {
//	where a and b are block numbers, puts block
//	a onto the top of the stack containing block b, after
//	returning any blocks that are stacked on top of block
//	a to their initial positions.

// find where is block a and block b
	vector<int> tmpa, tmpb;
	tmpa = return_element_arraypos_stack_pos(a, m);
	tmpb = return_element_arraypos_stack_pos(b, m);


	int arrayindexa = tmpa[0];
	int arrayindexb = tmpb[0];
	int element_index_a = tmpa[1];

	if (arrayindexa != arrayindexb) {

		if (m[arrayindexa].size() > 1) {
			std::vector<int>::iterator it = m[arrayindexa].begin()
					+ element_index_a + 1;
			while (it != m[arrayindexa].end()) {
				m[*it].push_back(*it);
				it = m[arrayindexa].erase(it);
			}
		}

		if (arrayindexa != arrayindexb) {
			m[arrayindexb].push_back(m[arrayindexa].back());
			m[arrayindexa].pop_back();
		}
	}

}

void pile_a_onto_b(int a, int b, vector<vector<int>> &m) {
	/* where a and b are block numbers, moves the pile of blocks consisting of block a, and any blocks
	 that are stacked above block a, onto block b. All blocks on top of block b are moved to their
	 initial positions prior to the pile taking place. The blocks stacked above block a retain their order
	 when moved */

	// find where is block a and block b
	vector<int> tmpa, tmpb;
	tmpa = return_element_arraypos_stack_pos(a, m);
	tmpb = return_element_arraypos_stack_pos(b, m);

	int arrayindexa = tmpa[0];
	int arrayindexb = tmpb[0];
	int element_index_a = tmpa[1];
	int element_index_b = tmpb[1];

	if (m[arrayindexb].size() > 1) {
		std::vector<int>::iterator it = m[arrayindexb].begin() + element_index_b
				+ 1;
		while (it != m[arrayindexb].end()) {
			m[*it].push_back(*it);
			it = m[arrayindexb].erase(it);
		}
	}

	if (arrayindexa != arrayindexb) {
		std::vector<int>::iterator it = m[arrayindexa].begin()
				+ element_index_a;
		while (it != m[arrayindexa].end()) {
			m[arrayindexb].push_back(*it);
			it = m[arrayindexa].erase(it);
		}
	}

}

void pile_a_over_b(int a, int b, vector<vector<int>> &m) {
//	where a and b are block numbers, puts the pile of blocks consisting of block a, and any blocks
//	that are stacked above block a, onto the top of the stack containing block b. The blocks stacked
//	above block a retain their original order when moved.

	vector<int> tmpa, tmpb;
	tmpa = return_element_arraypos_stack_pos(a, m);
	tmpb = return_element_arraypos_stack_pos(b, m);


	int arrayindexa = tmpa[0];
	int arrayindexb = tmpb[0];
	int element_index_a = tmpa[1];
	int element_index_b = tmpb[1];

	if (arrayindexa != arrayindexb) {
		std::vector<int>::iterator it = m[arrayindexa].begin()
				+ element_index_a;
		while (it != m[arrayindexa].end()) {
			m[arrayindexb].push_back(*it);
			it = m[arrayindexa].erase(it);
		}
	}

}

int main() {

	int a, b;
	int NumberOfBlocks;
	vector<string> Commandarray;
	vector<vector<int> > Matrix; // declare 2D vector
	cin >> NumberOfBlocks;

	for (int y = 0; y < NumberOfBlocks; y++) {
		vector<int> row; // creates empty row
		//inner loop populates row
		row.push_back(y);
		Matrix.push_back(row); // add row to vector Matrix
	}

	string Command;

	while (getline(cin, Command)) {
		if (Command.compare("quit") == 0) {
			break;
		}
		Commandarray = split(Command, ' ');
		if ((Command.find("move") != std::string::npos)
				&& (Command.find("onto") != std::string::npos)) {
			a = atoi(Commandarray[1].c_str());
			b = atoi(Commandarray[3].c_str());
			//move_a_onto_b(block[a], block[b]);
			move_a_onto_b(a, b, Matrix);

		} else if ((Command.find("move") != std::string::npos)
				&& (Command.find("over") != std::string::npos)) {
			a = atoi(Commandarray[1].c_str());
			b = atoi(Commandarray[3].c_str());
			move_a_over_b(a, b, Matrix);
		} else if ((Command.find("pile") != std::string::npos)
				&& (Command.find("onto") != std::string::npos)) {
			a = atoi(Commandarray[1].c_str());
			b = atoi(Commandarray[3].c_str());
			pile_a_onto_b(a, b, Matrix);
		} else if ((Command.find("pile") != std::string::npos)
				&& (Command.find("over") != std::string::npos)) {
			a = atoi(Commandarray[1].c_str());
			b = atoi(Commandarray[3].c_str());
			pile_a_over_b(a, b, Matrix);
		}
		Commandarray.clear();
	}

	printMatrix(Matrix);
	return 0;
}

