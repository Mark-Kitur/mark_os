# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# WARNING: the following LICENSE and LIC_FILES_CHKSUM values are best guesses - it is
# your responsibility to verify that the values are complete and correct.
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${THISDIR}/LICENSE;md5=d41d8cd98f00b204e9800998ecf8427e"

# No information for SRC_URI yet (only an external source tree was specified)
SRC_URI = "file://unblock.sh"

S = "${UNPACKDIR}"

# NOTE: no Makefile found, unable to determine what needs to be done

do_configure () {
	# Specify any needed configure commands here
	:
}

do_compile () {
	# Specify compilation commands here
	:
}

do_install () {
	# Specify install commands here
	:
	install -d ${D}${bindir}
	install -m 0755 ${S}/unblock.sh ${D}${bindir}/unblock-wifi
}

