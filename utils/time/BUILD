load("@rules_cc//cc:defs.bzl", "cc_library")

package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "timestr_c",
    srcs = [
        "timestr.c",
        "timestr.h",
    ],
    hdrs = [
        "timestr.h",
    ],
)

cc_library(
    name = "sleep_c",
    srcs = [
        "sleep.h",
    ] + select({
        "@bazel_tools//src/conditions:windows": ["sleep_dos.c"],
        "//conditions:default": ["sleep_unix.c"],
    }),
    # See: https://stackoverflow.com/a/48877306
)
