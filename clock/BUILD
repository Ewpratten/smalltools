load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "clock",
    srcs = [
        "main.c",
    ],
    copts = [
        "-std=gnu99",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//utils/time:timestr_c",
        "//utils/time:sleep_c",
    ],
)
