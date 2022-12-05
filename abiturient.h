#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

struct abiturient {
    string info[16];
    int russian, math, inform;
    streamoff cursor_pos = 0;
    void ball_to_int() {
        russian = 0; math = 0; inform = 0;
        for (int i = info[12].length() - 1, j = 1; i >= 0; i--)
            if (info[12][i] >= '0' && info[12][i] <= '9') {
                russian += (info[12][i] - 48) * j;
                j *= 10;
            }  
        for (int i = info[13].length() - 1, j = 1; i >= 0; i--)
            if (info[13][i] >= '0' && info[13][i] <= '9') {
                math += (info[13][i] - 48) * j;
                j *= 10;
            }   
        for (int i = info[14].length() - 1, j = 1; i >= 0; i--)
            if (info[14][i] >= '0' && info[14][i] <= '9') {
                inform += (info[14][i] - 48) * j;
                j *= 10;
            }
    }
    float summa_ballov() {
        return russian + math + inform;
    }
    void input() {
        cout << "First name: "; cin >> info[0];
        cout << "Middle name: "; cin >> info[1];
        cout << "Surname: "; cin >> info[2];
        if (info[2].length() == 0) cin >> info[2];
        cout << "Sex: "; cin >> info[3];
        cout << "Date of birth: ";  
        getline(cin, info[4]);
        if (info[4].length() == 0) getline(cin, info[4]);
        cout << "Nation: "; 
        getline(cin, info[5]);
        cout << "\nAddress: \n";
        cout << "   Country: ";      
        getline(cin, info[6]);
        cout << "   Region: ";  
        getline(cin, info[7]);
        cout << "   Locality: ";
        getline(cin, info[8]);
        cout << "   Street: ";       
        getline(cin, info[9]);
        info[9] = info[9] + "st.";
        cout << "   House: "; cin >> info[10];
        info[10] = "house " + info[10];
        cout << "   Flat: "; cin >> info[11];
        info[11] = "flat " + info[11];
        cout << "   Mail index: "; cin >> info[12];
        puts("\nResults of exams:");
        cout << "   English: "; cin >> info[13];
        cout << "   Math: "; cin >> info[14];
        cout << "   Infomatics: "; cin >> info[15];
        ball_to_int();
        system("cls");
    }
    void output() {
        if (summa_ballov() >= 0 && summa_ballov() <= 300) {
            cout << "First name: " << info[0] << endl;
            cout << "Middle name: " << info[1] << endl;
            cout << "Surname: " << info[2] << endl;
            cout << "Sex: " << info[3] << endl;
            cout << "Date of birth: " << info[4] << endl;
            cout << "Nation: " << info[5] << endl;
            cout << "\nAddress: ";
            for (int i = 6; i < 12; i++) cout << info[i] << ", ";
            cout << info[12];
            puts("\n\nResults of exams:");
            cout << "   English: " << russian << endl;
            cout << "   Math: " << math << endl;
            cout << "   Informatics: " << inform << endl;
            cout << "Summ of scores: " << summa_ballov() << endl;
            cout << "Passing score: " << summa_ballov() / 60 << endl << endl;
        }
        else puts("Error: incorrect data!\n");
    }
    void read_from_file(string name) {
        ifstream file(name, ios::binary);
        if (file.good()) {
            int i = 0;
            char n = '0', *x = &n;
            while (i < 16) {
                file.seekg(cursor_pos);
                file.read(x, sizeof(char));
                cout << info[i] << endl;
                cout << *x << ' ' << i << ' ' << cursor_pos << endl;
                system("pause");
                if (*x < 32 && info[i].length() > 0) i++;
                if (!file.good()) break;
                info[i] = info[i] + *x;
                cursor_pos++;
            }
            cursor_pos = file.tellg();
            cursor_pos++;
            ball_to_int();
        }    
    }
    void write_to_file(string name) {
        fstream file(name, ios::binary);
        file.open(name);
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < info[i].length(); j++) {
                file.seekg(cursor_pos);
                file.write(&info[i][j], sizeof(char));
                cursor_pos++;
            }
            file.seekg(cursor_pos);
            char n = '\n';
            file.write(&n, sizeof(char));
            cursor_pos++;    
        }
    }
};
