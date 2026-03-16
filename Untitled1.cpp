#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void showMenu () {
	cout<<"1-Encrypt File \n";
	cout<<"2-Decrypt File \n";
	cout<<"3-Exit \n";	
}
void EncryptFile()
{
    string inputfile, outputfile;
    cout << "Enter Input File Name: ";
    cin >> inputfile;
    cout << "Enter Output File Name: ";
    cin >> outputfile;
    ifstream inFile(inputfile);
    if(!inFile){
        cout << "Error opening input file!\n";
        return;
    }
    ofstream outFile(outputfile);
    string line;
    cout << "\nOriginal Text -> Encrypted Text\n";
    while(getline(inFile, line)){
    	 string encrypted = line;

        for(int i = 0; i < encrypted.length(); i++){
           encrypted[i] = encrypted[i] + 3;   //Caesar cipher encryption
        }
        cout << line << " -> " << encrypted << endl;
	    outFile << encrypted << endl;
    }
    cout << "File encrypted successfully!\n";
}
void DecryptFile(){
	string inputfile,outputfile;
	cout << "Enter Input File Name: ";
    cin >> inputfile;
    cout << "Enter Output File Name: ";
    cin >> outputfile;
    ifstream inFile(inputfile);
    if(!inFile){
        cout << "Error opening input file!\n";
        return;
    }
    ofstream outFile(outputfile);
    string line;
    cout << "\nEncrypted Text -> Decrypted Text\n";
    while(getline(inFile, line)){
    	 string decrypted = line;

        for(int i = 0; i < decrypted.length(); i++){
            decrypted[i] = decrypted[i] - 3;   
        }
        cout << line << " -> " << decrypted << endl;
	    outFile << decrypted << endl;
    }
    cout << "File Decrypted successfully!\n";
}

int main (){
	int choice ;
	while (true) {
		showMenu ();
		cout<<"Enter your choice (1-3)";
		cin>>choice;
		switch ( choice ) {
			case 1 : 
			EncryptFile ();
			break;
			case 2 : 
			DecryptFile ();
			break;
			case 3 : 
			cout<<"Program End..\n";
			return 0;
			default: 
			cout <<"Invalid choice , choose from ( 1-3 )";
		}
	}
}
	
	

