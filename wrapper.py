import subprocess


def decrypt(message, key):
    return subprocess.check_output(['./a.out', message, key, "1"]).decode('utf8').strip()


def encrypt(message, key):
    return subprocess.check_output(['./a.out', message, key, "0"]).decode('utf8').strip()


if __name__ == '__main__':
    original_msg = 'Hello world'
    key = 'key123'
    encrypted_msg = encrypt(original_msg, key)
    print('ORIGINAL  : ' + original_msg)
    print('ENCRYPTED : ' + encrypted_msg)
    print('DECRYPTED : ' + decrypt(encrypted_msg, key))
