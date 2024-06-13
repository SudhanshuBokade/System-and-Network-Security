import keys
import sys


def vigenereCipher(plainText, secret):
    encryptedText = ""
    secretKeyIndex = 0
    alphabetSize = keys.TRADITIONAL_CIPHER

    for i in range(0, len(plainText)):
        pVal = 0
        subkey = 0
        cVal = 0
        if(plainText[i].isnumeric()):
            pVal = int(plainText[i])
        else:
            pVal = ord(plainText[i]) - ord("a") + 11
        
        subkey = ord(secret[secretKeyIndex]) - ord("a") + 11

        cVal = (pVal + subkey) % len(alphabetSize)

        encryptedText += keys.TRADITIONAL_CIPHER[cVal]

        secretKeyIndex = (secretKeyIndex + 1) % (len(secret))

    return encryptedText


if len(sys.argv) < 2:
    print("Usage: prg1.py <text>")

plainText = sys.argv[1]
plainText = plainText.lower()

secret = keys.K_TRAD

print(vigenereCipher(plainText, secret))