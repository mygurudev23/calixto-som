/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2013 Google Inc.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License
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
#include "ec.h"
#include "ec_commands.h"
#include <spi-generic.h>
#include <timer.h>

static const uint8_t EcFramingByte = 0xec;

static int crosec_spi_io(uint8_t *write_bytes, size_t write_size,
			 uint8_t *read_bytes, size_t read_size,
			 void *context)
{
	struct spi_slave *slave = (struct spi_slave *)context;

	spi_claim_bus(slave);

	if (spi_xfer(slave, write_bytes, write_size, NULL, 0)) {
		printk(BIOS_ERR, "%s: Failed to send request.\n", __func__);
		spi_release_bus(slave);
		return -1;
	}

	uint8_t byte;
	struct mono_time start;
	struct rela_time rt;
	timer_monotonic_get(&start);
	while (1) {
		if (spi_xfer(slave, NULL, 0, &byte, sizeof(byte))) {
			printk(BIOS_ERR, "%s: Failed to receive byte.\n",
			       __func__);
			spi_release_bus(slave);
			return -1;
		}
		if (byte == EcFramingByte)
			break;

		// Wait 1s for a framing byte.
		rt = current_time_from(&start);
		if (rela_time_in_microseconds(&rt) > 1000 * 1000) {
			printk(BIOS_ERR,
			       "%s: Timeout waiting for framing byte.\n",
			       __func__);
			spi_release_bus(slave);
			return -1;
		}
	}

	if (spi_xfer(slave, NULL, 0, read_bytes, read_size)) {
		printk(BIOS_ERR, "%s: Failed to receive response.\n", __func__);
		spi_release_bus(slave);
		return -1;
	}

	spi_release_bus(slave);

	return 0;
}

int google_chromeec_command(struct chromeec_command *cec_command)
{
	static struct spi_slave *slave = NULL;
	if (!slave)
		slave = spi_setup_slave(CONFIG_EC_GOOGLE_CHROMEEC_SPI_BUS,
					CONFIG_EC_GOOGLE_CHROMEEC_SPI_CHIP);
	return crosec_command_proto(cec_command, crosec_spi_io, slave);
}

#ifndef __PRE_RAM__
u8 google_chromeec_get_event(void)
{
	printk(BIOS_ERR, "%s: Not supported.\n", __func__);
	return 0;
}
#endif
