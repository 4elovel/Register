#include <iostream>
#include <string>
#include "MD_5.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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
	string login="", password = "", question = "", answer = "", u_answer = "";;
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
		case(1): //Регістрація
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

				cout << "Write your question->\n";
				cin >> question;
				if (question == "e") {
					leaver = true;
					break;
				}
				
				cout << "Write your answer->\n";
				cin >> answer;
				if (answer == "e") {
					leaver = true;
					break;
				}

				break;
			}
			if (leaver) continue;
			cout << " ACCOUNT SUCCESSFULLY REGISTERED\n";
			Sleep(1000);
			login = md5(login); //хеш логіна
			password += login; //додавання солі
			password = md5(password); //хеш пароля
			answer = md5(answer);
			//Запис в базу хеш логіна
			//Запис в базу хеш пароля
			//Запис в базу питання
			//Запис в базу хеш відповіді
			break;
		case(2): //Вхід

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

				cout << "Write your password->\n";
				cin >> password;
				if (password == "e") {
					leaver = true;
					break;
				}

				//тут треба перевірити чи є в базі
				if (login=="admin" && password=="admin")
				{
					cout << "LOG IN SUCCESSFUL\n";
					run = false;
					leaver = true;
					Sleep(1000);
					break;
				} //
				else 
				{
					cout << "LOG IN UNSUCCESSFUL\n";
					cout << "WRONG LOGIN OR PASSWORD\n";
					Sleep(1000);
				}


			}
			if (leaver) continue;
			break;
		case(3): //відновлення

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
				//Перевірка чи є в базі
				if (login == "admin") {
					//витягуєм питання з бази
					question = "A or B";
					//витягуєм відповідь з бази
					answer = "A";
					cout << question << "\n";
					cin >> u_answer;
					if (u_answer == "e") {
						leaver = true;
						break;
					}
					if (answer == u_answer)
					{
						cout << "WELCOME\n";
						cout << "Write your new password->\n";
						cin >> password;
						if (password == "e") {
							leaver = true;
							break;
						}
						//запис пароля в базу
						cout << "PASSWORD SUCCESSFULLY SAVED\n";
						leaver = true;
						Sleep(1000);
						break;
					}
					else
					{
						cout << "WRONG ANSWER\n";
					}
				}
				else
				{
					cout << "WRONG LOGIN\n";
				}
			}
			if (leaver) continue;
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
