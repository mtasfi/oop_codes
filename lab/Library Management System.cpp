//Copyright MT ASFI (CSE12)

#include<iostream>
#include <iomanip>
using namespace std;

class book {
	string title;
	string author;
	int edition, copies, stock;
public:
	void book_data(string t, string a, int e, int c, int s) {
		title = t;
		author = a;
		edition = e;
		copies = c;
		stock = s;
	}
	void sell(int q) {
		if (q <= stock) {
			stock -= q;
			cout << q << " pieces of " << title << " has been Sold!" << endl;
		}
		else cout << "Dont have enough stock!" << endl;
	}
	void add(int q) {
		stock += q;
		cout << q << " pieces of " << title << " has been addded to the stock!" << endl;
	}
	void display() {
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Edition: " << edition << endl;
		cout << "Copies: " << copies << endl;
		cout << "Stock: " << stock << endl;
	}
	int match(string s) {
		if (s == title)return 1;
		else return 0;
	}
};


int searchBook(book obj[], int n, string s) {
	for (int i = 0; i < n; i++) {
		if (obj[i].match(s))return i;
	}
	return -1;
}

void options() {
	cout << setw(20) << left << " ";
	cout  << "ASFI Library Management System" << endl << endl;
	cout << setw(25) << left << " ";
	cout << "1. Add Book" << endl;
	cout << setw(25) << left << " ";
	cout << "2. Sell Book" << endl;
	cout << setw(25) << left << " ";
	cout << "3. Search Book" << endl;
	cout << setw(25) << left << " ";
	cout << "4. Display" << endl;
	cout << setw(25) << left << " ";
	cout << "5. Exit" << endl << endl << endl;
}

int main() {
	book obj[100];
	int idx = 0;


	options();


	while (1) {
		int x; cin >> x;

		system("cls");
		options();

		if (x == 1) {
			string t, a;
			int e, c, s;
			cout << "Enter book title" << endl;
			//cin >> t;
			cin.ignore(); getline(cin, t);

			int found = -1;
			found = searchBook(obj, idx, t);

			if (found == -1) {
				cout << "Enter book Author" << endl;
				//cin >> a;
				getline(cin, a);
				cout << "Enter book Edition" << endl;
				cin >> e;
				cout << "Enter book copies" << endl;
				cin >> c;
				cout << "Enter book stock" << endl;
				cin >> s;
				obj[idx].book_data(t, a, e, c, s);
				idx++;
			}

			else {
				cout << "This Book already exist!" << endl;
				cout << "Enter the quantity to add in the stock" << endl;
				int q;
				cin >> q;
				obj[found].add(q);
			}
		}
		else if (x == 2) {
			cout << "Enter the book title" << endl;
			string s;
			//cin >> s;
			cin.ignore(); getline(cin, s);
			int found = -1;
			found = searchBook(obj, idx, s);

			if (found != -1) {
				cout << "Enter the quantity" << endl;
				int q;
				cin >> q;
				obj[found].sell(q);
			}
			else cout << "Invalid book title!" << endl;
		}
		else if (x == 3) {
			cout << "Enter the book title" << endl;
			string s;
			//cin >> s;
			cin.ignore(); getline(cin, s);
			int found = searchBook(obj, idx, s);
			if (found != -1)obj[found].display();
			else cout << "Not Found!" << endl;
		}
		else if (x == 4) {
			for (int i = 0; i < idx; i++) {
				cout << "Book " << i + 1 << " :" << endl;
				obj[i].display();
				cout << endl << endl;
			}
		}
		else if (x == 5)break;
		else cout << "Invalid! PRESS 1-5" << endl;
	}
}
