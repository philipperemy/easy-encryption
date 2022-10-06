# Easy Encryption
A very simple standalone C++ module (API) to obfuscate/deobfuscate strings based on B64 and Vigenere ciper (symmetric cipher).

**DISCLAIMER: This encryption is NOT secure and can be used as a "cheap way" to obfuscate some messages in a communication channel. If you need a solid and unbreakable encryption, please use a widely adopted standard and well researched cipher like AES-GCM.** You can find more information there: [pyca](https://github.com/pyca/cryptography).


It works as follows:

- Alice encodes in base64 the message, then uses the Vigenere private key to encrypt the message.
- The encrypted message is sent through an unsecured channel.
- Bob gets the message and decrypts it with the Vigenere private key. He then decodes it with base64.

Diagram summary:
_______________________________________________________________________________________________________________
**Message -> B64 ENCODE -> VIGENERE ENCRYPT -> encrypted message -> VIGENERE DECRYPT -> B64 DECODE -> Message**
_______________________________________________________________________________________________________________

The reason why we apply b64 encode BEFORE Vigenere is because it's very easy for somebody to apply a b64 decode and see about the structure of the message. For example, if we send `{"hello":123}`, an attacker can sniff the message, b64 decode the message and get `{"qsggn":ygf}`. Of course the attacker still needs the Vigenere cipher key, but at least, he can get a pretty clear idea that JSON format messages are sent in the communication channel. The way to avoid this is to encode first in b64 then encrypt it with the Vigenere key. If the attacker tries to b64 decode first, it will see a random string of weird characters.

## API

### C++

- **Encrypt message**
```c++
std::string encrypt(std::string& msg, std::string& key)
```

- **Decrypt message**
```c++
std::string decrypt(std::string& encrypted_msg, std::string& key)
```

### Python

- **Encrypt message**
```python
wrapper.encrypt(message, key): returns encrypted message
```

- **Decrypt message**
```python
wrapper.decrypt(encrypted_message, key): returns decrypted message
```

## Compilation and execution
```bash
g++ cl.cpp Base64.cpp
./a.out "Hello world" MYPRIVATEKEY 0
```

The encrypted message is: `ttz9JqxZHBClNtu=`.

```bash
./a.out ttz9JqxZHBClNtu= MYPRIVATEKEY 1
```

The decrypted message is `Hello world`.

## Python wrapper

```bash
g++ cl.cpp Base64.cpp
python3 wrapper.py
```

## Example - Encoding/Decoding JSON format

### Source code
```c++
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "encrypt.h"

using namespace std;

int main() {
 	// std::string msg = "HELLO WORLD";
 	std::string msg = "{\"id\":1,\"method\":\"service.subscribe\",\"params\":[\"myapp/0.1c\", null,\"0.0.0.0\",\"80\"]}";
 	std::string key = "THISISMYKEY";
 	std::cout << "  message to send: " << msg << std::endl;
 	std::string encrypted_msg = encrypt(msg, key);
 	std::cout << "encrypted message: " << encrypted_msg << std::endl;
 	std::string decrypted_msg = decrypt(encrypted_msg, key);
 	std::cout << "decrypted message: " << decrypted_msg << std::endl;
    return 0;
}
```

### Output
```
  message to send: {"id":1,"method":"service.subscribe","params":["myapp/0.1c", null,"0.0.0.0","80"]}
encrypted message: X5g7wjjTllj1ItCxShWUb77PKJsfP VNMAB7VtqaLCccGTr0ijkjxqw0IutQvXfSFK4OKo8cnpD1Lge0pdMCZf0fqQ8bjjFjkNn1h pBtdwNJD==
decrypted message: {"id":1,"method":"service.subscribe","params":["myapp/0.1c", null,"0.0.0.0","80"]}
```
