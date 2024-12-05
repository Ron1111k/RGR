#include "RGR.h"


void atbashEncrypt(string &programEncrFile,string &programOutFile) {
    string output;
    ofstream out;
    ifstream input;
    char ch;

    input.open(programEncrFile);
    out.open(programOutFile);

    if (!input.is_open() || !out.is_open()){
                stringstream serr;
                serr << "�� ������� ������� ����.";
                throw runtime_error(serr.str());
    }


    while (input.get(ch)) { 

        if (ch >= '�' && ch <= '�'){  
            ch= '�' - ( ch - '�' ); 
        }

        else if (ch >= '�' && ch <= '�'){
            ch = '�' - ( ch - '�' ); 
        }

        else if (ch >= 'A' && ch <= 'Z'){
            ch = 'Z' - ( ch - 'A' );
        }

        else if (ch >= 'a' && ch <= 'z'){
             ch = 'z' - ( ch - 'a' );
        }

        out << ch;
    }
   
}

void Atbash(string &fileName, string &programEncrFile, string &programOutFile){
     string choice;


    cout<<"��� ����� ������:\n 1)��������� \n 2)�������������� \n 3)�����"<< endl;

    while(getline(cin,choice)){

        if(choice == "") continue;

        else if (choice == "1"){ // �������

             atbashEncrypt(fileName,programEncrFile);

            cout << "���������� ������� �����������." << endl;
            cout << "������� ��������� � �������?" << endl << "[y/n] ";
            while (getline(cin, choice)){
                if (choice == "y"){
                    cout << "���������: " << endl;
                    displayFile(programEncrFile);
                    break;
                } else if (choice == "n"){
                    break;
                }
                else {
                    cout<<"������� ���������� �������"<< endl;
                    continue;
            }
            break;
            cout << endl;
            }

            cout<<"������ ������������? \n 1)�� \n 2) ��� "<<endl;
            while(getline(cin,choice)){
                if(choice == ""){
                    continue;
                }
                else if (choice == "1"){
                    atbashEncrypt(programEncrFile,programOutFile);
                    cout << "���������� ������� �����������." << endl;
                    cout << "������� ��������� � �������?" << endl << "[y/n] ";

                        while (getline(cin, choice)){
                            if (choice == "y"){
                                cout << "���������: " << endl;
                                displayFile(programOutFile);
                                break;
                            } else if (choice == "n"){
                                break;
                            }
                            else {
                                cout<<"������� ���������� �������"<< endl;
                                continue;
                                }
                        }
                        break;
                        cout << endl;   
                }

                else if(choice == "2") {
                    break;
                cout << endl;
                }
                else {
                    cout<<"������� ���������� �������"<< endl;
                    continue;
            }

            }
            break;
            cout<<endl;
        }



        else if(choice == "2"){ // ��������������
            atbashEncrypt(fileName,programOutFile);
            

            cout << "���������� ������� �����������." << endl;
            cout << "������� ��������� � �������?" << endl << "[y/n] ";

            while (getline(cin, choice)){
                if (choice == "y"){
                    cout << "���������: " << endl;
                    displayFile(programOutFile);
                    break;
                } else if (choice == "n"){
                    break;
                }
            }
         break;
            cout << endl;   
        }

        else if (choice == "3"){
             system("cls");
                break;
        }


        else {
            cout<<"������ ������ ��� "<< endl;
            break;
        }


    }
    cout<< endl;

}
