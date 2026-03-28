SUMMARY = "A simple hello world application written in Python."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${THISDIR}/LICENSE;md5=59a892df105a057157407c8452becd72"

SRC_URI = "file://hello.py"

# Required for file-only recipes in modern Yocto
S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/hello.py ${D}${bindir}/hello-python
}