#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	int x = 0;
	int y = 0;
	char path[100];
	cout << "Enter the path to the file (for example-C:\\Users\\Mister\\Desktop\\maximum\\disbalans):" << endl;
	cin >> path;
	strcat_s(path, ".txt");
	string s;
	ifstream rea(path);
	if (rea.is_open()) {
		x = 1;
		cout << endl;
		cout << "The file is opened" << endl;
		cout << "______________________" << endl;
		while (getline(rea, s)) {
			if (s.find('{') != string::npos && s.find('}') != string::npos) {
					a++;
					b++;
			}
			else {
				if (s.find('{') != string::npos) {
					a++;
				}
				if (s.find('}')!= string::npos) {
					b++;
				}
			}
			cout << s << endl;
		}
		cout << "______________________" << endl;
		rea.close();
	}
	else {
		x = 2;
		cout << endl;
		cout << "The file can't be open" << endl;
	}
	if (x == 1) {
		ofstream out(path, ios_base::app);
		out << endl;
		out << "----------------------" << endl;
		if (a == b && a!=0) {
			cout << endl;
			cout << "Everything is fine" << endl;
			cout << "Number of pairs:" << a << endl;
			out << "Everything is fine" << endl;
			out << "Number of pairs:" << a << endl;
		}
		else if (a > b) {
			cout << endl;
			cout << "Problem! Opening more" << endl;
			cout << "Number  of opening: " << a << endl;
			cout << "Number of closing: " << b << endl;
			out << "Problem! Opening more" << endl;
			out << "Number  of opening: " << a << endl;
			out << "Number of closing: " << b << endl;
		}
		else if (a < b) {
			cout << endl;
			cout << "Problem! Closing more" << endl;
			cout << "Number  of opening: " << a << endl;
			cout << "Number of closing: " << b << endl;
			out << "Problem! Closing more" << endl;
			out << "Number  of opening: " << a << endl;
			out << "Number of closing: " << b << endl;
		}
		else {
			cout << endl;
			cout << "Braces are missing!" << endl;
			out << "Braces are missing!" << endl;
		}
		out.close();
	}
	system("pause");
	return 0;
}