#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <bitset>
#include <queue>
#include <string>

#define TEST_FILE "test1_ALU.txt"
#define ANS_FILE "ans1_ALU.txt"
using namespace std;

int main() {
	queue<string> test, ans;
	srand(time(NULL));
	cout << "The follow instructions will help you produce some test data.\nAll the data would show in the end." << endl;
	for (int i = 1; ; i++) {
		int operation;
		string prefix;
		int src1, src2;
		int answer;
		bool overflow = false;

		cout << "\nTest data " << i << ":" << endl;
		cout << "\n1) Addition\t2) Subtraction\t3) And\n4) Or\t\t5) Not\t\t6) Set on less than" << endl;
		cout << "Please choose the function of the ALU(-1 to exit): ";
		cin >> operation;

		if (operation == -1)
			break;

		char q;
		cout << "Random produce Src1? (y/n): ";
		cin >> q;
		if (tolower(q) == 'y')
			src1 = rand() * rand() * rand();
		else
			cin >> src1;
		cout << "Src1 is " << src1 << '.' << endl;

		cout << "Random produce Src2? (y/n): ";
		cin >> q;
		if (tolower(q) == 'y')
			src2 = rand() * rand() * rand();
		else
			cin >> src2;
		cout << "Src2 is " << src2 << '.' << endl;

		switch (operation) {
		case 1:
			prefix = "00010";
			answer = src1 + src2;
			break;
		case 2:
			prefix = "01010";
			answer = src1 - src2;
			break;
		case 3:
			prefix = "00000";
			answer = src1 & src2;
			break;
		case 4:
			prefix = "00001";
			answer = src1 | src2;
			break;
		case 5:
			prefix = "10110";
			answer = ~src1;
			break;
		case 6:
			prefix = "01011";
			answer = src1 < src2 ? 1 : 0;
			break;
		}

		if (operation != 5)
			overflow = prefix[1] == '1' ?
			(src1 > 0 && src2 < 0 && (src1 - src2) < 0 || src1 < 0 && src2 > 0 && (src1 - src2) > 0) :
			(src1 > 0 && src2 > 0 && (src1 + src2) < 0 || src1 < 0 && src2 < 0 && (src1 + src2) > 0);

		bitset<32> src1_bit(src1), src2_bit(src2), ans_bit(answer);
		string test_str = prefix + src1_bit.to_string() + src2_bit.to_string();
		string ans_str = string(overflow ? "1" : "0") + string(answer == 0 ? "1" : "0") + ans_bit.to_string();

		test.push(test_str);
		ans.push(ans_str);
	}

	ofstream t_file(TEST_FILE, ios::out);
	ofstream a_file(ANS_FILE, ios::out);

	cout << "\n*************************************************************\n";
	cout << "The follows are test data: \n";
	while (!test.empty()) {
		cout << test.front() << endl;
		t_file << test.front() << '\n';
		test.pop();
	}

	cout << "\n*************************************************************\n";
	cout << "The follows are answer data: \n";
	while (!ans.empty()) {
		cout << ans.front() << endl;
		a_file << ans.front() << '\n';
		ans.pop();
	}

	t_file.close();
	a_file.close();
	cout << "\n*************************************************************\n";
	cout << "The test data and answer data have also been saved in " << TEST_FILE << " and " << ANS_FILE << endl;
	cin.get();
}
