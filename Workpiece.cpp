#include "RGR.h"


bool isRightPassword(){
    string rightPassword = "11.11";
    cout << " ������� ������" << endl;
    string checkPassword;
    getline(cin, checkPassword);
    while (checkPassword != rightPassword){
        system("cls");
        if (checkPassword == "exit"){
            return false;
        }
        cout << "�������� ������" << endl;
        cout << "������� ������ ��� ������� ��� ������ \"exit\"" << endl;
        getline(cin, checkPassword);
    }
    cout << "����� ������ ������" << endl;
    return true;
}


void inFile( string& outputFile){
    ofstream out(outputFile); //����� ������ � ����
    if (!out.is_open()){
        stringstream serr;
        serr << "���������� ������� ����.";
        throw runtime_error(serr.str());
    }
    cout << "������� ��� ���������, ����� ��������� \"end\"" << endl;
    string str;
    while (getline(cin, str)){
        if (str.empty()) continue;
        if (str == "end") break;
        out << str << '\n';
    }
    out.close();
    ifstream check(outputFile);
    if (check.peek() == EOF){
        stringstream serr;
        serr << "����� ������ ���� �� ���-��.";
        throw runtime_error(serr.str());
    }
    
    check.close();
}

void EncryptionMethods( string &fileName,  string &programEncrFile,  string &programOutFile, string &DecFile){
    bool isGoBack = false;
    string choice;
    while (!isGoBack){
        cout << "�������� ����:" << endl << "1) ������" << endl;
        cout << "2) �����" << endl << "3) ��������" << endl << "4) ������� �� ���������� ���" << endl;
        cin >> choice;
        switch (choice[0]) {
            case '1':
                Caesar(fileName, programEncrFile, programOutFile);
                isGoBack = true;
                break;
            case '2':
                 Atbash(fileName, programEncrFile, programOutFile);
                 isGoBack = true;
                break;
            case '3':
                PlayFair(fileName,programEncrFile,programOutFile,DecFile);
                isGoBack = true;
                break;
            case '4':
                system("cls");
                isGoBack = true;
                break;
            default:
                system("cls");
                cout << "������ �������� �� ����������" << endl;
                system("pause");
        }
    }
}

void displayFile( string &str){
    ifstream input(str);
    char ch;
    while(input.get(ch)){
        cout << ch;
    }
    cout << endl;
}
