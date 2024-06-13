import keys
import sys
import random
import numpy
#hill ciper
def modifyInput(plaintext):
    #If len(plaintext) is a multiple of 5 there is no need
    #to add bogus characters
    if(len(plainText) % 5 == 0):
        return plainText
    
    modifedText = plainText
    bogusCharacterCount = 5 - (len(plainText) % 5)

    for i in range(0, bogusCharacterCount):
        modifedText += keys.TRADITIONAL_CIPHER[random.randint(11, 36)]

    return modifedText

def hillCipher(plaintext, secretMatrix):
    modifiedText = modifyInput(plaintext)

    rowCount = len(modifiedText) // 5

    #Make a matrix from the modified text which can be multiplied
    #by the secretMatrix

    modifiedTextMatrix = []

    k = 0
    for i in range(0, rowCount):
        row = []
        for j in range(0, 5):
            row.append(ord(modifiedText[k]) - ord("a") + 11)
            k += 1
        modifiedTextMatrix.append(row)

    encryptedTextMatrix = numpy.dot(modifiedTextMatrix, secretMatrix)
    #Modulate values in the matrix
    encryptedTextMatrix %= 37

    encryptedText = ""
    for row in encryptedTextMatrix:
        for col in row:
            encryptedText += keys.TRADITIONAL_CIPHER[col]
    
    return encryptedText

if len(sys.argv) < 2:
    print("Usage: prg1.py <text>")
    exit()

plainText = sys.argv[1]
plainText = plainText.lower()
secretMatrix = keys.SECRET_MATRIX_NUMERIC

print(hillCipher(plainText, secretMatrix))

