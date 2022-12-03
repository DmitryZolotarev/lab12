#include "abiturient.h"

int main() {
	system("chcp 1251");
	system("cls");
	puts("Abiturient Manager 1.0\n");
	int n, command;
	string file_name;
	streamoff current_position = 0;
	cout << "Количество абитуриентов: ";
	cin >> n;
	cout << endl;
	system("dir");
	cout << "\nВведите имя файла с базой данных из списка выше: ";
	cin >> file_name;
	abiturient* abiturients = new abiturient[n];
	while(true){
		system("cls");
		puts("Abiturient Manager 1.0\n");
		puts("Список команд:");
		puts("	1 - ввод данных об абитуриентах с клавиатуры");
		puts("	2 - запись введённых данных в файл");
		puts("	3 - чтение данных об абитуриентах из файла");
		puts("	4 - вывод всей базы данных об абитуриентах");
		puts("	5 - вывод данных об абитуриентах, которые смогли поступить в ВУЗ, набрав проходной балл");
		puts("	6 - просмотр количества абитуриентов");
		puts("	7 - изменение количества абитуриентов");
		puts("	8 - смена файла, с которым работает программа\n");
		cin >> command;
		system("cls");
		switch (command) {
			case 1:
				for (int i = 0; i < n; i++) {
					cout << i + 1 << " абитуриент:\n\n";
					abiturients[i].input();
				}
				break;
			case 2:
				for (int i = 0; i < n; i++) {
					abiturients[i].cursor_pos = current_position;
					abiturients[i].write_to_file(file_name);
					current_position = abiturients[i].cursor_pos;
				}
				cout << "Данные записаны в файл " << file_name << ".\n\n";
				system("pause");
				break;
			case 3:
				for (int i = 0; i < n; i++) {
					abiturients[i].cursor_pos = current_position;
					abiturients[i].read_from_file(file_name);
					current_position = abiturients[i].cursor_pos;
				}	
				cout << "Данные прочитаны из файла " << file_name << ".\n\n";;
				system("pause");
				break;
			case 4:
				for (int i = 0; i < n; i++) {
					cout << i + 1 << " абитуриент:\n\n";
					abiturients[i].output();
				}
				system("pause");
				break;
			case 5:
				for (int i = 0, j = 0; i < n; i++)
					if (abiturients[i].summa_ballov() >= 240) {
						j++;
						cout << j << " абитуриент:\n\n";
						abiturients[i].output();
					}
				cout << endl;
				system("pause");
				break;
			case 6:
				cout << "Количество абитуриентов: " << n << endl << endl;
				system("pause");
				break;
			case 7:
				cout << "Количество абитуриентов: ";
				cin >> n;
				break;
			case 8:
				system("dir");
				cout << "\nВведите имя файла с базой данных из списка выше: ";
				cin >> file_name;
				break;
		}
	}
}