#include <bits/stdc++.h>

using namespace std;

int binaryToDecimal(int);
int octalToDecimal(int);
int hexToDecimal(string);
int decimalToBinary(int);
int decimalToOctal(int);
string decimalToHex(int);

int main()
{
    int choice;
    cout<< "1.Binary to Decimal \n2.Octal to Decimal\n3.Hex to Decimal \n4.Decimal to Other\n";
    cin>>choice;

    int num;
    string s;
    cout<<"\nInput Number : ";

    switch (choice){
    case 1: cin>>num;
            cout<<binaryToDecimal(num);
            break;
    case 2: cin>>num;
            cout<<octalToDecimal(num);
            break;
    case 3: cin>>s;
            cout<<hexToDecimal(s);
            break;
    case 4: cin>>num;
            cout<<"Binary : "<<decimalToBinary(num);
            cout<<"\nOctal : "<<decimalToOctal(num);
            cout<<"\nHex : "<<decimalToHex(num); 
    }
}

int octalToDecimal(int oNum){
    int dNum=0;
    int c=1;
    while(oNum){
        dNum += (oNum %10)*c;
        c *= 8;
        oNum /= 10;
    }
    return dNum;
}

int binaryToDecimal(int bNum){
    int dNum=0;
    int c=1;
    while(bNum){
        dNum += (bNum %10)*c;
        c *= 2;
        bNum /= 10;
    }
    return dNum;
}

int hexToDecimal(string hexNumber)
{
    int decimalNumber=0;
    int c=1;

    for(int i=hexNumber.length()-1;i>=0;i--){
        if(hexNumber[i]>='0' && hexNumber[i]<='9'){
            decimalNumber += (hexNumber[i]-'0')*c;
        }
        else if(hexNumber[i]>='A'&& hexNumber[i]<='F'){
            decimalNumber += (hexNumber[i]-'A'+10)*c;    
        }
        c *= 16;
    }
    
    return decimalNumber;
}

string decimalToHex(int dNum){
    string hNum = "";
    
    int c=1;
    while(c<=dNum){
        c *= 16;
    }
    c/=16;
    int lastDigit;
    char lastHex;
    while(c){
        lastDigit = dNum/c;
        if(lastDigit<10){
            lastHex = lastDigit + '0';
        }
        else{
            lastHex = lastDigit - 10 + 'A'; 
        }
        hNum.push_back(lastHex);
        dNum -=   lastDigit*c;
        c /= 16;
    }
    
    return hNum;
}

int decimalToOctal(int dNum){
    int oNum=0;
    
        int c=1;
        while(c<=dNum){
            c *= 8;
        }
        c/=8;
        int lastDigit;
        while(c){
            lastDigit = dNum/c;
            oNum = oNum*10 + lastDigit;
            dNum -=   lastDigit*c;
            c /= 8;
        }
    
    return oNum;
}

int decimalToBinary(int dNum){
    int bNum=0;
    
        int c=1;
        while(c<=dNum){
            c *= 2;
        }
        c/=2;
        int lastDigit;
        while(c){
            lastDigit = dNum/c;
            bNum = bNum*10 + lastDigit;
            dNum -=   lastDigit*c;
            c /= 2;
        }
    
    return bNum;
}





