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

//*******************DECIMAL CONVERSIONS********************
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
//*******************END DECIMAL CONVERSIONS********************

//*******************BINARY CONVERSIONS************************
int binaryToDecimal(int n){
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}//end binary to decimal 
int convertBinarytoOctal(long long binaryNumber){
    int octalNumber = 0, decimalNumber = 0, i = 0;
    while(binaryNumber != 0){
        decimalNumber += (binaryNumber%10) * pow(2,i);
        ++i;
        binaryNumber/=10;
    }
    i = 1;
    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }
    return octalNumber;
}//end binary to octal 
void binaryToHex(int num){
    int i,temp=0,hexa[20],rem;
    for(i=0;num>0;i++)
    {
        for(int y=0;y<4;y++)
        {
             rem=num%10;
             num/=10;
             temp+=rem*pow(2,y);
       }
       hexa[i]=temp;
       temp=0;
    }
    while(i>0)
    {
        i--;
        if(hexa[i]>9)
            cout<<char(55+hexa[i]);
        else
            cout<<hexa[i];
    }
}
//*******************END BINARY CONVERSIONS********************

//*******************OCTAL CONVERSIONS************************
int octalToDecimal(int octalNumber){
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}//end octal to decimal 
long long convertOctalToBinary(int octalNumber){
    int decimalNumber = 0, i = 0;
    long long binaryNumber = 0;
    while(octalNumber != 0){
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }
    i = 1;
    while (decimalNumber != 0){
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }
    return binaryNumber;
}//end octal to binary 
//*******************END OCTAL CONVERSIONS********************

//*******************HEX CONVERSIONS************************
int hexadecimalToDecimal(char hexVal[]) {    
    int len = strlen(hexVal); 
    int base = 1; 
    int dec_val = 0; 
    for (int i=len-1; i>=0; i--) {    
        if (hexVal[i]>='0' && hexVal[i]<='9') { 
            dec_val += (hexVal[i] - 48)*base;  
            base = base * 16; 
        } 
        else if (hexVal[i]>='A' && hexVal[i]<='F') { 
            dec_val += (hexVal[i] - 55)*base; 
            base = base*16; 
        } 
    } 
    return dec_val; 
} //end hex to decimal
//*******************END HEX CONVERSIONS********************
int main() {
  int inputNum, numType;
  int convertNum=-1;
  char looper = 'Y'; 
  while(looper == 'Y'){ 
    cout << endl<< "What type of number would you like to convert?"
    <<endl << "decimal(1), binary(2), octal(3) or hex(4)? ";
    cin >> numType; 
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
            if(numType == 1){
                cout <<endl<< inputNum << " in decimal to decimal -> " << inputNum; 
            }
            if(numType == 2){
                cout <<endl<< inputNum << " in binary to decimal -> " << binaryToDecimal(inputNum); 
            }
            if(numType == 3){
                cout <<endl<< inputNum << " in octal to decimal -> " << octalToDecimal(inputNum);
            }
            if(numType == 4){
                cout <<endl<< "(not implimented)";
                //must add cases or string conversion for hexa 
                //cout <<endl<< inputNum << " in hex to decimal -> " << hexadecimalToDecimal(hexa);
            }
        }
        if(convertNum == 2){
            if(numType == 1){
                cout <<endl<< inputNum << " in decimal to binary -> "; 
                decToBinary(inputNum);
            }
            if(numType == 2){
                cout <<endl<< inputNum << " in binary to binary -> " << inputNum; 
            }
            if(numType == 3){
                cout <<endl<< inputNum << " in octal to binary -> " ;
                convertOctalToBinary(inputNum); 
            }
            if(numType == 4){
                cout <<endl<< "(not implimented)";
                //must add cases or string conversion for hexa 
                //cout <<endl<< inputNum << " in hex to binary -> " << hexadecimalToDecimal(hexa);
            } 
        }
        if(convertNum == 3){ 
            if(numType == 1){
                cout <<endl<< inputNum << " in decimal to octal -> ";
                decToOctal(inputNum); 
                
            }
            if(numType == 2){
                int fill = convertBinarytoOctal(inputNum);
                cout <<endl<< inputNum << " in binary to octal -> "<<fill; 
                 
            }
            if(numType == 3){
                cout <<endl<< inputNum << " in octal to octal -> " << inputNum;
            }
            if(numType == 4){
                cout <<endl<< "(not implimented)";
                //must add cases or string conversion for hexa 
                //cout <<endl<< inputNum << " in hex to octal -> " << hexadecimalToDecimal(hexa);
            } 
        }
        if(convertNum == 4){
            if(numType == 1){
                cout <<endl<< inputNum << " in decimal to hex -> ";
                decToHexa(inputNum); 
            }
            if(numType == 2){
                cout <<endl<< inputNum << " in binary to hex -> " << inputNum; 
                binaryToHex(inputNum); 
            }
            if(numType == 3){
                cout <<endl<< inputNum << " in octal to hex -> (not implimented)" << inputNum;
                
            }
            if(numType == 4){
                //must add cases or string conversion for hexa 
                cout <<endl<< inputNum << " in hex to hex -> " << inputNum;
            } 
        }
        cout << endl<<"Convert " << inputNum << " again(Y/N)? ";
        cin >> loopNum; 
        }//end number loop 
    cout << endl <<"Convert a new numeber(Y/N)? ";
    cin >> looper; 
    if(looper == 'N'){
        cout <<endl<<endl<< "Now exiting...goodbye!"<<endl<<endl;
    }
    
  }//program loop 
}
