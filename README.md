# Curve25519 for ESP32 
An implementation of elliptic curve cryptography (ECC) using Curve25519. It includes functions for key generation, scalar multiplication, and computing shared secrets. The implementation is designed for use with ESP32 microcontrollers.
## Requirements:
- ESP32 That supports EspressIDF
- Access to esp_system.h (found by installing the board)

## Usage
Key Generation:
```
auto keys = generate_keys();
auto private_key = keys.first;
auto public_key = keys.second;
```
Computing Shared Secret:
```
auto shared_secret = compute_shared(private_key, other_public_key);
```
### Example:
```
#include "Curve25519.h"

int main() {
    // Generate key pairs for two parties
    auto keys_a = generate_keys();
    auto keys_b = generate_keys();

    auto private_key_a = keys_a.first;
    auto public_key_a = keys_a.second;

    auto private_key_b = keys_b.first;
    auto public_key_b = keys_b.second;

    // Compute shared secrets
    auto shared_secret_a = compute_shared(private_key_a, public_key_b);
    auto shared_secret_b = compute_shared(private_key_b, public_key_a);

    // Verify that both shared secrets are equal
    if (is_equal(shared_secret_a.data(), shared_secret_b.data())) {
        std::cout << "Shared secrets match!" << std::endl;
    } else {
        std::cout << "Shared secrets do not match!" << std::endl;
    }

    // Example data to encrypt
    const char* plaintext = "Hello, World!";
    uint8_t encrypted_data[AES_BLOCK_SIZE] = {0};
    uint8_t decrypted_data[AES_BLOCK_SIZE] = {0};

    // Encrypt the data using the shared secret as the key
    encryptData(shared_secret_a.data(), reinterpret_cast<const uint8_t*>(plaintext), encrypted_data);

    // Decrypt the data
    decryptData(shared_secret_a.data(), encrypted_data, decrypted_data);

    // Print the decrypted data
    std::cout << "Decrypted data: " << decrypted_data << std::endl;

    return 0;

    return 0;
}
```
