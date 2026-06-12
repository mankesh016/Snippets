// trie binary xor
struct Node {
	Node* ch[2];
};

class Trie {
	Node* root;
public:
	Trie() {
		root = new Node();
	}
	void insert(int n) {
		Node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) % 2;
			if (temp->ch[bit] == NULL) temp->ch[bit] = new Node();
			temp = temp->ch[bit];
		}
	}
	int getMaxXor(int n) {
		Node* temp = root;
		int ans = 0;
		// trie should have atleast one element before this query
		// add all array elements to trie, xor to self will be zero
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) % 2;

			if (temp->ch[!bit]) {
				ans |= (1 << i);
				temp = temp->ch[!bit];
			}
			else temp = temp->ch[bit];
		}

		return ans;
	}
	int getMinXor(int n) {
		Node* temp = root;
		int ans = 0;
		// trie should have atleast one element before this query
		// insert elements only till (i-1)th position

		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) % 2;

			if (temp->ch[bit]) temp = temp->ch[bit];
			else {
				ans |= (1 << i);
				temp = temp->ch[!bit];
			}
		}

		return ans;
	}
};
