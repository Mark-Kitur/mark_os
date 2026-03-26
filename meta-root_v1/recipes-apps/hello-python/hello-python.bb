SUMMARY = "A simple hello world application written in Python. This recipe is used to demonstrate how to create a new layer and add a new recipe to it."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${THISDIR}/LICENSE;md5=59a892df105a057157407c8452becd72"

SRC_URI = "file://hello.py"
S = "${UNPACKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/hello-python.py ${D}${bindir}/hello-python
}