SUMMARY = "A simple i2c"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

inherit module

SRC_URI = "file://Makefile \
           file://i2c_driver.c"

S = "${UNPACKDIR}"

RPROVIDES:${PN} += "kernel-module-i2c"