SUMMARY = "Simple Hello World Linux kernel module"
DESCRIPTION = "Example out-of-tree kernel module"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

inherit module

SRC_URI = "file://Makefile \
           file://hello.c"

S = "${UNPACKDIR}"

RPROVIDES:${PN} += "kernel-module-hello"

# Optional: module name for modprobe
KERNEL_MODULE_NAME = "hello"