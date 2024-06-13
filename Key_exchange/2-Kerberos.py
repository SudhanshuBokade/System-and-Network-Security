
################################ KERBEROS ################################

#Initialization :
#   KDC (Key Distribution Center): A trusted server(third party), the KDC, is set up in the network. 
#   The KDC has two main components: 
#       1.The Authentication Server (AS)
#       2.The Ticket Granting Server (TGS).

# User Registration :
#   Users are registered with the KDC, and each user is issued a secret symmetric key (password).

# Authentication :
#   When a user wants to authenticate to a network service, 
#   they provide their credentials (username and password) to the AS.

# Ticket Granting :
#   The AS checks the provided credentials. If they are correct, the AS generates a TGT (Ticket Granting Ticket) and sends it back to the user.

# Requesting a Service Ticket :
#   The user wants to access a specific network service (e.g., a file server). 
#   They send a service ticket request to the TGS, including the TGT.

# Service Ticket Issuance :
#   The TGS verifies the TGT and, if valid, issues a service ticket encrypted with a session key. 
#   The service ticket represents the user's identity and includes the session key.

# Accessing the Service :
#   The user sends the service ticket to the desired service, along with a timestamp, which proves the current time. 
#   The service decrypts the service ticket using its own secret key, obtains the session key, and validates the user's identity.

# Mutual Authentication :
#   Both the user and the service can trust each other since they share a common session key. 
#   They can communicate securely without sending sensitive information over the network.


################################ CODE ################################

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import hashlib
import base64
import hashlib

# Simulate the user database with usernames and passwords (insecure, only for demonstration)
user_database = {
    "sudhanshu": "sudh123",
    "harsh": "harsh123",
}

# Simulate a Key Distribution Center (KDC) with secret keys
kdc_secret_key = "KDC_SECRET_KEY"

# XOR encryption and decryption functions
def xor_encrypt(data, key):
    encrypted = []
    for i in range(len(data)):
        encrypted.append(data[i] ^ key[i % len(key)])
    return bytes(encrypted)

def xor_decrypt(data, key):
    return xor_encrypt(data, key)

# Authentication Server (AS)
def as_request(username):
    if username in user_database:
        password = user_database[username]
        # Simulate a timestamp as a nonce
        nonce = b"123456"
        # Combine password and nonce to create the message
        message = password.encode() + nonce
        # Encrypt the message using XOR with KDC's secret key
        encrypted_message = xor_encrypt(message, kdc_secret_key.encode())
        return encrypted_message, nonce
    else:
        return None, None

# Ticket Granting Server (TGS)
def tgs_request(encrypted_message, nonce):
    # Decrypt the message using XOR with KDC's secret key
    decrypted_message = xor_decrypt(encrypted_message, kdc_secret_key.encode())
    password = decrypted_message[:-len(nonce)].decode()
    if password == user_database.get("sudhanshu"):
        # Generate a session key and a TGT
        session_key = hashlib.sha256(password.encode()).digest()
        tgt = session_key
        return tgt
    else:
        return None

# Client request
client_username = "sudhanshu"
client_message, nonce = as_request(client_username)
if client_message:
    tgt = tgs_request(client_message, nonce)
    if tgt:
        print("TGS Authentication successful!")
    else:
        print("TGS authentication failed.")
else:
    print("AS authentication failed.")
