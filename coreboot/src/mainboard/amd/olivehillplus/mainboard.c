/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2012 Advanced Micro Devices, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <console/console.h>
#include <device/device.h>
#include <device/pci.h>
#include <arch/io.h>
#include <device/pci_def.h>
#include <arch/acpi.h>
#include <northbridge/amd/pi/BiosCallOuts.h>
#include <cpu/amd/pi/s3_resume.h>
#include <northbridge/amd/pi/agesawrapper.h>
#include <cpu/x86/msr.h>
#include <cpu/amd/mtrr.h>

/**********************************************
 * enable the dedicated function in mainboard.
 **********************************************/
static void mainboard_enable(device_t dev)
{
	printk(BIOS_INFO, "Mainboard " CONFIG_MAINBOARD_PART_NUMBER " Enable.\n");

	if (acpi_is_wakeup_s3())
		agesawrapper_fchs3earlyrestore();
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
};
