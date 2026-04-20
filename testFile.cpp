
#include <iostream>
#include "httplib.h"

httplib::Server svr;

int main(){
    std::cout << "test2";

    svr.Get("/viewer", [](const httplib::Request &, httplib::Response &res) {res.set_content("LocoViewerLight is being built here", "text/plain");});
    svr.listen("0.0.0.0", 8234);
    std::cout << "test3";
    return 0;
}

