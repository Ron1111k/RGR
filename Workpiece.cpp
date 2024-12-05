#include "RGR.h"


bool isRightPassword(){
    string rightPassword = "11.11";
    cout << " Введите пароль" << endl;
    string checkPassword;
    getline(cin, checkPassword);
    while (checkPassword != rightPassword){
        system("cls");
        if (checkPassword == "exit"){
            return false;
        }
        cout << "Неверный пароль" << endl;
        cout << "Введите пароль или команду для выхода \"exit\"" << endl;
        getline(cin, checkPassword);
    }
    cout << "Введён верный пароль" << endl;
    return true;
}


void inFile( string& outputFile){
    ofstream out(outputFile); //поток записи в файл
    if (!out.is_open()){
        stringstream serr;
        serr << "Невозможно открыть файл.";
        throw runtime_error(serr.str());
    }
    cout << "Введите своё сообщение, затем отправьте \"end\"" << endl;
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
        serr << "Нужно ввести хотя бы что-то.";
        throw runtime_error(serr.str());
    }
    
    check.close();
}

void EncryptionMethods( string &fileName,  string &programEncrFile,  string &programOutFile, string &DecFile){
    bool isGoBack = false;
    string choice;
    while (!isGoBack){
        cout << "Выберите шифр:" << endl << "1) Цезаря" << endl;
        cout << "2) Атбаш" << endl << "3) Плейфера" << endl << "4) Возврат на предыдущий шаг" << endl;
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
                cout << "Такого варианта не существует" << endl;
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
