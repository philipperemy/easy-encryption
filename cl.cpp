#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "encrypt.h"

using namespace std;

int main(int argc, char** argv) {

    if(argc != 4) {
        std::cout << "Usage: ./a.out message key (0:encrypt|1:decrypt)" << std::endl;
        std::cout << "./a.out \"Hello world\" MYPRIVATEKEY 0" << std::endl;
        std::cout << "./a.out ttz9JqxZHBClNtu= MYPRIVATEKEY 1" << std::endl;
        return -1;
    }

 	std::string msg = argv[1];
 	std::string key = argv[2];
 	int encrypt_flag = atoi(argv[3]);

 	if(encrypt_flag == 0) {
 	    std::cout << encrypt(msg, key) << std::endl;
 	} else {
 	    std::cout << decrypt(msg, key) << std::endl;
 	}

    return 0;
}
