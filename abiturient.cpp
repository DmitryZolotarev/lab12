#include "abiturient.h"

int main() {
	system("chcp 1251");
	system("cls");
	puts("Abiturient Manager 1.0\n");
	int n, command;
	string file_name;
	streamoff current_position = 0;
	cout << "���������� ������������: ";
	cin >> n;
	cout << endl;
	system("dir");
	cout << "\n������� ��� ����� � ����� ������ �� ������ ����: ";
	cin >> file_name;
	abiturient* abiturients = new abiturient[n];
	while(true){
		system("cls");
		puts("Abiturient Manager 1.0\n");
		puts("������ ������:");
		puts("	1 - ���� ������ �� ������������ � ����������");
		puts("	2 - ������ �������� ������ � ����");
		puts("	3 - ������ ������ �� ������������ �� �����");
		puts("	4 - ����� ���� ���� ������ �� ������������");
		puts("	5 - ����� ������ �� ������������, ������� ������ ��������� � ���, ������ ��������� ����");
		puts("	6 - �������� ���������� ������������");
		puts("	7 - ��������� ���������� ������������");
		puts("	8 - ����� �����, � ������� �������� ���������\n");
		cin >> command;
		system("cls");
		switch (command) {
			case 1:
				for (int i = 0; i < n; i++) {
					cout << i + 1 << " ����������:\n\n";
					abiturients[i].input();
				}
				break;
			case 2:
				for (int i = 0; i < n; i++) {
					abiturients[i].cursor_pos = current_position;
					abiturients[i].write_to_file(file_name);
					current_position = abiturients[i].cursor_pos;
				}
				cout << "������ �������� � ���� " << file_name << ".\n\n";
				system("pause");
				break;
			case 3:
				for (int i = 0; i < n; i++) {
					abiturients[i].cursor_pos = current_position;
					abiturients[i].read_from_file(file_name);
					current_position = abiturients[i].cursor_pos;
				}	
				cout << "������ ��������� �� ����� " << file_name << ".\n\n";;
				system("pause");
				break;
			case 4:
				for (int i = 0; i < n; i++) {
					cout << i + 1 << " ����������:\n\n";
					abiturients[i].output();
				}
				system("pause");
				break;
			case 5:
				for (int i = 0, j = 0; i < n; i++)
					if (abiturients[i].summa_ballov() >= 240) {
						j++;
						cout << j << " ����������:\n\n";
						abiturients[i].output();
					}
				cout << endl;
				system("pause");
				break;
			case 6:
				cout << "���������� ������������: " << n << endl << endl;
				system("pause");
				break;
			case 7:
				cout << "���������� ������������: ";
				cin >> n;
				break;
			case 8:
				system("dir");
				cout << "\n������� ��� ����� � ����� ������ �� ������ ����: ";
				cin >> file_name;
				break;
		}
	}
}