# include <iostream>

using namespace std;

int N, K;

int chess_inf[14][14];

int mal_inf[10][3];

int turns = 0;

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = { 0, 1, -1, 0, 0 };


struct Node{
	bool is_end = true;
	int malIndex = -1;
	Node* nextmal = NULL;
	Node* beforemal = NULL;
};

Node chess[145];

Node mals[10];



int check_size(int x, int y) {
	int size = 0;
	Node* curboard = &chess[N *(x - 1) + y];

	while (curboard->is_end == false) {
		curboard = curboard->nextmal;
		size++;
	}

	return size;
}
Node* returnEndnode(int x, int y) {
	Node * curNode;

	curNode = &chess[N *(x - 1) + y];
	while (curNode->is_end == false) {
		curNode = curNode->nextmal;
	}

	return curNode;

}

void Connect(Node* curNode, Node* endNode) {

	endNode->is_end = false;
	endNode->nextmal = curNode;
	if (curNode->beforemal != NULL) {
		curNode->beforemal->is_end = true;
		curNode->beforemal->nextmal = NULL;
	}
	curNode->beforemal = endNode;
}

Node* redCase(Node* curNode) {
	Node* tempNode;
	if (curNode->is_end == false) {
		curNode->is_end = true;
		curNode->beforemal->is_end = true;
		curNode->beforemal->nextmal = NULL;
		curNode->beforemal = curNode->nextmal;
		curNode->nextmal = NULL;
		curNode = curNode->beforemal;
		while (true) {
			tempNode = curNode->beforemal;
			curNode->beforemal = curNode->nextmal;
			curNode->nextmal = tempNode;
			if (curNode->is_end == true) {
				curNode->is_end = false;
				break;
			}
			curNode = curNode->beforemal;
		}
	}
	return curNode;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> chess_inf[i][j];
		}
	}
	for (int i = 0; i <= N; i++) {
		chess_inf[0][i] = 2;
		chess_inf[i][N + 1] = 2;
		chess_inf[i + 1][0] = 2;
		chess_inf[N + 1][i + 1] = 2;
	}


	for (int i = 0; i < K; i++) {
		cin >> mal_inf[i][0] >> mal_inf[i][1] >> mal_inf[i][2];

		chess[N * (mal_inf[i][0] - 1) + mal_inf[i][1]].is_end = false;
		chess[N * (mal_inf[i][0] - 1) + mal_inf[i][1]].nextmal = &mals[i];
		mals[i].beforemal = &chess[N * (mal_inf[i][0] - 1) + mal_inf[i][1]];
		mals[i].malIndex = i;

	}


	int next_x;
	int next_y;
	bool is_gameover = false;
	Node* curNode;
	Node* endNode;
	Node* tempNode;
	while (turns <= 1000) {
		turns++;

		for (int mal_index = 0; mal_index < K; mal_index++) {
			next_x = mal_inf[mal_index][0] + dx[mal_inf[mal_index][2]];
			next_y = mal_inf[mal_index][1] + dy[mal_inf[mal_index][2]];
			curNode = &mals[mal_index];
			// white
			if (chess_inf[next_x][next_y] == 0) {

				endNode = returnEndnode(next_x, next_y);

				Connect(curNode, endNode);

			}
			// red
			else if (chess_inf[next_x][next_y] == 1) {
				curNode = redCase(curNode);

				endNode = returnEndnode(next_x, next_y);

				Connect(curNode, endNode);

			}
			//blue
			else {

				if (mal_inf[mal_index][2] == 1) {
					mal_inf[mal_index][2] = 2;
				}
				else if (mal_inf[mal_index][2] == 2) {
					mal_inf[mal_index][2] = 1;
				}
				else if (mal_inf[mal_index][2] == 3) {
					mal_inf[mal_index][2] = 4;
				}
				else {
					mal_inf[mal_index][2] = 3;
				}
				next_x = mal_inf[mal_index][0] + dx[mal_inf[mal_index][2]];
				next_y = mal_inf[mal_index][1] + dy[mal_inf[mal_index][2]];

				
				if(chess_inf[next_x][next_y] == 0){
					endNode = returnEndnode(next_x, next_y);

					Connect(curNode, endNode);
				}
				else if(chess_inf[next_x][next_y] == 1){
					curNode = redCase(curNode);

					endNode = returnEndnode(next_x, next_y);

					Connect(curNode, endNode);
				}
				else {
					next_x = mal_inf[mal_index][0];
					next_y = mal_inf[mal_index][1];
				}

				
			}
			while (true) {
				mal_inf[curNode->malIndex][0] = next_x;
				mal_inf[curNode->malIndex][1] = next_y;
				if (curNode->is_end == true) {
					break;
				}
				curNode = curNode->nextmal;
			}

			if (check_size(next_x, next_y) >= 4) {
				is_gameover = true;
				break;
			}
		}
		if (is_gameover) {
			break;
		}
	}


	if (turns > 1000) {
		cout << -1;
	}
	else {
		cout << turns;
	}



}