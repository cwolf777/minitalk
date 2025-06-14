📨 **minitalk**

This repository contains a solution to the minitalk project from the **third circle** of the **42 school curriculum**.
It explores UNIX signals for interprocess communication (IPC), introducing low-level concepts like bitwise data transmission and signal handling.

🚀 Project Overview

The goal of minitalk is to implement a simple communication protocol between two programs — a server and a client — using only UNIX signals (SIGUSR1 and SIGUSR2).

The client sends messages to the server, bit by bit, with each bit encoded as a specific signal. The server receives and reconstructs the message, displaying it on the screen.


🎯 Features:

🔁 Bit-by-bit message transmission via SIGUSR1 and SIGUSR2

🧠 Bitmask logic to encode and decode characters

🧵 Asynchronous signal handling using sigaction

✅ Full message integrity with null-terminator detection

🧹 Clean error handling and memory-safe implementation

🔗 Dependencies
libft – cloned automatically and compiled as part of the build process

⚙️ Build Instructions
make
This builds both client and server executables. If libft is not present, it is automatically cloned from GitHub.

💬 Usage
1. Start the server:
./server

2. Send a message from the client:
./client <server_pid> "Your message here"
