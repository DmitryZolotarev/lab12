#include "abiturient.h"

int main() {
	system("cls");
	puts("Abiturient Manager 1.2\n");
	int n, command;
	string file_name;
	cout << "Quantity of abiturients: ";
	cin >> n;
	cout << endl;
	puts("List of files in a program folder:\n");
	system("dir /b");
	cout << "\nEnter a name of file with database: ";
	cin >> file_name;
	abiturient* abiturients = new abiturient[n];
	while(true){
		streamoff current_position = 0;
		system("cls");
		puts("Abiturient Manager 1.2\n");
		puts("Command list:");
		puts("	1 - input a data about form keyboard");
		puts("	2 - write an inputted data to file");
		puts("	3 - read a data from file");
		puts("	4 - out the all database about abiturients");
		puts("	5 - out the data about abiturients, who can go to the university");
		puts("	6 - view the abiturients quantity");
		puts("	7 - change the abiturients quantity");
		puts("	8 - change file for program\n");
		cin >> command;
		system("cls");
		switch (command) {
			case 1:
				for (int i = 0; i < n; i++) {
					cout << i + 1 << " abiturient:\n\n";
					abiturients[i].input();
				}
				break;
			case 2:
				{ofstream file(file_name); }/*Создание или перезапись файла*/
				for (int i = 0; i < n; i++) {
					abiturients[i].cursor_pos = current_position;
					abiturients[i].write_to_file(file_name);
					current_position = abiturients[i].cursor_pos;
				}
				cout << "Data have written to file " << file_name << ".\n\n";
				system("pause");
				break;
			case 3:
				for (int i = 0; i < n; i++) {
					abiturients[i].cursor_pos = current_position;
					abiturients[i].read_from_file(file_name);
					current_position = abiturients[i].cursor_pos;
				}	
				if (current_position != 0) cout << "Data have red from the file " << file_name << ".\n\n";
				else cout << "Error: file " << file_name << "is missing or empty!\n\n";
				system("pause");
				break;
			case 4:
				for (int i = 0; i < n; i++) {
					cout << i + 1 << " abiturient:\n\n";
					abiturients[i].output();
				}
				system("pause");
				break;
			case 5:
				for (int i = 0, j = 0; i < n; i++)
					if (abiturients[i].summa_ballov() >= 240) {
						j++;
						cout << j << " abiturient:\n\n";
						abiturients[i].output();
					}
				cout << endl;
				system("pause");
				break;
			case 6:
				cout << "Quantity of abiturients: " << n << endl << endl;
				system("pause");
				break;
			case 7:
				cout << "Quantity of abiturients: ";
				cin >> n;
				break;
			case 8:
				puts("List of files in a program folder:\n");
				system("dir /b");
				cout << "\nEnter a name of file with database: ";
				cin >> file_name;
				break;
		}
	}
}