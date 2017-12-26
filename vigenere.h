#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

std::string extend_key(std::string& msg, std::string& key) {
	//generating new key
	int msgLen = msg.size();
	std::string newKey(msgLen, 'x');
	int keyLen = key.size(), i, j;
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
	return newKey;
}


std::string encrypt_vigenere(std::string& msg, std::string& key) {
	int msgLen = msg.size(), keyLen = key.size(), i, j;
 	std::string encryptedMsg(msgLen, 'x');
    // char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 
	std::string newKey = extend_key(msg, key);
 
    //encryption
    for(i = 0; i < msgLen; ++i) {
    	// std::cout << msg[i] << " " << isalnum(msg[i]) << std::endl;
    	if(isalnum(msg[i])) {
    		encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    	} else {
    		encryptedMsg[i] = msg[i];
    	}
    }
	
    encryptedMsg[i] = '\0';
    return encryptedMsg; 
}

std::string decrypt_vigenere(std::string& encryptedMsg, std::string& newKey) {
	// decryption
	int msgLen = encryptedMsg.size();
	std::string decryptedMsg(msgLen, 'x');
	int i;
    for(i = 0; i < msgLen; ++i) {
    	if(isalnum(encryptedMsg[i])) {
    		decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    	} else {
    		decryptedMsg[i] = encryptedMsg[i];
    	}
    }
    decryptedMsg[i] = '\0';
	return decryptedMsg;
}

