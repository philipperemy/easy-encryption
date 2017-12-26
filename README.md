# Easy Encryption
A very simple C++ module to encrypt/decrypt strings based on B64 and Vigenere ciper (symmetric cipher).

We want to send the message `HELLO WORLD` with the vigenere key `THISISMYKEY`. 

NB: In order to have an uncompromised system, we need to choose a very long key (always be longer than the longest message to send).

The reason why we use B64 is because Vigenere works only on alphabet (or on a finite and pre-defined set). We want to be able to encode characters such as `{` and `\`. So it works as an obfuscator.

## Compilation and execution
```
g++ main_encrypt.cpp
./a.out
```

## Output

```
  message to send: HELLO WORLD
```
```
encrypted message: QUxURFcgSU1CUEI=
```
```
decrypted message: HELLO WORLD
```

## Encoding/Decoding JSON format

### Example
```
std::string msg = "{\"PARAM\": 123, \"MSG\": \"HELLO WORLD\"}";
std::string key = "THISISMYKEY";
std::cout << "  message to send: " << msg << std::endl;
std::string encrypted_msg = encrypt(msg, key);
std::cout << "encrypted message: " << encrypted_msg << std::endl;
std::string decrypted_msg = decrypt(encrypted_msg, key);
std::cout << "decrypted message: " << decrypted_msg << std::endl;
```

### Output
```
  message to send: {"PARAM": 123, "MSG": "HELLO WORLD"}
encrypted message: eyJYU1pTWSI6IElFVCwgIkVFRSI6ICJPTURURyBVWVZKVyJ9
decrypted message: {"PARAM": KLM, "MSG": "HELLO WORLD"}
```
