DESCRIPTION = "RISC-V Linux Kernel"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${S}/COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel
require recipes-kernel/linux/linux-yocto.inc

LINUX_VERSION_EXTENSION = "-riscv"

PV = "${LINUX_VERSION}+git${SRCPV}"

DEPENDS_append = " libgcc"

KBUILD_DEFCONFIG_qemuriscv32 = "defconfig"
KBUILD_DEFCONFIG_qemuriscv64 = "defconfig"
KCONFIG_MODE="--alldefconfig"

KERNEL_CC_append = " ${TOOLCHAIN_OPTIONS} ${SECURITY_NOPIE_CFLAGS}"
KERNEL_LD_append = " -no-pie"

COMPATIBLE_MACHINE = "(qemuriscv32|qemuriscv64|freedom-u540)"

KERNEL_FEATURES_remove = "features/debug/printk.scc"
KERNEL_FEATURES_remove = "features/kernel-sample/kernel-sample.scc"
