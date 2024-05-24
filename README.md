# KP9
## Usage
### Prerequisites
You will need:
- llvm clang with google santizers
- cmake 3.25 installed
### Building
```bash
rm -rf build && mkdir build
cd build
cmake ..
make && make install
cd ..
```
## Running
```bash
./build/lab23
```
## Shell sort test
```bash
cd build
ctest --verbose
```

