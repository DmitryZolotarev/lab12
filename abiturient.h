#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

struct abiturient {
    string info[11];
    int russian, math, inform, mail_index;
    streamoff cursor_pos = 0;
    bool gender = 1;
    float summa_ballov() {
        return russian + math + inform;
    }
    void input() {
        cout << "Фамилия: "; cin >> info[0];
        cout << "Имя: "; cin >> info[1];
        cout << "Отчество: "; cin >> info[2];
        string S;
        cout << "Пол: "; cin >> S;
        if (S[0] == 'М' || S[0] == 'м') gender = 1;
        else if (S[0] == 'Ж' || S[0] == 'ж') gender = 0;
        cout << "Дата рождения: ";  
        getline(cin, info[3]);
        getline(cin, info[3]);
        cout << "Национальность: "; 
        getline(cin, info[4]);
        cout << "\nАдрес: \n";
        cout << "   Страна: ";      
        getline(cin, info[5]);
        cout << "   Регион: ";  
        getline(cin, info[6]);
        cout << "   Населённый пункт: ";
        getline(cin, info[7]);
        cout << "   Улица: ";       
        getline(cin, info[8]);
        info[8] = "ул. " + info[8];
        cout << "   Дом: "; cin >> info[9];
        info[9] = "дом " + info[9];
        cout << "   Квартира: "; cin >> info[10];
        info[10] = "кв. " + info[10];
        cout << "   Почтовый индекс: "; cin >> mail_index;
        puts("\nРезультаты ЕГЭ:");
        cout << "   Русский язык: "; cin >> russian;
        cout << "   Математика: "; cin >> math;
        cout << "   Информатика: "; cin >> inform;
        system("cls");
    }
    void output() {
        if (summa_ballov() >= 0 && summa_ballov() <= 300 && mail_index > 0) {
            cout << "Фамилия: " << info[0] << endl;
            cout << "Имя: " << info[1] << endl;
            cout << "Отчество: " << info[2] << endl;
            if (gender) cout << "Пол: мужской\n";
            else cout << "Пол: женский\n";
            cout << "Дата рождения: " << info[3] << endl;
            cout << "Национальность: " << info[4] << endl;
            cout << "\nАдрес: ";
            for (int i = 5; i < 11; i++) cout << info[i] << ", ";
            cout << mail_index;
            puts("\n\nРезультаты ЕГЭ:");
            cout << "   Русский язык: " << russian << endl;
            cout << "   Математика: " << math << endl;
            cout << "   Информатика: " << inform << endl;
            cout << "Суммарный балл: " << summa_ballov() << endl;
            cout << "Проходной балл: " << summa_ballov() / 60 << endl << endl;
        }
        else puts("Ошибка: некорректные данные!\n");
    }
    void read_from_file(string name) {
        fstream file(name);
        file.seekg(cursor_pos);
        if (file.good()) {
            file >> gender;
            for (int i = 0; i < 11; i++) file >> info[i];
            file >> mail_index;
            /*Результаты ЕГЭ*/ {
                file >> russian;
                file >> math;
                file >> inform;
            }
            cursor_pos = file.tellg();
        }    
    }
    void write_to_file(string name) {
        fstream file(name);
        file.seekg(cursor_pos);
        file << gender << endl;
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < info[i].length(); j++)
                if (info[i][j] == ' ') info[i][j] = ' ';
            file << info[i] << endl;
        }//смена формата пробелов для корректности работы с файлом.
        file << mail_index << endl;
        /*Результаты ЕГЭ*/ {
            file << russian << endl;
            file << math << endl;
            file << inform << endl;
        }
        cursor_pos = file.tellg();
    }
};