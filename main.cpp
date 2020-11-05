/*
@    TITLE:numberConverter.cpp
@  AUTHORS:Kyle Xyian Dilbeck
@     DATE:11/5/20
@FUNCTIONS:This program will convert multiple input numbers to either decimal, binary, octal or hex and may to do so multiple times. 
*/
#include <iostream> 
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <ctype.h>
#include <stack>
#include <limits.h>
#include <unordered_map>
using namespace std;

void decToBinary(int n) { 
    int binaryNum[32]; 
    int i = 0; 
    while (n > 0) { 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
}//end decimal to binary 
void decToOctal(int n){
    int octalNum[100];
    int i = 0;
    while (n != 0) {
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
    // printing octal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << octalNum[j];
}//end decimal to octal 
void decToHexa(int n){    
    char hexaDeciNum[100];   
    int i = 0; 
    while(n!=0){     
        int temp  = 0;  
        temp = n % 16;
        if(temp < 10){ 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else{ 
            hexaDeciNum[i] = temp + 55; 
            i++; 
        } 
        n = n/16; 
    }//END WHILE 
    for(int j=i-1; j>=0; j--)     // printing hexadecimal number array in reverse order 
        cout << hexaDeciNum[j]; 
}//end deca to hex 

int main() {
  int inputNum;
  int convertNum=-1;
  char looper = 'Y'; 
  while(looper == 'Y'){ 
    std::cout <<endl<< "Enter a number to convert or exit(0): ";
    cin >> inputNum;
    if(inputNum == 0){
        cout <<endl<<endl<< "Now exiting...goodbye!";
        break;
        }
    char loopNum = 'Y';
    while(loopNum == 'Y'){
        std::cout <<endl<< "Convert to decimal(1), binary(2), octal(3), hex(4) or exit(0)? ";
        cin >> convertNum ; 
        if(convertNum == 0){break;}
        if(convertNum == 1){
            cout <<endl<< inputNum <<" to decimal ->";
            //
        }
        if(convertNum == 2){
            cout <<endl<< inputNum <<" to binary ->";
            decToBinary(inputNum); 
        }
        if(convertNum == 3){
            cout <<endl<< inputNum <<" to octal ->";
            decToOctal(inputNum); 
        }
        if(convertNum == 4){
            cout <<endl<< inputNum <<" to hex ->";
            decToHexa(inputNum);
        }
        cout << endl<<"Convert " << inputNum << " again(Y/N)? ";
        cin >> loopNum; 
        }//end number loop 
    cout << endl <<"Convert a new numeber(Y/N)? ";
    cin >> looper; 
    if(looper == 'N'){
        cout <<endl<<endl<< "Now exiting...goodbye!";
    }
    
  }//program loop 
}
