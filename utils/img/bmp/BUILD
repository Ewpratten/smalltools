load("@rules_cc//cc:defs.bzl", "cc_library")

package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "utils",
    srcs = [
        "utils.c",
        "utils.h",
    ],
    hdrs = [
        "utils.h",
    ],
    deps = [
        ":fileheader",
        "//utils/img:pixel"
    ]
)

cc_library(
    name = "fileheader",
    srcs = [
        "fileheader.h",
    ],
    hdrs = [
        "fileheader.h",
    ],
)

