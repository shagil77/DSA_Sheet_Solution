#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

string intToRoman(int A) {
    string s="";
    int num=A;
    while(num>0) {
        if(num>=1 && num<=4) {
            if(num==4) {
                s+="IV";
                num-=4;
            }
            else {
                int i=num/1;
                while(i--) s+="I";
                num=num%1;
            }
        }
        else if(num>=5 && num<=9) {
            if(num==9) {
                s+="IX";
                num-=9;
            }
            else {
                s+="V";
                num-=5;
            }
        }
        else if(num>=10 && num<=40) {
            if(num==40) {
                s+="XL";
                num-=40;
            }
            else {
                int i=num/10;
                while(i--) s+="X";
                num=num%10;
            }
        }
        else if(num>=41 && num<=50) {
            if(num==50) {
                s+="L";
                num-=50;
            }
            else {
                s+="XL";
                num-=40;
            }
        }
        else if(num>=51 && num<=90) {
            if(num==90) {
                s+="XC";
                num-=90;
            }
            else {
                s+="L";
                num-=50;
            }
        }
        else if(num>=91 && num<=100) {
            if(num==100) {
                s+="C";
                num-=100;
            }
            else {
                s+="XC";
                num-=90;
            }
        }
        else if(num>=101 && num<=400) {
            if(num==400) {
                s+="CD";
                num-=400;
            }
            else {
                s+="C";
                num-=100;
            }
        }
        else if(num>=401 && num<=500) {
            if(num==500) {
                s+="D";
                num-=500;
            }
            else {
                s+="CD";
                num-=400;
            }
        }
        else if(num>=501 && num<=900) {
            if(num==900) {
                s+="CM";
                num-=900;
            }
            else {
                num-=500;
                s+="D";
            }
        }
        else if(num>=901 && num<=1000) {
            if(num==1000) {
                s+="M";
                num-=1000;
            }
            else {
                num-=900;
                s+="CM";
            }

        }
        else {
            int i=num/1000;
            while(i--) s+="M";
            num=num%1000;
        }
    }
    return s;
}

int main()
{
    cout<<intToRoman(47);

    return 0;
}