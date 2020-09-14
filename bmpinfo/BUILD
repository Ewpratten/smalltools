load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "bmpinfo",
    srcs = [
        "main.c",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//utils/img/bmp:fileheader",
        "//utils/img/bmp:io",
    ],
)
