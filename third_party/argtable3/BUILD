load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

cmake_external(
    name = "argtable3",
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
    },
    lib_source = "@argtable3_sources//:all",
    shared_libraries = ["libargtable3.so"],
    visibility = ["//visibility:public"],
)
