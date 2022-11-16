#include"randinput.h"
#include"getfilename.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> dirname = getfile("./input");
    for(int i=0;i<=dirname.size()-1;i++){
        string curdir="./input/"+dirname[i]; string PATH=curdir+"/stdin_format.txt";
        vector<string>filename=getfile(curdir);
        for(int i=0;i<filename.size();i++){
            for(int j=i+1;j<filename.size();j++){
                bool eq=true;
                string program1="g++ "+curdir+'/'+filename[i];
                string program2="g++ "+curdir+'/'+filename[j];
                for(int k=1;k<=10;k++){
                    int t=rand()%3;
                    srand(time(NULL)+k+t);
                    generate(PATH);
                    system(program1.c_str());
                    system(program2.c_str());
                    system("timeout 0.3s ./a.out <input.txt >ouput1.txt");
                    system("timeout 0.3s ./a.out <input.txt >ouput2.txt");
                    ifstream opt1("output1.txt");
                    ifstream opt2("output2.txt");
                    char check1,check2;
                    while((check1=opt1.get())!=EOF ||(check2=opt2.get())!=EOF ){
                        if(check1!=check2){
                            eq=false;
                            break;
                        }
                    }    
                }
                if(eq){
                    ofstream opt("eq.csv");
                    opt<<program1<<' '<<program2<<endl;
                    opt.close();
                }
                else{
                    ofstream opt("noteq.csv");
                    opt<<program1<<' '<<program2<<endl;
                    opt.close();
                }
            }
        }
    }
    return 0;
}