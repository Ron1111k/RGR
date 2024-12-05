#include"RGR.h"


int main(){
    system("chcp 1251");

    if(!isRightPassword()){
        cout << "Bye!" << endl;
        system("pause");
        return 0;
    }

    string fileName;
    string programInFile = "fileEnc.txt";
    string programEncrFile = "programEncrFile.txt";
    string programOutFile = "programOutFile.txt";
    string DecFile = "decFile.txt";

    bool exit = false;
    string choice;

    while(!exit){
          cout << "Выберете, с чем будет взаимодействие:" << endl << "1) Существующий файл;" << endl << "2) Текст, введённый в консоль;" << endl
        << "3) Выход из программы." << endl;
        cin>> choice;
        switch (choice[0])
        {
        case '1':
             cout << "Введите название существующего файла" << endl;
             cin >> fileName;
             try
             {
                ifstream input (fileName);
                if (!input.is_open()){
                        stringstream serr;
                        serr << "Файл не существует.";
                        throw runtime_error(serr.str());
             }
               else {
                        input.close();
                        if (fileName != programEncrFile && fileName != programOutFile){
                            EncryptionMethods(fileName, programEncrFile, programOutFile,DecFile);
                        } else {
                            cout << "Не самый лучший выбор" << endl;
                        }
                    }
             }
             catch(const exception& e)
             {
                std::cerr << e.what() << '\n';
             }
             
            break;
              case '2':
                try {
                    inFile(programInFile);
                    EncryptionMethods(programInFile, programEncrFile, programOutFile,DecFile);
                } catch (exception& ex){
                    system("cls");
                    cout << ex.what() << endl;
                }
                break;
            case '3':
                exit = true;
                cout << "Bye!" << endl;
                system("pause");
                break;
            default:
                system("cls");
                cout << "Такого варианта не существует" << endl;
        }
    }
        

    return 0;
}