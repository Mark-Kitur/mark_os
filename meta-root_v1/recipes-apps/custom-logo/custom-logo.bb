SUMMARY = "Generate splash screen logos for U-Boot and Linux kernel"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${THISDIR}/LICENSE;md5=d41d8cd98f00b204e9800998ecf8427e"

SRC_URI = "file://logo.jpg \
           file://logo.sh"

S = "${UNPACKDIR}"

do_compile() {
    chmod +x ${S}/logo.sh
    cd ${S}
    IMAGE_JPG_INPUT="${S}/logo.jpg" ./logo.sh
}

do_install() {
    # Create target directory
    install -d ${D}${datadir}/psplash

    # Copy generated images
    install -m 0644 ${S}/raspi.bmp       ${D}${datadir}/psplash/
    install -m 0644 ${S}/logo_kernel.bmp ${D}${datadir}/psplash/
}

FILES:${PN} = "${datadir}/psplash/"