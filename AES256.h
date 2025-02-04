#include <Crypto.h>
#include <AES.h>
#include <string.h>

#define AES_KEY_SIZE 32
#define AES_BLOCK_SIZE 16

// Function to encrypt data using AES-256
void encryptData(const uint8_t *key, const uint8_t *data, uint8_t *encryptedData)
{
    AES256 aesEncryptor;
    aesEncryptor.setKey(key, AES_KEY_SIZE);
    aesEncryptor.encryptBlock(encryptedData, data);
}

// Function to decrypt data using AES-256
void decryptData(const uint8_t *key, const uint8_t *encryptedData, uint8_t *decryptedData)
{
    AES256 aesDecryptor;
    aesDecryptor.setKey(key, AES_KEY_SIZE);
    aesDecryptor.decryptBlock(decryptedData, encryptedData);
}

// Helper function to convert float to byte array
void floatToBytes(float value, uint8_t *bytes)
{
    memcpy(bytes, &value, sizeof(value));
}

// Helper function to convert byte array to float
float bytesToFloat(const uint8_t *bytes)
{
    float value;
    memcpy(&value, bytes, sizeof(value));
    return value;
}