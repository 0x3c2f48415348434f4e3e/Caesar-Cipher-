//our main file
//#include <iostream>
#include "File.h"
#include <stdlib.h>
#include <filesystem>
#include <map>

/*
std::string treatString(const std::string & filePath){ //our helper function
    std::string treatedString = "";
    for(int i=0; i<filePath.size(); i++){
        //check for space, and if space exist, continue, else apped charcater to new string
        if(filePath[i] == ' '){
            continue;
        }
        else{
            treatedString += filePath[i];
        }
    }

    return treatedString;
}*/


std::string getFileExtenstion(std::string temp){
    std::string res = "";
    //get the position of the period
    int pos = 0;
    for(int i=0; i<temp.size(); i++){
        if(temp[i] == '.'){
            pos = i;
            break;
        }
    }

    res = temp.substr(pos + 1,temp.size()-1);

    return res;
}

//for now, lets only support txt files
std::map<std::string,int> supportedFiles;


int main(int argc,char* argv[]){
    //char *filePATH = (char*) malloc(100*sizeof(char));
    supportedFiles.insert({"txt",0});
    supportedFiles.insert({"docx",1});
    std::string* filePath = new std::string();
    printf("Specify the location of your file: \n");
    /*
    //scanf("%s",filePath); //assuming user string does not contain space (Will fix that later)
    */
    std::cin >> *filePath;
    //std::cout << *filePath << std::endl;


    std::filesystem::path myPath = *filePath;
    

   //first we are going to check if the given file exists
    if(std::filesystem::exists(myPath) > 0){ //looks like exists can check for both file and directories
        std::cout << "The given path " <<  *filePath << " exists" << std::endl;
    }
    else{
        std::cout << "The given path " <<  *filePath << " could not be found";
        exit(EXIT_FAILURE);
    }

    //Here i will check if it is a directory and if true, we exit (No direcoties allowed)
    std::string extension = getFileExtenstion(myPath.filename().generic_string());
    //convert from path to string 
    //https://stackoverflow.com/questions/45401822/how-to-convert-filesystem-path-to-string
    
    std::cout << myPath.filename().generic_string() << std::endl;

    //lets see if this file extension is dupported in our hashmap
    if(supportedFiles.find(extension) != supportedFiles.end()){
        printf("File extension is supported");
    }
    else{
        printf("File extension not supported");
        exit(EXIT_FAILURE);
    }

    //create our class

    file newFile(myPath.filename().generic_string(),myPath.generic_string());
    //std::cout << newFile.getName() << std::endl;
    newFile.encryptFile();


}
//C:\Users\benja\Downloads\Future Me.png
//C:\Users\benja\Downloads\Bloomberg.docx"
//C:\Users\benja\Desktop\new.txt