## TCPClientServer
**Project Overview**

This project is a TCP communication application built using the Qt framework, consisting of both client and server components. The client can connect to the server via TCP and exchange data. The server is capable of accepting client connections and incoming data.

**Features**

**Client**
- Input server IP address and port number.
- Establish a connection to the server and display an interaction interface upon successful connection.
- Send data.
  
**Server**

- Listen on a specified port and accept client connection requests.
- Handle client connections, receive, and respond to data sent by clients.
- Support multi-threading to handle multiple client connections without blocking the main thread.
- Logging functionality to record server status and communication data.
  
**Technology Stack**

- **Qt Framework:** Used for building the graphical user interface (GUI) for both client and server.
- **TCP Protocol:** Used for network communication between client and server.
-** Multi-threading:** The server uses multi-threading to handle multiple client connections.
-** Logging: **Server logs its operational status and communication data to a file.
  
**Installation and Running**

**Requirements**

**Qt Framework:** Qt 5.15 or higher is recommended.
**Compiler:** A compiler that supports C++11 or higher.
**Operating System:** Windows, Linux, or macOS.

**Compilation and Execution**

1.Clone the Project
```git clone https://github.com/serein-23/TCPClientServer.git
cd TCPClientServer`
```
2.Client
- Navigate to the client directory:
```
cd TcpClient
```
- Open the project in Qt Creator, or compile using the command line:
```
qmake make ./TcpClient
```
3.Server
- Navigate to the server directory:
````
cd TcpServer
````
- Open the project in Qt Creator, or compile using the command line:

```
qmake make ./TcpServer
```
**Usage**

**1.Start the Server**
- Run the server application and click the "Start" button.
- The server will listen on the specified port (default is 8000) and wait for client connections.
**2.Start the Client**
- Run the client application, input the server's IP address and port number (default is 8000).
- Click the "Connect" button to establish a connection to the server.
- Use the interaction interface to send data and observe responses from the server.
**3.Notes**
- Ensure that the port numbers are consistent between the server and client.
- If the server and client are running on different machines, ensure proper network connectivity.
- The server supports multi-threading for handling multiple client connections, but the client currently supports only a single connection.
