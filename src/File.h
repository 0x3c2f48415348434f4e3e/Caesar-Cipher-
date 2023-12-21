#include <iostream>
class file{
private:
    std::string Name;
    std::string Path;
    //int size; leave this sectionlater as it shard
    int shift;

public:
    file(const std::string &fileName, const std::string &Path);
    std::string getName();
    std::string getPath();
    int getShift();

    //int getSize(const std::string & fileName);
    void encryptFile();
};