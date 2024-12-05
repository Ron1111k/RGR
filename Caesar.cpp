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
                serr << "Не удалось открыть файл.";
                throw runtime_error(serr.str());
            }

       while (input.get(ch)) {
        if (ch >= 'А' && ch <= 'Я') {
            ch+=key;
            if(ch > 'Я'){
                ch = ch - 'Я' + 'А' - 1;
            }
        } 
        else if (ch >= 'а' && ch <= 'я') {
            ch+=key;
            if(ch>'я'){
                ch = ch - 'я' + 'а' - 1;
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
        if (ch >= 'а' && ch <= 'я') {
            ch-=key;
            if(ch < 'а'){
                ch = ch +'я' -'а' + 1;
            }
        } else if (ch >= 'А' && ch <= 'Я') {
            ch-=key;
            if(ch<'А'){
                ch = ch + 'Я' - 'А' + 1;
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


    cout<<"Что будем делать:\n 1)Шифровать \n 2)Расшифровывать \n 3)Выход"<< endl;

    while(getline(cin,choice)){

        if(choice == "") continue;

        else if (choice == "1"){ // 

            key = RandomValues(0, 24);

            EncryptCaesar(fileName,programEncrFile,key);

            cout << "Key:" << key << endl;
            cout << "Шифрование успешно произведено." << endl;
            cout << "Вывести сообщение в консоль?" << endl << "[y/n] ";
            while (getline(cin, choice)){
                if (choice == "y"){
                    cout << "Сообщение: " << endl;
                    displayFile(programEncrFile);
                    break;
                } else if (choice == "n"){
                    break;
                }
                else {
                    cout<<"Введите корректную команду"<< endl;
                    continue;
            }
            break;
            cout << endl;
            }

            cout<<"Хотите расшифровать? \n [y/n]  "<<endl;
            while(getline(cin,choice)){
                if(choice == ""){
                    continue;
                }
                else if (choice == "y"){
                    DecryptCaesar(programEncrFile,programOutFile, key);
                    cout <<  "Расшифрова успешно произведена." << endl;
                    cout <<"Вывести сообщение в консоль?" << endl << "[y/n] ";

                        while (getline(cin, choice)){
                            if (choice == "y"){
                                cout <<  "Сообщение: " << endl;
                                displayFile(programOutFile);
                                break;
                            } else if (choice == "n"){
                                break;
                            }
                            else {
                                cout<<"Введите корректную команду"<< endl;
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
                    cout<<"Введите корректную команду"<< endl;
                    continue;
            }

            }
            break;
            cout<<endl;
        }



        else if(choice == "2"){ // 

            DecryptCaesar(fileName,programOutFile, key);
            
            cout << "Key:" << key << endl;

            cout <<"Расшифрова успешно произведена." << endl;
            cout <<"Вывести сообщение в консоль?" << endl << "[y/n] ";

            while (getline(cin, choice)){
                if (choice == "y"){
                    cout << "Сообщение: " << endl;
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
            cout<<"такого выбора нет "<< endl;
            break;
        }


    }
    cout<< endl;
}










