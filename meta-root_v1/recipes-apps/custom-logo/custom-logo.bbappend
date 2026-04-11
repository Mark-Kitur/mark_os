# Make Yocto search our custom-logo output
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

# Override default Poky splash image
do_install:append:rpi() {
    install -d ${D}${datadir}/psplash
    install -m 0644 ${WORKDIR}/../../custom-logo/raspi.bmp \
        ${D}${datadir}/psplash/psplash-poky-img.png
}