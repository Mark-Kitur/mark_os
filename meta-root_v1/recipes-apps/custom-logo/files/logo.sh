#!/bin/bash

IMAGE_JPG_INPUT="$IMAGE_JPG_INPUT"
IMAGE_UBOOT="raspi.bmp"
IMAGE_KERNEL="logo_kernel.bmp"

echo "Converting ${IMAGE_JPG_INPUT} to ${IMAGE_UBOOT} and ${IMAGE_KERNEL}"

# Convert JPG to PPM, then to BMP for U-Boot, and PPM for kernel
jpegtopnm "${IMAGE_JPG_INPUT}" | ppmquant 448 > tmp.ppm
ppmnoraw tmp.ppm > "${IMAGE_KERNEL}"
ppmtobmp -bpp 8 tmp.ppm > "${IMAGE_UBOOT}"

rm tmp.ppm