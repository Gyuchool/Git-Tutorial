#include <iostream>
#include <string>
using namespace std;

char c[10000][11];

class Tri {
	
	Tri* node[11];
	bool finish;
	int to_int(char c) {
	
		return c - '0';
	}
public:
	
	Tri() {
		finish = false;
		for (int i = 0; i < 11; ++i) {
		
			node[i] = NULL;
			
		}
	}
	
	~Tri() {
	
		for (int i = 0; i < 11; ++i) {
		
			if (node[i] != NULL) {
			
				delete node[i];
				
			}
			
		}
	}
	
	void insert(const char* words) {
	
		if (*words == '\0')
			finish = true;
			
		else {
			int next = to_int(*words);
			
			if (node[next] == NULL) {//새로운 가지
				node[next] = new Tri();
			}
			node[next]->insert(words + 1);
			
		}
	}
	
	bool find(const char* words) {
	
		int next = to_int(*words);
		
		if (*words == '\0')
			return false;
			
		if (finish)
			return true;

		return node[next]->find(words + 1);
	}
};

int main() {
	
	int t, n;
	int no;
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		Tri* tri=new Tri;
		cin >> n;
		
		for (int j = 0; j < n; ++j) {
			cin >> c[j];
			
			tri->insert(c[j]);
		}
		
		no = 0;
		for (int j = 0; j < n; ++j) {
			
			if (tri->find(c[j])) {
				no = 1;
			}
		}
		
		if (no) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
	
	return 0;
}

