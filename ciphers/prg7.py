import keys
import sys
import copy
#rotor cipher
K_TRAD = "sudhanriboketvfjcpwlxmgyqz 0123456789"

mapping = {
    "0" : "s", "1" : "u", "2" : "d", "3" : "h", "4" : "a",
    "5" : "n", "6" : "r", "7" : "i", "8" : "b", "9" : "o", " " : "k",
    "a" : "e", "b" : "t", "c" : "v", "d" : "f", "e" : "j", "f" : "c",
    "g" : "p", "h" : "w", "i" : "l", "j" : "x", "k" : "m", "l" : "g",
    "m" : "y", "n" : "q", "o" : "g", "z" : " ", "q" : "0", "r" : "1", 
    "s" : "2", "t" : "3", "u" : "4", "v" : "5", "w" : "6", 
    "x" : "7", "y" : "8", "z" : "9"
}

def reverseMapping():
    newMapping = {}

    for key in mapping:
        newMapping[mapping[key]] = key

    return newMapping


def rotate(mapping):
    keyList = list(mapping.keys())

    newMapping = {}

    for i in range(0, len(mapping)):
        newMapping[keyList[i]] = mapping[keyList[(i + 1) % len(mapping)]]

    return newMapping

def decrypt(encryptedText):
    
    reverseMap = reverseMapping()

    for char in encryptedText:
        print(reverseMap[char], end="")

#rotor is rotated onestep each time.
def rotoCipher(plainText):
    global mapping
    keyMapping = rotate(mapping)
    
    encryptedText = ""
    for char in plainText:
        encryptedText += keyMapping[char]

    mapping = keyMapping

    return encryptedText


if len(sys.argv) < 2:
    print("Usage: prg8.py <text>")

plainText = sys.argv[1]
plainText = plainText.lower()

encryptedText = rotoCipher(plainText)

print(encryptedText)
decrypt(encryptedText)