#include"RGR.h"

// ������� ��������� �������� 
char Checking(char ch){
    if(ch>='�' && ch<='�'){
        ch+=32;
    }
    else ch = tolower(ch);

    return ch;
}



vector<int> makeBigram(string fileName,vector<int> index,char matrix[8][8],bool isEnc = true){
    
    ifstream in;
    char ch;


    in.open(fileName);

    string bigram = "";

    //�������� ������� 
    while(in.get(ch)){
        if((ch>='a' && ch<='z')|| (ch>='�' && ch<='�') || (ch>='A' && ch <= 'Z' ) || (ch>= '�' && ch <= '�') ){
            ch = Checking(ch);   
            bigram += ch ;
        }
    }
   
  
    if(isEnc){
        // ��������� ������������ � �������
        for(int i = 0 ; i<bigram.length();i++){
            if(bigram[i] == bigram[i+1]) {
                bigram.insert(i+1,1,'$');
                i++;
            }
        }
        //���������� x � �������� �������� 
        if(bigram.length() % 2 != 0)bigram.push_back('$');
    }

   

    //�������� �������
    for(int i = 0;i < bigram.length(); i+=2 ){
        cout<<bigram[i]<<bigram[i+1]<<"  ";
    }
    cout<< endl;

    //���������� ������� �������
    
    for(int i = 0; i < bigram.length(); i++){
        for( int j = 0; j < 8; j++){
            for( int k = 0; k < 8;k++){
                if(bigram[i] == matrix[j][k]){
                    index.push_back(j);
                    index.push_back(k);
                }
            }
        }
    }
    in.close();
  
    return index;
}



void Encode(vector<int> index , char matrix[8][8], string &programOutFile ){

    int a = 0 , b = 0;

    ofstream out;

    out.open(programOutFile);

    for(int i = 0 ; i < index.size() - 3 ; i+=4  ){

        a = index[i + 3] + 1;
        // ���� �� ����� ������
        if(index[i] == index[i+2] &&(index[i+1]+1<8 || a < 8)){
            out << matrix[index[i]][index[i+1]+1] << matrix[index[i+2]][a];
        }

        //���� �� ����� ������ � � ���� 
        if(index[i] == index[i+2] && (index[i+1]+1>=8 || a>=8)){
            a = 0;
            if(index[i+1]+1 >= 8){
                out<<matrix[index[i]][a]<<matrix[index[i+2]][index[i+3]+1];
            }
            else {
                out<<matrix[index[i]][index[i+1]+1]<<matrix[index[i+2]][a];
            }
        }

        //���� � ����� ������� 
        b = index[i + 2] + 1;

        if(index[i+1] == index[i+3] && (index[i]+1<8 || b<8)){
            out<< matrix[index[i]+1][index[i+1]]<< matrix[b][index[i+3]];
        }


        //���� � ����� ������� � � ����
         if(index[i+1] == index[i+3] && (index[i]+1>=8|| b>=8)){
            b = 0;
            if(index[i]+1>=8){
                out<< matrix[b][index[i+1]] << matrix[index[i+2] + 1][index[i+3]];
            }
            else out<< matrix[index[i]+1][index[i+1]] << matrix[b][index[i+3]];
        }

        //����������� ������ 
        if ( index[i] != index[i+2] && index[i+1] != index[i+3] ){
            out<< matrix[index[i]][index[i+3]]<< matrix[index[i+2] ][index[ i + 1] ];
        } 
    }
    out.close();
}

