# Easy Encryption
A very simple C++ module to encrypt/decrypt strings based on B64 and Vigenere ciper (symmetric cipher).

We want to send the message `HELLO WORLD` with the vigenere key `THISISMYKEY`. 

NB: In order to have an uncompromised system, we need to choose a very long key (always be longer than the longest message to send).

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
