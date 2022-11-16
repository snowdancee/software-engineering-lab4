#include<dirent.h>
#include<bits/stdc++.h>
using namespace std;
vector<string> getfile(string PATH)
{
    struct dirent *ptr;    
    DIR *dir;
    dir=opendir(PATH.c_str()); 
    vector<string> files;
    while((ptr=readdir(dir))!=NULL)
    {
        if(ptr->d_name[0] == '.')
            continue;
        files.push_back(ptr->d_name);
    }
    
    for (int i = 0; i < files.size(); ++i)
    {
        cout << files[i] << endl;
    }
    closedir(dir);
    return files;
}
//参考资料：https://blog.csdn.net/adong76/article/details/39432467