# Copyright lowRISC contributors.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hash",
    srcs = ["hash.c"],
    hdrs = [
        "//sw/device/lib/crypto/drivers:kmac.h",
        "//sw/device/lib/crypto/include:hash.h",
    ],
    deps = [
        "//sw/device/lib/base:hardened",
        "//sw/device/lib/crypto/drivers:kmac",
        "//sw/device/lib/crypto/include:datatypes",
    ],
)

cc_library(
    name = "integrity",
    srcs = ["integrity.c"],
    hdrs = ["integrity.h"],
    deps = [
        "//sw/device/lib/base:hardened",
        "//sw/device/lib/crypto/include:datatypes",
    ],
)

cc_library(
    name = "keyblob",
    srcs = ["keyblob.c"],
    hdrs = ["keyblob.h"],
    deps = [
        ":integrity",
        ":status",
        "//sw/device/lib/base:hardened_memory",
        "//sw/device/lib/crypto/include:datatypes",
    ],
)

cc_test(
    name = "keyblob_unittest",
    srcs = ["keyblob_unittest.cc"],
    deps = [
        ":keyblob",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "status",
    srcs = ["status.c"],
    hdrs = [
        "status.h",
    ],
    deps = [
        "//sw/device/lib/base:hardened_status",
        "//sw/device/lib/crypto/include:datatypes",
    ],
)

cc_test(
    name = "status_unittest",
    srcs = ["status_unittest.cc"],
    deps = [
        ":status",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "mac",
    srcs = ["mac.c"],
    hdrs = [
        "//sw/device/lib/crypto/drivers:kmac.h",
        "//sw/device/lib/crypto/include:datatypes.h",
        "//sw/device/lib/crypto/include:mac.h",
    ],
    deps = [
        ":integrity",
        ":keyblob",
        "//sw/device/lib/base:hardened",
        "//sw/device/lib/crypto/drivers:kmac",
    ],
)
