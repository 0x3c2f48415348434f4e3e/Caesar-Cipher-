#include "File.h"
#include <fstream>
#include <map>
//#include <iostream>


//our hashmap
std::map<int, char> uppercase{
    {1,'A'},
    {2,'B'},
    {3,'C'},
    {4,'D'},
    {5,'E'},
    {6,'F'},
    {7,'G'},
    {8,'H'},
    {9,'I'},
    {10,'J'},
    {11,'K'},
    {12,'L'},
    {13,'M'},
    {14,'N'},
    {15,'O'},
    {16,'P'},
    {17,'Q'},
    {18,'R'},
    {19,'S'},
    {20,'T'},
    {21,'U'},
    {22,'V'},
    {23,'W'},
    {24,'X'},
    {25,'Y'},
    {26,'Z'},
};


std::map<int,char> lowercase{
    {1,'a'},
    {2,'b'},
    {3,'c'},
    {4,'d'},
    {5,'e'},
    {6,'f'},
    {7,'g'},
    {8,'g'},
    {9,'i'},
    {10,'j'},
    {11,'k'},
    {12,'l'},
    {13,'m'},
    {14,'n'},
    {15,'o'},
    {16,'p'},
    {17,'q'},
    {18,'r'},
    {19,'s'},
    {20,'t'},
    {21,'u'},
    {22,'v'},
    {23,'w'},
    {24,'x'},
    {25,'y'},
    {26,'z'},
};

//using namespace std;
file::file(const std::string &fileName, const std::string &Path) {
    this->Name = fileName;
    this->Path = Path;

    //lets get a random shift
    srand(time(0));
    this->shift = rand();
}

std::string file::getName() {
    return this->Name;
}

std::string file::getPath() {
    return this->Path;
}

int file::getShift(){
    return this->shift;
}

void file::encryptFile() {
    // Going to first read the file
    std::string content;
    std::ifstream myfile (this->Path);
    if (myfile.is_open())
    {
        while (std::getline (myfile,content))
        {
            //std::cout << content << '\n';
            continue;
        }

        //std::cout << std::endl << content <<std::endl;
        std::map<int,char>::iterator itr;
        std::string res = "";
        //check if upper case or lower case
        for(int i=0; i<content.size(); i++){
            if(isupper(content[i])){
                //do stuff for the upper
                for(itr = uppercase.begin(); itr != uppercase.end(); itr++){
                    if(itr->second == content[i]){
                        res += uppercase[(itr->first+this->shift)%26];
                    }
                }
            }
            else{
                // is not upper, do stuff for lower
                for(itr = lowercase.begin(); itr != lowercase.end(); itr++){
                    if(itr->second == content[i]){
                        res += lowercase[(itr->first+this->shift)%26];
                    }
                }
            }
        }
            //find the letter in either the uppercase or lowercase

        std::cout<<res<<std::endl;
        //time for our encryption
        myfile.close();
    }
    else{
        std::cout << "\nUnable to open file" << this->Name; 
        exit(EXIT_FAILURE);
    }


}