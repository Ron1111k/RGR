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
          cout << "��������, � ��� ����� ��������������:" << endl << "1) ������������ ����;" << endl << "2) �����, �������� � �������;" << endl
        << "3) ����� �� ���������." << endl;
        cin>> choice;
        switch (choice[0])
        {
        case '1':
             cout << "������� �������� ������������� �����" << endl;
             cin >> fileName;
             try
             {
                ifstream input (fileName);
                if (!input.is_open()){
                        stringstream serr;
                        serr << "���� �� ����������.";
                        throw runtime_error(serr.str());
             }
               else {
                        input.close();
                        if (fileName != programEncrFile && fileName != programOutFile){
                            EncryptionMethods(fileName, programEncrFile, programOutFile,DecFile);
                        } else {
                            cout << "�� ����� ������ �����" << endl;
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
                cout << "������ �������� �� ����������" << endl;
        }
    }
        

    return 0;
}