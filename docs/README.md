# My Project

This is a C++ program that connects to MariaDB and accepts HTTP requests.

## Building and Running

To build the project, follow these steps:

1. Install the required dependencies (e.g., MariaDB Connector/C++, cpp-httplib).
2. Configure the project build using CMake.
3. Build the project using your preferred build system (e.g., `make`, Visual Studio, Xcode).
4. Execute the resulting binary to start the server.

## Usage

The server listens on `localhost:8080` and supports the following HTTP endpoints:

- `GET /`: Retrieves data from the database.
- `POST /`: Adds data to the database.

For detailed API documentation, refer to [API.md](API.md).

## License

This project is licensed under the [MIT License](../LICENSE).