void Decode(vector<int> index , char matrix[8][8], string &programOutFile,string &DecFile ){
    int a = 0 , b = 0;
    char ch;
    string result = "";
    ifstream in;
    ofstream out;
    ofstream outno$;

    out.open(programOutFile);

     for(int i = 0 ; i < index.size() - 3  ; i += 4  ){
        

        a = index[i+3] - 1;
        //���� �� ����� ������ 
        if(index[i] == index[i+2] && (index[i+1] - 1 >= 0 || a >= 0)){
            out<<matrix[index[i]][index[i+1]-1]<<matrix[index[i+2]][a];
        }

        //���� � ����� �������
        b = index[i+2] - 1;
        if(index[i+1] == index[i+3] && (index[i]-1 >= 0 || b >= 0)){
            out << matrix[index[i] - 1][index[i+1]]<<matrix[b][index[i+3]];
        } 

         //���� � ����� ������� � � ����
        if(index[i+1] == index[i+3] && (index[i]-1 < 0 || b < 0)){
            b = 7;
            if(index[i]-1 < 0){
                out<< matrix[b][index[i+1]]<< matrix[index[i+2]-1][index[i+3]]  ;
            }
            else out<< matrix[index[i] - 1][index[i+1]]<< matrix[b][index[i+3]]  ;
        } 

        //���� �� ����� ������ � � ����
        if(index[i] == index[i+2] && (index[i+1]-1 < 0 || a < 0)){
            a = 7;
            if(index[i+1] - 1 < 0){
                out<<matrix[index[i]][a]<<matrix[index[i+2]][index[i+3]-1];
            }
            else out<<matrix[index[i]][index[i+1]-1]<<matrix[index[i+2]][a];
        }


        //����������� ������ 
        if ( index[i] != index[i+2] && index[i+1] != index[i+3] ){
            out<< matrix[index[i]][index[i+3]]<< matrix[index[i+2] ][index[ i + 1] ];
        } 
    }
    out.close();

    in.open(programOutFile);
    outno$.open(DecFile);

    while(in.get(ch)){
        if (ch != '$') {
            outno$<<ch;
        }  
    }
    in.close();
    outno$.close();

}



void PlayFair(string &fileName, string &programEncrFile, string &programOutFile,string &DecFile){
    vector<int> index;
    char matrix[8][8];
    string key;
    string alphabet = "abcdefghijklmnopqrstuvwxyz�����������������������������$?,. !:\n";
    int q = 0;

    //���� ����� 
    cout << "������� ����: " << endl;
    while(q == 0){
    cin >> key ;
                
    //�������� �� ������� �������
    for(int i = 0; i < key.length();i++){
        if(isupper(key[i]) || (key[i]>='�' && key[i]<='�')) key[i] = Checking(key[i]);
    }

    //�������� �� ����������� ������� 
    for(auto i:key){
        if(isalpha(i) || (i >= '�' && i <='�') ) q = 1;
        else {
            cout<<"���� ������ �������� ������ �� ����"<<endl;
            q = 0 ;
            break;
        }
    }
    
    }

    //�������� ������������
    for(int i = 0; i < key.length();i++){
        for (int j = i+1; j < key.length(); j++){
            if(key[i] == key[j]){
            key.erase(j,1);
            j -- ;
            }
        }
    }

    //�������� ���� ����� �� ��������
    for(int i = 0; i < key.length();i++){
        for(int j = 0; j < alphabet.length();j++){
            if(key[i] == alphabet[j]) alphabet.erase(j,1);
        }
    }

    //���� ������ � ������
    cout<<"���� �������:"<< endl;
    int k = 0 , m = 0 ;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8;j++){
            if(k < key.length()){
                matrix[i][j] = key[k];
            }
            if(k>= key.length()){
                matrix[i][j] = alphabet[m];
                m++;
            }
            k++;
        }
    }

    // ����� �������
    for(int i = 0; i < 8; i++ ){
        for(int j = 0; j < 8;j++){
            cout << matrix[i][j]<<" "; 
        }
        cout<< endl;
    }


    string choice;

    cout<<"��� ����� ������:\n 1)��������� \n 2)�������������� \n 3)�����"<< endl;

    while(getline(cin,choice)){

        if(choice == "") continue;

        else if (choice == "1"){ // �������

            index = makeBigram(fileName,index,matrix);

            Encode(index,matrix,programEncrFile);

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

            cout<<"������ ������������? \n 1)�� \n 2) ��� "<<endl;
            while(getline(cin,choice)){
                if(choice == ""){
                    continue;
                }
                else if (choice == "1"){
                    index.clear();
                    index = makeBigram(programEncrFile,index,matrix,false); 
                    Decode(index,matrix,programOutFile,DecFile);
                    cout << "���������� ������� �����������." << endl;
                    cout << "������� ��������� � �������?" << endl << "[y/n] ";

                        while (getline(cin, choice)){
                            if (choice == "y"){
                                cout << "���������: " << endl;
                                displayFile(DecFile);
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

            index = makeBigram(fileName,index,matrix,false); 
            Decode(index,matrix,programOutFile,DecFile);
            
            cout << "Key:" << key << endl;

            cout << "���������� ������� �����������.\n" << endl;
            cout << "������� ��������� � �������?" << endl << "[y/n] ";

            while (getline(cin, choice)){
                if (choice == "y"){
                    cout << "���������:\n " << endl;
                    displayFile(DecFile);
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