#include<bits/stdc++.h>
using namespace std;

void optline(){
    ofstream opt("input.txt", ios::trunc);
    opt<<endl;
    opt.close();
}
void singlechar(int endline){
    ofstream opt("input.txt", ios::trunc);
    int capital=rand()%2;
    int character=rand()%26;
    char outputchar;
    if(capital==1)
        outputchar='A'+character;
    else
        outputchar='a'+character;
    opt<<outputchar;
    if(endline==1) opt<<endl;
    opt.close();
}
void singleint(int small, int big){
    ofstream opt("input.txt", ios::trunc);
    if(small>big){
        cout<<"wrong int range!!";
        exit(-1);
    }
    int outputint=small+rand()%(big-small+1);
    opt<<outputint<<endl;
    opt.close();
}
void generate(string PATH){
    string ss;
    ifstream ipt(PATH);
    while(ipt>>ss){
        if(ss[0]=='c') singlechar(1);
         else if (ss[0]=='i'){
            int small, big=0; bool comma=true; int pos1,pos2=1;
            for(int i=4;i<=ss.length()-2;i++){
                if(comma){
                    if(ss[i]==',') comma=false;
                    else if(ss[i]=='-') pos1=-1;
                         else small=small*10+ss[i]-'0';
                }
                else{
                    if(ss[i]=='-') pos2=-1;
                    else big=big*10+ss[i]-'0';
                }
            }
            small*=pos1; big*=pos2;
            singleint(small,big);
         }
         else if(ss[0]=='s'){
            int small, big=0; bool comma=true; 
            for(int i=7;i<=ss.length()-2;i++){
                if(comma){
                    if(ss[i]==',') comma=false;
                    else small=small*10+ss[i]-'0';
                }
                else big=big*10+ss[i]-'0';
            }
            if(small>big){
                    cout<<"wrong string range!!";
                    exit(-1);
            }
            else {
                int strlen;
                strlen=small+rand()%(big-small+1);
            }
            for(int j=1;j<=strlen;j++) singlechar(0);
            optline();
         }
         else{
            cout<<"wrong input format!!";
            exit(-1);
         }
    }
    ipt.close();
    return;
}