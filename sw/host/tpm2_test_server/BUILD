# Copyright lowRISC contributors.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0

load("@rules_rust//rust:defs.bzl", "rust_binary")
load("@rules_pkg//pkg:mappings.bzl", "pkg_filegroup", "pkg_files")

package(default_visibility = ["//visibility:public"])

rust_binary(
    name = "tpm2-test-server",
    srcs = [
        "src/interface.rs",
        "src/main.rs",
    ],
    stamp = 1,
    deps = [
        "//sw/host/opentitanlib",
        "@crate_index//:anyhow",
        "@crate_index//:env_logger",
        "@crate_index//:log",
        "@crate_index//:mio",
        "@crate_index//:num_enum",
        "@crate_index//:structopt",
    ],
)

pkg_files(
    name = "binary",
    srcs = [":tpm2-test-server"],
)

pkg_filegroup(
    name = "package",
    srcs = [
        ":binary",
    ],
    prefix = "tpm2-test-server",
)
