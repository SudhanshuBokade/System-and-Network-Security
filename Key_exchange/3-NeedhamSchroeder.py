
# SNS-LAB-4
# Q3 - Implement Needham–Schroeder protocol using any symmetric cryptosystem

################################ Needham-Schroeder ################################

# Same as Kerberos but it has not KDC (Key Distribution Center)
# It is a third party
# It ensures : 
    # Centralized Authentication:
    # Secret Key Distribution

################################ Code ################################

import hashlib

# Simulate the user database with usernames and passwords
user_database = {
    "Sudhanshu": "password1",
    "Raj": "password2",
}

# XOR encryption function
def xor_encrypt(data, key):
    encrypted = []
    for i in range(len(data)):
        encrypted.append(data[i] ^ key[i % len(key)])
    return bytes(encrypted)

# XOR decryption function
def xor_decrypt(data, key):
    return xor_encrypt(data, key)

# Authentication Server (AS)
def as_request(username, timestamp):
    if username in user_database:
        password = user_database[username]
        # Generate a nonce
        nonce = b"123456"
        # Create the message for the user
        message = password.encode() + nonce + timestamp
        # Encrypt the message using XOR with a shared secret key
        shared_secret_key = hashlib.sha256(username.encode()).digest()
        encrypted_message = xor_encrypt(message, shared_secret_key)
        return encrypted_message, nonce
    else:
        return None, None

# Ticket Granting Server (TGS)
def tgs_request(encrypted_message, nonce, timestamp):
    # Decrypt the message using XOR with a shared secret key
    decrypted_message = xor_decrypt(encrypted_message, hashlib.sha256("Sudhanshu".encode()).digest())
    password = decrypted_message[:-len(nonce)-len(timestamp)].decode()
    if password == user_database.get("Sudhanshu"):
        # Generate a session key
        session_key = hashlib.sha256(password.encode()).digest()
        # Encrypt the session key using XOR with the nonce and timestamp
        tgt = xor_encrypt(session_key, nonce + timestamp)
        return tgt
    else:
        return None

# Client request
client_username = "Sudhanshu"
client_timestamp = b"987654"
client_message, nonce = as_request(client_username, client_timestamp)
if client_message:
    tgt = tgs_request(client_message, nonce, client_timestamp)
    if tgt:
        print("Authentication successful!")
        print("Session Key (hex):", tgt.hex())
    else:
        print("TGS authentication failed.")
else:
    print("AS authentication failed.")
