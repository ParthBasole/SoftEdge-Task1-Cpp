#include<iostream>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include <map>
#include <unistd.h>
#include <errno.h> 
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
using namespace std;

class FileDict
{
public : 

    static void funct(char Fname[])
    {   map<string,int> MaP;    
        int fd=open(Fname,O_RDWR);
        char c;
        if(fd==-1)
        {
            return; 
        }
        string str="";
        while(read(fd,&c,1))
        {
            str.push_back(c);
                if((c==' ')||(c=='\n'))
                { str.pop_back();
                //cout<<str;
                MaP[str]++;
                    str="";
                }
        } 
        MaP[str]++;
        FileDict::printMap(MaP);
    }



    static void  printMap(map<string,int> &MaP)
    {map<string, int>::iterator itr;
    for (itr = MaP.begin(); itr != MaP.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    }
};





int main (int argc,char * argv[])
{ FileDict::funct(argv[1]);

 return 0;    
}
