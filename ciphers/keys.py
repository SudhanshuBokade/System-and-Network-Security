K_TRAD = "sudhanriboketvfjcpwlxmgyqz"

K_ROLL1 = 4
K_ROLL2 = 2

TRADITIONAL_CIPHER = [
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " ", "a", "b", "c", "d", "e", "f", "g", "h",
    "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
    "w", "x", "y", "z"
]

TRADITIONAL_CIPHER_MODIFIED = [
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "a", "b", "c", "d", "e", "f", "g", "h",
    "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
    "w", "x", "y", "z"
]

#Array of sets so that searching becomes quicker
SECRET_MATRIX = [
    ["s", "u", "d", "h", "a"],
    ["n", "r", "i", "b", "o"],
    ["k", "e", "t", "v", "f"],
    ["c", "p", "w", "l", "x"],
    ["m", "g", "y", "q", "z"]
]

SECRET_MATRIX_NUMERIC = [
    [29, 31, 14, 18, 11],
    [24, 28, 19, 12, 25],
    [21, 15, 30, 32, 16],
    [13, 26, 33, 22, 34],
    [23, 17, 35, 27, 36]
]
