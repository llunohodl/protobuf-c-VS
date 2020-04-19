# protobuf-c-VS

Fork of [protobuf-c](https://github.com/protobuf-c/protobuf-c/commit/39cd58f5ff06048574ed5ce17ee602dc84006162) for build in MSVS (Microsoft Visual Studio Community 2019 ver 16.5.4)

### Usage

build protobuf pb.c / pb.h files:


```
 .\protoc-c.exe --c_out=. .\test.proto
```


### Update source code

1. Build release of [protobuf](https://github.com/protocolbuffers/protobuf) as explained in [cmake/README.md](https://github.com/protocolbuffers/protobuf/blob/master/cmake/README.md) 
(note: current version use [f15ac4091f96eb88f583eaa040ed16319104ebd2](https://github.com/protocolbuffers/protobuf/commit/f15ac4091f96eb88f583eaa040ed16319104ebd2))

2. Copy include and lib folder content (from C:\Path\to\install - see cmake/README.md) to this project
3. Get [protobuf-c](https://github.com/protobuf-c/protobuf-c) and update files in protobuf-c and protoc-c
4. Corect main.cc:
add version info from [build-cmake/CMakeLists.txt](https://github.com/protobuf-c/protobuf-c/blob/master/build-cmake/CMakeLists.txt) 

```
//See https://github.com/protobuf-c/protobuf-c/blob/39cd58f5ff06048574ed5ce17ee602dc84006162/build-cmake/CMakeLists.txt
#define PACKAGE_STRING "protobuf-c 1.3.3" 
```

delete exe name test:

replace string:
```
std::string invocation_basename = invocation_name.substr(invocation_name.find_last_of("/") + 1);
```
to:

```
std::string invocation_basename = "protoc-c";
```
