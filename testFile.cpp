
#include <iostream>
#include "httplib.h"
#include <fstream>

httplib::Server svr;

int main(){
    std::cout << "test5";
    
    
    svr.Get("/viewer", [](const httplib::Request &, httplib::Response &res) {
        std::string dataFileName = "testTable.csv";
        std::ifstream contentFile;
    
        contentFile.open(dataFileName);
        if(!contentFile){
            std::cout << "Datei nicht geöffnet:" << dataFileName;
        }

        
        
        std::string fileContent;
        char fileChar;
        

        while (contentFile.get(fileChar)){
            fileContent += fileChar;
        }

        if (contentFile.is_open()){
            contentFile.close();
        }    
        res.set_content(fileContent, "text/plain");
    });
    svr.listen("0.0.0.0", 8234);
    std::cout << "test3";
    return 0;
}

