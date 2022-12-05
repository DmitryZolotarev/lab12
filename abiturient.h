#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

struct abiturient {
    string info[15];
    int russian, math, inform;
    streamoff cursor_pos = 0;
    bool gender = 1;
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
        cout << "Ôàìèëèÿ: "; cin >> info[0];
        cout << "Èìÿ: "; cin >> info[1];
        cout << "Îò÷åñòâî: "; cin >> info[2];
        if (info[2].length() == 0) cin >> info[2];
        string S;
        cout << "Ïîë: "; cin >> S;
        if (S[0] == 'Ì' || S[0] == 'ì') gender = 1;
        else if (S[0] == 'Æ' || S[0] == 'æ') gender = 0;
        cout << "Äàòà ðîæäåíèÿ: ";  
        getline(cin, info[3]);
        if (info[3].length() == 0) getline(cin, info[3]);
        cout << "Íàöèîíàëüíîñòü: "; 
        getline(cin, info[4]);
        cout << "\nÀäðåñ: \n";
        cout << "   Ñòðàíà: ";      
        getline(cin, info[5]);
        cout << "   Ðåãèîí: ";  
        getline(cin, info[6]);
        cout << "   Íàñåë¸ííûé ïóíêò: ";
        getline(cin, info[7]);
        cout << "   Óëèöà: ";       
        getline(cin, info[8]);
        info[8] = "óë. " + info[8];
        cout << "   Äîì: "; cin >> info[9];
        info[9] = "äîì " + info[9];
        cout << "   Êâàðòèðà: "; cin >> info[10];
        info[10] = "êâ. " + info[10];
        cout << "   Ïî÷òîâûé èíäåêñ: "; cin >> info[11];
        puts("\nÐåçóëüòàòû ÅÃÝ:");
        cout << "   Ðóññêèé ÿçûê: "; cin >> info[12];
        cout << "   Ìàòåìàòèêà: "; cin >> info[13];
        cout << "   Èíôîðìàòèêà: "; cin >> info[14];
        ball_to_int();
        system("cls");
    }
    void output() {
        if (summa_ballov() >= 0 && summa_ballov() <= 300) {
            cout << "Ôàìèëèÿ: " << info[0] << endl;
            cout << "Èìÿ: " << info[1] << endl;
            cout << "Îò÷åñòâî: " << info[2] << endl;
            if (gender) cout << "Ïîë: ìóæñêîé\n";
            else cout << "Ïîë: æåíñêèé\n";
            cout << "Äàòà ðîæäåíèÿ: " << info[3] << endl;
            cout << "Íàöèîíàëüíîñòü: " << info[4] << endl;
            cout << "\nÀäðåñ: ";
            for (int i = 5; i < 11; i++) cout << info[i] << ", ";
            cout << info[11];
            puts("\n\nÐåçóëüòàòû ÅÃÝ:");
            cout << "   Ðóññêèé ÿçûê: " << russian << endl;
            cout << "   Ìàòåìàòèêà: " << math << endl;
            cout << "   Èíôîðìàòèêà: " << inform << endl;
            cout << "Ñóììàðíûé áàëë: " << summa_ballov() << endl;
            cout << "Ïðîõîäíîé áàëë: " << summa_ballov() / 60 << endl << endl;
        }
        else puts("Îøèáêà: íåêîððåêòíûå äàííûå!\n");
    }
    void read_from_file(string name) {
        fstream file(name);
        file.seekg(cursor_pos);
        if (file.good()) {
            file >> gender;
            for (int i = 0; i < 15; i++) file >> info[i];
            cursor_pos = file.tellg();
            ball_to_int();
        }    
    }
    void write_to_file(string name) {
        fstream file(name);
        file.seekg(cursor_pos);
        file << gender << endl;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < info[i].length(); j++)
                if (info[i][j] == ' ') info[i][j] = ' ';
            file << info[i] << endl;
        }//ñìåíà ôîðìàòà ïðîáåëîâ äëÿ êîððåêòíîñòè ðàáîòû ñ ôàéëîì.
        /*Ðåçóëüòàòû ÅÃÝ*/ {
            file << russian << endl;
            file << math << endl;
            file << inform << endl;
        }
        cursor_pos = file.tellg();
    }
};
