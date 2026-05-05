# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# Unable to find any files that looked like license statements. Check the accompanying
# documentation and source headers and set LICENSE and LIC_FILES_CHKSUM accordingly.
#
# NOTE: LICENSE is being set to "CLOSED" to allow you to at least start building - if
# this is not accurate with respect to the licensing of the software being built (it
# will not be in most cases) you must specify the correct value before using this
# recipe for anything other than initial testing/development!
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${THISDIR}/LICENSE;md5=d41d8cd98f00b204e9800998ecf8427e"

# No information for SRC_URI yet (only an external source tree was specified)
SRC_URI = "file://hello.py"
PV = "1.0"
PR = "r0"

# for knowledge, next time i will use this format for auto-updating from git repositories:
# SRC_URI = "git://github.com/...;branch=main"
# PV = "1.0+git${SRCPV}"



S = "${UNPACKDIR}"
# adding gobject-introspection to the recipe to allow it to be used in the future if needed
inherit gobject-introspection

# NOTE: no Makefile found, unable to determine what needs to be done

do_configure () {
	# Specify any needed configure commands here
	:
}

do_compile () {
	# Specify compilation commands here
	:
}



# commented logging since they were for learning and not needed for this simple recipe, but they can be used as a template for future recipes 
do_install() {
    bbdebug 2 "Running do_my_function"
    # if [ exceptional_condition ]; then
    #     bbnote "Hit exceptional_condition"
    # fi
    # bbdebug 2  "Got to point xyz"
    # if [ warning_trigger ]; then
    #     bbwarn "Detected warning_trigger, this might cause a problem later."
    # fi
    # if [ recoverable_error ]; then
    #     bberror "Hit recoverable_error, correcting"
    # fi
    # if [ fatal_error ]; then
    #     bbfatal "fatal_error detected"
    # fi
    bbdebug 2 "Completed do_my_function"

    install -d ${D}${bindir}
    install -m 0755 ${S}/hello.py ${D}${bindir}/hello-python
}

# python do_listtasks() {
#     bb.debug(2, "Starting to figure out the task list")

#     noteworthy_condition = True
#     warning_trigger = True
#     recoverable_error = False
#     fatal_error = False

#     if noteworthy_condition:
#         bb.note("There are 13 tasks to run")

#     bb.debug(2, "Got to point XYZ")

#     if warning_trigger:
#         bb.warn("Warning trigger hit!")

#     if recoverable_error:
#         bb.error("Recoverable error detected")

#     if fatal_error:
#         bb.fatal("Fatal error: cannot continue")

#     bb.plain("Tasks present are: abc, def, ghi")

#     bb.debug(2, "Finished figuring out the task list")
# }