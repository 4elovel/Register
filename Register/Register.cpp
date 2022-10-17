#include <iostream>
#include <string>

using namespace std;

bool check_login(string login) {
	if (login.size() > 6 && login.find(" ") == string::npos && login.size() < 20)
	{
		return true;
	}
	return false;
}

bool check_pass(string password) {
	if (password.size() > 6 && password.find(" ") == string::npos && password.size() < 20)
	{
		return true;
	}
	return false;
}

bool inline check_Sign(string login,string password) {
	if (check_login(login) && check_pass(password))
	{
		return true;
	}
	return false;
}

void reg_init() {
	bool leaver;
	bool run = true;
	int choice;
	string login="", password = "";
	while (run)
	{
		system("CLS");
		cout << "Choose the option->\n";
		cout << "1 - Sign in\n";
		cout << "2 - Log in\n";
		cout << "3 - Forget password?\n";
		cin >> choice;
		switch (choice)
		{
		case(1):
			system("CLS");
			cout << "e - to return\n\n";

			leaver = false;
			while (true) {
				cout << "Write your login->\n";
				cin >> login;
				if (login == "e") {
					leaver = true;
					break;
				}
				if (!check_login(login)) {
					cout << "INVALID LOGIN\n";
					continue;
				}

				cout << "Write your password->\n";
				cin >> password;
				if (password == "e") {
					leaver = true;
					break;
				}
				if (!check_pass(password)) {
					cout << "INVALID PASSWORD\n";
					continue;
				}
				break;
			}
			if (leaver) continue;
			cout << "SUCCESSFULLY\n";
			run = false;
			break;
		default:
			break;
		}
	}
}

int main()
{
	reg_init();
}
