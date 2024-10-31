
# AES Encryption Algorithm

## Overview

This repository contains an implementation of the AES (Advanced Encryption Standard) encryption algorithm in C++. It supports both encryption and decryption of 128-bit blocks using a 128-bit key.
**AES (Advanced Encryption Standard)** is a symmetric encryption algorithm widely used for securing data. It operates on fixed-size blocks of data (128 bits) and supports key sizes of 128, 192, or 256 bits. AES is known for its speed and security, making it a standard choice for encrypting sensitive information.

## Features

-   **128-bit Key Length**: The algorithm uses a fixed key size of 128 bits.
-   **Block Size**: Operates on 128-bit (16 bytes) blocks of plaintext.
-   **Encryption and Decryption**: Fully implements the AES encryption and decryption process.
-   **S-box and Inverse S-box**: Utilizes pre-defined S-boxes for substitution steps.

## Structure

-   **aes.hpp**: Header file containing the AES class definition and method declarations.
-   **aes.cpp**: Implementation of the AES algorithm methods.
-   **main.cpp**: Example usage of the AES class demonstrating encryption and decryption.