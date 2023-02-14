#include<bits/stdc++.h>
using namespace std;

class product {
	int code;
	string name;
	int price;
	int stock;
public:
	product() {}
	void set(int c, string n, int p, int s) {
		code = c;
		name = n;
		price = p;
		stock = s;
	}
	int getStock() {
		return stock;
	}
	friend class bill;
	friend void showProducts(product[], int);
	friend int search(product[], int, string);
};

class bill {
	product item[100];
	int quantity[100];
	int totalItem = 0;
	int grandTotal = 0;
public:

	void add(product &obj, int q) {
		int idx = search(obj.code);

		if (idx == -1) {
			item[totalItem] = obj;
			quantity[totalItem] = q;
			totalItem++;
		}

		else quantity[idx] += q;

		obj.stock -= q;
	}
	int search(int c) {
		for (int i = 0; i < totalItem; ++i)
		{
			if (item[i].code == c)return i;
		}
		return -1;
	}
	void show() {

		cout << "You have purchased " << totalItem << " items" << endl << endl << endl;
		grandTotal = 0;

		for (int i = 0; i < totalItem; ++i)
		{
			cout << "Item " << i + 1 << endl << "-------" << endl;
			cout << "Code: " << item[i].code << endl
			     << "Name: " << item[i].name << endl
			     << "Unit Price: " << item[i].price << " TK" << endl;
			cout << "Quantity: " << quantity[i] << endl;

			int totalPrice = quantity[i] * item[i].price;

			cout << "Total Price: " << totalPrice << " TK" << endl << endl << endl;
			grandTotal += totalPrice;
		}
		cout << endl << endl << "Grand Total: " << grandTotal << " TK" << endl << endl;
	}
	void file() {
		ofstream billfile("bill.txt");
		billfile << "You have purchased " << totalItem << " items" << endl << endl << endl;
		grandTotal = 0;

		for (int i = 0; i < totalItem; ++i)
		{
			billfile << "Item " << i + 1 << endl << "-------" << endl;
			billfile << "Code: " << item[i].code << endl
			         << "Name: " << item[i].name << endl
			         << "Unit Price: " << item[i].price << " TK" << endl;
			billfile << "Quantity: " << quantity[i] << endl;

			int totalPrice = quantity[i] * item[i].price;

			billfile << "Total Price: " << totalPrice << " TK" << endl << endl << endl;
			grandTotal += totalPrice;
		}
		billfile << endl << endl << "Grand Total: " << grandTotal << " TK" << endl << endl;
	}
};

void options() {
	cout << "\t\t\t\tASFI Store Manager" << endl << endl;
	cout << "1. ADD NEW PRODUCT" << endl;
	cout << "2. ADD PRODUCT TO BILL" << endl;
	cout << "3. SHOW BILL" << endl;
	cout << "4. Print BILL" << endl;
	cout << "5. EXIT" << endl << endl;
}

void showProducts(product a[], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << i + 1 << ". " << a[i].name << endl;
	}
}

int search(product a[], int n, string s) {
	for (int i = 0; i < n; ++i) {
		if (a[i].name == s)return i;
	}
	return -1;
}

int main() {

	product productList[100];
	int available = 0;
	bill b;

	while (1) {
		options();

		cout << "Enter a option" << endl;
		int x; cin >> x;
		system("cls");

		if (x == 1) {
			cout << "Enter the new product code" << endl;
			int c; cin >> c;
			cout << "Enter the new product name" << endl;
			string n; cin >> n;
			cout << "Enter the new product unit price" << endl;
			int p; cin >> p;
			cout << "Enter the new product stock" << endl;
			int s; cin >> s;
			productList[available].set(c, n, p, s);
			available++;
			system("cls");
			cout << "NEW PRODUCT ADDED TO THE LIST" << endl << endl;
		}
		else if (x == 2) {
			cout << "Available Products" << endl << endl;
			showProducts(productList, available);
			cout << endl << endl;
			cout << "Enter the product name" << endl;
			string n; cin >> n;
			cout << "Enter the quantity" << endl;
			int q; cin >> q;
			int idx = search(productList, available, n);
			system("cls");
			if (idx != -1 && productList[idx].getStock() >= q) {
				b.add(productList[idx], q);
				cout << n << " Added Successfully" << endl << endl;
			}
			else if (idx == -1) cout << n << " Not Found" << endl << endl;
			else cout << "Dont have enough stock" << endl << endl;

		}
		else if (x == 3) {
			b.show();
		}
		else if (x == 4) {
			b.file();
			cout << "File Saved In The Drive!" << endl << endl;
		}
		else if (x == 5)break;
		else cout << "Not a valid option" << endl;
	}

}
