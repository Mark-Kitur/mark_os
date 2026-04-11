SUMMARY = "A simple C application that prints Hello World"
SECTION = "examples"

LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

SRC_URI = "file://helloworld.c"


S = "${UNPACKDIR}"

do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} helloworld.c -o helloworld
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 helloworld ${D}${bindir}/helloworld
}