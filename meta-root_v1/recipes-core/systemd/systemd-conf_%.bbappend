FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

PACKAGECONFIG = "${@bb.utils.contains('DISTRO_FEATURES', 'static-ip-address', 'static-wifi', 'dhcp-wifi',d)}"

PACKAGECONFIG[static-wifi] = ""

SRC_URI:prepend = " \
    file://wifi-static.network \
    "

do_install:append() {
    if ${@bb.utils.contains('PACKAGECONFIG', 'static-wifi', 'true', 'false', d)}; then
        install -D -m0644 \
        ${UNPACKDIR}/wifi-static.network \
        ${D}${systemd_unitdir}/network/75-wifi-static.network
    fi
}

#FILES:${PN} += "${nonarch_libdir}/systemd/network/75-wifi-static.network"