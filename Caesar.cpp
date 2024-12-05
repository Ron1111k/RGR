#include "RGR.h"



size_t RandomValues(size_t LeftBorder, size_t RightBorder){
    ranlux24 generator(random_device{}());
    uniform_int_distribution<size_t> distribution(LeftBorder, RightBorder);
    size_t RdValue = distribution(generator);
    return RdValue;
}


void EncryptCaesar(string &programEncrFile,string &programOutFile, size_t key){

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
        if (ch >= '�' && ch <= '�') {
            ch+=key;
            if(ch > '�'){
                ch = ch - '�' + '�' - 1;
            }
        } 
        else if (ch >= '�' && ch <= '�') {
            ch+=key;
            if(ch>'�'){
                ch = ch - '�' + '�' - 1;
            }
        } 
        else if (ch >= 'a' && ch <= 'z') {

            ch+=key;

            if(ch<0) {
                ch -= key;
                ch = 'z'- ch;
                key -= ch;
                ch = 'a' + key - 1;
            }

            if(ch>'z'){
                ch = ch - 'z' + 'a' - 1;
            }
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch+=key;
            if(ch>'Z'){
            ch = ch - 'Z' + 'A' - 1;
            }
        }
        out << ch;
    }

    out.close();
    input.close();
    
}

void DecryptCaesar(string &programOutFile,string &DecFail, size_t key){


    ofstream out;
    ifstream in;
    char ch;


    in.open(programOutFile);
    out.open( DecFail);
    
    while (in.get(ch)) {
        if (ch >= '�' && ch <= '�') {
            ch-=key;
            if(ch < '�'){
                ch = ch +'�' -'�' + 1;
            }
        } else if (ch >= '�' && ch <= '�') {
            ch-=key;
            if(ch<'�'){
                ch = ch + '�' - '�' + 1;
            }
        } else if (ch >= 'a' && ch <= 'z') {
            ch-=key;
            if(ch<'a'){
                ch = ch +'z' - 'a' + 1;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch-=key;
            if(ch<'A')
            ch = ch + 'Z' - 'A' + 1;
        }
        out << ch;
    }
    out.close();
    in.close();
}



void Caesar( string &fileName, string &programEncrFile, string &programOutFile){
    
    size_t key ;
    string choice;


    cout<<"��� ����� ������:\n 1)��������� \n 2)�������������� \n 3)�����"<< endl;

    while(getline(cin,choice)){

        if(choice == "") continue;

        else if (choice == "1"){ // �������

            key = RandomValues(0, 24);

            EncryptCaesar(fileName,programEncrFile,key);

            cout << "Key:" << key << endl;
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

            cout<<"������ ������������? \n [y/n]  "<<endl;
            while(getline(cin,choice)){
                if(choice == ""){
                    continue;
                }
                else if (choice == "y"){
                    DecryptCaesar(programEncrFile,programOutFile, key);
                    cout <<  "���������� ������� �����������." << endl;
                    cout <<"������� ��������� � �������?" << endl << "[y/n] ";

                        while (getline(cin, choice)){
                            if (choice == "y"){
                                cout <<  "���������: " << endl;
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

                else if(choice == "n") {
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

            DecryptCaesar(fileName,programOutFile, key);
            
            cout << "Key:" << key << endl;

            cout <<"���������� ������� �����������." << endl;
            cout <<"������� ��������� � �������?" << endl << "[y/n] ";

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










