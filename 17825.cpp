#include <iostream>

using namespace std;

struct Node {
	bool change = false;
	int value;
	int index;
	Node* next_node;
	Node* change_node = NULL;
};

Node yuk[33];
// 20 3 2 3 3

int mal[4] = { 0, 0, 0, 0 };

int dice[10];

int ans = 0;

//말 이동 함수 구현
int move(int start, int num) {

	Node * present_node;
	if (start == 32) {
		return 32;
	}

	if (yuk[start].change) {
		present_node = yuk[start].change_node;
		num--;
	}
	else {
		present_node = yuk[start].next_node;
		num--;
	}

	for (int i = 0; i < num; i++) {
		if (present_node->index == 32) {
			break;
		}
		present_node = present_node->next_node;
		
	}
	
	return present_node->index;

}

bool check_endnode(int value) {
	if (value == 32) {
		return false;
	}
	for (int i = 0; i < 4; i++) {
		if (mal[i] == value)
			return true;
	}
	return false;
	
}

// dfs로 말 선택 함수 구현
void dfs(int deep, int point) {
	int end_node, mal_temp;
	

	if (deep == 10) {
		if (point > ans) {
			ans = point;
		}
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			end_node = move(mal[i], dice[deep]);

			if (check_endnode(end_node)) {
				continue;
			}

			mal_temp = mal[i];

			mal[i] = end_node;
			point += yuk[end_node].value;
			dfs(deep + 1, point);
			mal[i] = mal_temp;
			point -= yuk[end_node].value;
		}
	}


}


//int strait_way[21];
//int ten_way[5];
//int twenty_way[4];
//int thirty_way[5];
//int twenty5_way[4];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// strait_way
	for (int i = 0; i < 20; i++) {
		yuk[i].value = 2 * i;
		yuk[i].next_node = &yuk[i + 1];
		yuk[i].index = i;
	}
	
	yuk[20].value = 40;
	yuk[20].index = 20;

	// center node
	yuk[21].value = 25;
	yuk[21].index = 21;
	yuk[21].next_node = &yuk[30];

	//cout << yuk[3].next_node->value;

	// ten_way 22 ~ 24
	yuk[5].change = true;
	yuk[5].change_node = &yuk[22];

	yuk[22].value = 13;
	yuk[22].index = 22;
	yuk[22].next_node = &yuk[23];
	yuk[23].value = 16;
	yuk[23].index = 23;
	yuk[23].next_node = &yuk[24];
	yuk[24].value = 19;
	yuk[24].index = 24;
	yuk[24].next_node = &yuk[21];
	
	// twenty_way 25 ~ 26
	yuk[10].change = true;
	yuk[10].change_node = &yuk[25];

	yuk[25].value = 22;
	yuk[25].index = 25;
	yuk[25].next_node = &yuk[26];
	yuk[26].value = 24;
	yuk[26].index = 26;
	yuk[26].next_node = &yuk[21];


	// thirty_way 27 ~ 29
	yuk[15].change = true;
	yuk[15].change_node = &yuk[27];

	yuk[27].value = 28;
	yuk[27].index = 27;
	yuk[27].next_node = &yuk[28];
	yuk[28].value = 27;
	yuk[28].index = 28;
	yuk[28].next_node = &yuk[29];
	yuk[29].value = 26;
	yuk[29].index = 29;
	yuk[29].next_node = &yuk[21];

	// twenty5_way 30 ~ 31
	yuk[30].value = 30;
	yuk[30].index = 30;
	yuk[30].next_node = &yuk[31];
	yuk[31].value = 35;
	yuk[31].index = 31;
	yuk[31].next_node = &yuk[20];

	// end
	yuk[20].next_node = &yuk[32];
	yuk[32].value = 0;
	yuk[32].index = 32;
	yuk[32].next_node = NULL;
	
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	int end_node;

	end_node = move(mal[0], dice[0]);
	mal[0] = end_node;
	dfs(1, yuk[end_node].value);

	cout << ans;
	


}