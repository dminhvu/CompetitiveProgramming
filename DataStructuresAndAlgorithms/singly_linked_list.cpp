#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

struct node {
	int val;
	node *next;
	node(int x): val(x), next(NULL) {}
};

node *head, *tail;

void add_head(int x) {
	node *new_node = new node(x);
	new_node->next = head;
	head = new_node;
}

void add_tail(int x) {
	node *new_node = new node(x);
	tail->next = new_node;
	tail = new_node;
}

void add_at(int k, int x) {
	if (k == 0) {
		add_head(x);
		return;
	}
	node *p = head;
    for(int i = 1; i < k; i++) {
        p = p->next;
    }
    node *new_node = new node(x);
    new_node->next = p->next;
    p->next = new_node;
}

void erase_head() {
	node *tmp = head;
	tmp = head->next;
	delete(head);
	head = tmp;
}

void erase_tail() {
	node *tmp = head;
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	delete(tail);
	tail = tmp;
	tail->next = NULL;
}

void erase_at(int k) {
	if (k == 0) {
		erase_head();
		return;
	}
	node *tmp = head;
	for(int i = 1; i < k; i++) {
		tmp = tmp->next;
	}
	node *tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	delete(tmp2);
}

void show() {
	node *p = head;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int val; cin >> val;
	head = tail = new node(val);
	for(int i = 1; i < n; i++) {
		cin >> val;
		add_tail(val);
	}
    // int k, x; cin >> k >> x;
    // add_at(k, x);
	int k; cin >> k;
	erase_at(k);
    show();
	return 0;
}