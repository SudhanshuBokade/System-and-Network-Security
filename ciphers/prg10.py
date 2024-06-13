import sys
import random
import keys

K_TRAD = "sudhanriboketvfjcpwlxmgyqz"

mapping = {
    0 : 29, 1 : 31, 2 : 14, 
    3 : 18, 4 : 11, 5 : 24, 
    6 : 28, 7 : 19, 8 : 12, 
    9 : 25, 10 : 21, 11 : 15, 
    12 : 30, 13 : 32, 14 : 16, 
    15 : 20, 16 : 13, 17 : 26, 
    18 : 33, 19 : 22, 20 : 34, 
    21 : 23, 22 : 17, 23 : 35, 
    24 : 27, 25 : 36, 26 : 10, 
    27 : 0, 28 : 1, 29 : 2,
    30 : 3, 31 : 4, 32 : 5, 
    33 : 6, 34 : 7, 35 : 8, 
    36 : 9
}

def generateMapping():
    mapping = {}
    for i in range(0, 25):
        mapping[i] = keys.TRADITIONAL_CIPHER.index(K_TRAD[i])

    return mapping

def padInput(plainText):
    if((len(plainText)) % 37 == 0):
        return plainText
    
    modifiedText = plainText

    for i in range(0, 37 - ((len(plainText) % 37))):
        modifiedText += keys.TRADITIONAL_CIPHER[(random.randint(0, 36))]

    return modifiedText

def makeBlocks(plainText):
    blocks = []
    for i in range(0, len(plainText), 37):
        blocks.append(plainText[i : i + 37])

    return blocks

def encryptBlock(block):
    encryptedBlock = [""] * len(block)
    for i in range(0, 37):
        encryptedBlock[i] = block[mapping[i]]

    return encryptedBlock

def keyedTranspositionCipher(plainText):
    paddedPlainText = padInput(plainText)
    blocks = makeBlocks(paddedPlainText)
    encryptedBlocks = []

    for block in blocks:
        encryptedBlocks.append(encryptBlock(block))

    encryptedText = ""
    for block in encryptedBlocks:
        encryptedText += "".join(block)
    
    return encryptedText

def decryptBlock(block):
    decryptedBlock = [""] * len(block)
    for i in range(0, 37):
        decryptedBlock[mapping[i]] = block[i]
    return decryptedBlock

def decrypt(encryptedText):
    blocks = makeBlocks(encryptedText)

    decryptedBlocks = []

    for block in blocks:
        decryptedBlocks.append(decryptBlock(block))

    decryptedText = ""
    for block in decryptedBlocks:
        decryptedText += "".join(block)
    
    return decryptedText

if len(sys.argv) < 2:
    print("Usage: prg1.py <text>")
    exit()

plainText = sys.argv[1]
plainText = plainText.lower()

encryptedText = keyedTranspositionCipher(plainText)
print(encryptedText)
