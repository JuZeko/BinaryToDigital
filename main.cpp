#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void convertToDigital(int number,int numbersPowerOfTwo[]){

    string nu;
    cout<<"Enter a binary number ";  cin >> nu;
    int suma = 0;

    for(int i =nu.length()-1;i>=0;i--){


        if( nu.at(i) == '1'){
            suma += numbersPowerOfTwo[i+1];
        }
   }
    cout<<suma<<endl;

}
void convertToBinary(int number,int numbersPowerOfTwo[],int numberInBites[]){

    cout<<"Enter number ";    cin>>number;
    int i = 0;

    while(number != 0){

        if(numbersPowerOfTwo[i]>number){
            number -= numbersPowerOfTwo[i-1];
            numberInBites[i]+=1;
            i=0;
        }
        else{
            i++;
        }
    }
}

void reverseArray(int numberInBites[]){
    for(int i=0;i<5;i++){
        int dummyNumber = numberInBites[10-i];
        numberInBites[10-i] = numberInBites[i];
        numberInBites[i] = dummyNumber;
    }
}

void showBinaryNumber(int numberInBites[]){

    cout<<"Your number in binary is ";
    for(int i =0;i<10;i++){
        cout<< numberInBites[i];
       }
}



void menu(int number,int numbersPowerOfTwo[],int numberInBites[]){

    int numberOfChoise;
    cout<<"Hello this is Jules app which converts digital numbers to binary and vice verca"<<endl;;
    cout<<"If you want to convert digital number to binary press 1 "<<endl;
    cout<<"If you want to convert binary number to digital press 2 "<<endl;
    cin>>numberOfChoise;

    if(numberOfChoise == 1){
        convertToBinary(number,numbersPowerOfTwo,numberInBites);
        reverseArray(numberInBites);
        showBinaryNumber(numberInBites);
    }
    if(numberOfChoise == 2){
       convertToDigital(number,numbersPowerOfTwo);

    }
}

int main()
{
    int number;

    int numbersPowerOfTwo[11] = {1,2,4,8,16,32,64,128,256,512,1024};
    int numberInBites[11] = {0,0,0,0,0,0,0,0,0,0,0};


    menu(number,numbersPowerOfTwo,numberInBites);

    cout<<" " <<endl;
    return 0;
}
