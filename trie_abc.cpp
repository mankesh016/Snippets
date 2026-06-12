
// trie abcd map

struct Node {
	map<char, Node*>mp;
	bool isEnd;
	int cnt = 0;
};

class Trie {
	Node* root;
public:
	Trie() {
		root = new Node();
	}
	void insert(string &s) {
		Node* temp = root;

		for (auto c : s) {
			if (temp->mp.count(c)) temp = temp->mp[c];
			else {
				temp->mp[c] = new Node();
				temp = temp->mp[c];
			}
			temp->cnt++;
		}

		temp->isEnd = true;
	}
	bool query(string &s) {
		Node* temp = root;

		for (auto c : s) {
			if ((temp->mp).count(c)) temp = temp->mp[c];
			else return false;
		}

		cout << temp->cnt << " ";
		return (temp->isEnd == true);
	}
};
