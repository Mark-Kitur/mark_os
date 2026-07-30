LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${THISDIR}/LICENSE;md5=d41d8cd98f00b204e9800998ecf8427e"

# Fixed: Removed trailing space in SRC_URI
SRC_URI = " \
    file://unblock.sh \
    file://unblock-wifi.service \
"

inherit systemd

S = "${UNPACKDIR}"

do_install() {
    # Install script
    install -d ${D}${bindir}
    install -m 0755 ${S}/unblock.sh ${D}${bindir}/unblock-wifi

    # Fixed: Use ${systemd_unitdir}/system which is the standard variable
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${S}/unblock-wifi.service ${D}${systemd_unitdir}/system/
}

# Ensure the service is enabled
SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} = "unblock-wifi.service"

# Explicitly add the service file to the package (good practice, though systemd class often handles it)
FILES:${PN} += "${systemd_unitdir}/system/unblock-wifi.service"   