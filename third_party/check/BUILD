load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

cmake_external(
    name = "check",
    lib_source = "@check_sources//:all",
    shared_libraries = ["libcheck.so.0"],
    visibility = ["//visibility:public"],
)
