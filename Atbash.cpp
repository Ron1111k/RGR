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
                serr << "Не удалось открыть файл.";
                throw runtime_error(serr.str());
    }


    while (input.get(ch)) { 

        if (ch >= 'а' && ch <= 'я'){  
            ch= 'я' - ( ch - 'а' ); 
        }

        else if (ch >= 'А' && ch <= 'Я'){
            ch = 'Я' - ( ch - 'А' ); 
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


    cout<<"Что будем делать:\n 1)Шифровать \n 2)Расшифровывать \n 3)Выход"<< endl;

    while(getline(cin,choice)){

        if(choice == "") continue;

        else if (choice == "1"){ // шифруем

             atbashEncrypt(fileName,programEncrFile);

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

            cout<<"Хотите расшифровать? \n 1)Да \n 2) Нет "<<endl;
            while(getline(cin,choice)){
                if(choice == ""){
                    continue;
                }
                else if (choice == "1"){
                    atbashEncrypt(programEncrFile,programOutFile);
                    cout << "Расшифрова успешно произведена." << endl;
                    cout << "Вывести сообщение в консоль?" << endl << "[y/n] ";

                        while (getline(cin, choice)){
                            if (choice == "y"){
                                cout << "Сообщение: " << endl;
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

                else if(choice == "2") {
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



        else if(choice == "2"){ // расшифровываем
            atbashEncrypt(fileName,programOutFile);
            

            cout << "Расшифрова успешно произведена." << endl;
            cout << "Вывести сообщение в консоль?" << endl << "[y/n] ";

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
