#ifndef ENCRYPTION_H
#define ENCRYPTION_H

void encrypt_password(const char* password, char* encrypted_password);
void decrypt_password(const char* encrypted_password, char* decrypted_password);

#endif