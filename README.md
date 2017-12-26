# Easy Encryption
A very simple yet powerful standalone C++ module (API) to encrypt/decrypt strings based on B64 and Vigenere ciper (symmetric cipher).

We want to send the message `HELLO WORLD` with the Vigenere key `THISISMYKEY`. It works as follows:

- Alice encodes in base64 the message, then uses the Vigenere private key to encrypt the message.
- The encrypted message is sent through an unsecured channel.
- Bob gets the message and decrypts it with the Vigenere private key. He then decodes it with base64.

The system is safe and unbreakable because:
- Vigenere cipher is vulnerable to bruteforce attacks with dictionaries. Our system encodes first the string in base64. All frequencies and other attacks are void.
- A very large key is used for the Vigenere encryption. We strongly encourage the key to be larger than any message to be sent. The reason is that Vigenere is almost uncrackable if the cipher key is extremely long compared to the average message length.

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
