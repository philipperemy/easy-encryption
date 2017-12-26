# Easy Encryption
A very simple yet powerful standalone C++ module (API) to encrypt/decrypt strings based on B64 and Vigenere ciper (symmetric cipher).

We want to send the message `HELLO WORLD` with the Vigenere key `THISISMYKEY`. It works as follows:

- Alice encodes in base64 the message, then uses the Vigenere private key to encrypt the message.
- The encrypted message is sent through an unsecured channel.
- Bob gets the message and decrypts it with the Vigenere private key. He then decodes it with base64.

_______________________________________________________________________________________________________________
**Message -> B64 ENCODE -> VIGENERE ENCRYPT -> encrypted message -> VIGENERE DECRYPT -> B64 DECODE -> Message**
_______________________________________________________________________________________________________________

The system is safe and unbreakable because:
- Vigenere cipher is vulnerable to bruteforce attacks with dictionaries. Our system encodes first the string in base64. All frequencies and other attacks are void.
- A very large key is used for the Vigenere encryption. We strongly encourage the key to be larger than any message to be sent. The reason is that Vigenere is almost uncrackable if the cipher key is extremely long compared to the average message length.
- The reason why we apply b64 encode BEFORE Vigenere is because it's very easy for somebody to apply a b64 decode and see about the structure of the message. For example, if we send `{"hello":123}`, an attacker can sniff the message, b64 decode the message and get `{"qsggn":ygf}`. Of course the attacker still needs the Vigenere cipher key, but at least, he can get a pretty clear idea that JSON format messages are sent in the communication channel. The way to avoid this is to encode first in b64 then encrypt it with the Vigenere key. If the attacker tries to b64 decode first, it will see a random string of weird characters.

## Compilation and execution
```
g++ main.cpp
./a.out
```

## Encoding/Decoding JSON format

### Example
```
std::string msg = "{\"id\":1,\"method\":\"service.subscribe\",\"params\":[\"myapp/0.1c\", null,\"0.0.0.0\",\"80\"]}";
std::string key = "THISISMYKEY";
std::cout << "  message to send: " << msg << std::endl;
std::string encrypted_msg = encrypt(msg, key);
std::cout << "encrypted message: " << encrypted_msg << std::endl;
std::string decrypted_msg = decrypt(encrypted_msg, key);
std::cout << "decrypted message: " << decrypted_msg << std::endl;
```

### Output
```
  message to send: {"id":1,"method":"service.subscribe","params":["myapp/0.1c", null,"0.0.0.0","80"]}
encrypted message: X5g7wjjTllj1ItCxShWUb77PKJsfP VNMAB7VtqaLCccGTr0ijkjxqw0IutQvXfSFK4OKo8cnpD1Lge0pdMCZf0fqQ8bjjFjkNn1h pBtdwNJD==
decrypted message: {"id":1,"method":"service.subscribe","params":["myapp/0.1c", null,"0.0.0.0","80"]}
```
