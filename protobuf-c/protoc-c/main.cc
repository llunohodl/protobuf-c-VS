#include <string>

#include <google/protobuf/compiler/plugin.h>
#include <google/protobuf/compiler/command_line_interface.h>
#include <protoc-c/c_generator.h>

//See https://github.com/protobuf-c/protobuf-c/blob/39cd58f5ff06048574ed5ce17ee602dc84006162/build-cmake/CMakeLists.txt
#define PACKAGE_STRING "protobuf-c 1.3.3" 


int main(int argc, char* argv[]) {
  google::protobuf::compiler::c::CGenerator c_generator;

  std::string invocation_name = argv[0];
  std::string invocation_basename = "protoc-c";
  const std::string legacy_name = "protoc-c";

  if (invocation_basename == legacy_name) {
    google::protobuf::compiler::CommandLineInterface cli;
    cli.RegisterGenerator("--c_out", &c_generator, "Generate C/H files.");
    cli.SetVersionInfo(PACKAGE_STRING);
    return cli.Run(argc, argv);
  }

  return google::protobuf::compiler::PluginMain(argc, argv, &c_generator);
}
