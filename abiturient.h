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
        cout << "�������: "; cin >> info[0];
        cout << "���: "; cin >> info[1];
        cout << "��������: "; cin >> info[2];
        string S;
        cout << "���: "; cin >> S;
        if (S[0] == '�' || S[0] == '�') gender = 1;
        else if (S[0] == '�' || S[0] == '�') gender = 0;
        cout << "���� ��������: ";  
        getline(cin, info[3]);
        getline(cin, info[3]);
        cout << "��������������: "; 
        getline(cin, info[4]);
        cout << "\n�����: \n";
        cout << "   ������: ";      
        getline(cin, info[5]);
        cout << "   ������: ";  
        getline(cin, info[6]);
        cout << "   ��������� �����: ";
        getline(cin, info[7]);
        cout << "   �����: ";       
        getline(cin, info[8]);
        info[8] = "��.�" + info[8];
        cout << "   ���: "; cin >> info[9];
        info[9] = "���" + info[9];
        cout << "   ��������: "; cin >> info[10];
        info[10] = "��.�" + info[10];
        cout << "   �������� ������: "; cin >> mail_index;
        puts("\n���������� ���:");
        cout << "   ������� ����: "; cin >> russian;
        cout << "   ����������: "; cin >> math;
        cout << "   �����������: "; cin >> inform;
        system("cls");
    }
    void output() {
        if (summa_ballov() >= 0 && summa_ballov() <= 300 && mail_index > 0) {
            cout << "�������: " << info[0] << endl;
            cout << "���: " << info[1] << endl;
            cout << "��������: " << info[2] << endl;
            if (gender) cout << "���: �������\n";
            else cout << "���: �������\n";
            cout << "���� ��������: " << info[3] << endl;
            cout << "��������������: " << info[4] << endl;
            cout << "\n�����: ";
            for (int i = 5; i < 11; i++) cout << info[i] << ", ";
            cout << mail_index;
            puts("\n\n���������� ���:");
            cout << "   ������� ����: " << russian << endl;
            cout << "   ����������: " << math << endl;
            cout << "   �����������: " << inform << endl;
            cout << "��������� ����: " << summa_ballov() << endl;
            cout << "��������� ����: " << summa_ballov() / 60 << endl << endl;
        }
        else puts("������: ������������ ������!\n");
    }
    void read_from_file(string name) {
        fstream file(name);
        file.seekg(cursor_pos);
        if (file.good()) {
            file >> gender;
            for (int i = 0; i < 11; i++) file >> info[i];
            file >> mail_index;
            /*���������� ���*/ {
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
                if (info[i][j] == ' ') info[i][j] = '�';
            file << info[i] << endl;
        }//����� ������� �������� ��� ������������ ������ � ������.
        file << mail_index << endl;
        /*���������� ���*/ {
            file << russian << endl;
            file << math << endl;
            file << inform << endl;
        }
        cursor_pos = file.tellg();
    }
};