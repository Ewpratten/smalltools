load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

package(
    default_visibility = ["//visibility:public"],
)

test_suite(
    name = "tests",
    tests = [
        ":timestr_test",
    ],
)

cc_library(
    name = "timestr",
    srcs = [
        "timestr.c",
        "timestr.h",
    ],
    hdrs = [
        "timestr.h",
    ],
)

cc_test(
    name = "timestr_test",
    srcs = [
        "timestr_test.c",
    ],
    deps = [
        ":timestr",
        "//third_party/check",
    ],
    copts = [
        "-Wno-unused-variable"
    ]
)

cc_library(
    name = "sleep",
    srcs = [
        "sleep.h",
    ] + select({
        "@bazel_tools//src/conditions:windows": ["sleep_dos.c"],
        "//conditions:default": ["sleep_unix.c"],
    }),
    # See: https://stackoverflow.com/a/48877306
)
