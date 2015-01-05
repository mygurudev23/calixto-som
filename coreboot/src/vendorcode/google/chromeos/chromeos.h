/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2011 The ChromiumOS Authors.  All rights reserved.
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

#ifndef __CHROMEOS_H__
#define __CHROMEOS_H__

#include <stddef.h>
#include <stdint.h>
#include <bootmode.h>

/* functions implemented in vbnv.c: */
int get_recovery_mode_from_vbnv(void);
int vboot_wants_oprom(void);

void read_vbnv(uint8_t *vbnv_copy);
void save_vbnv(const uint8_t *vbnv_copy);

#if CONFIG_CHROMEOS
/* functions implemented in vboot.c */
void init_chromeos(int bootmode);
#else
static inline void init_chromeos(int bootmode) { }
#endif /* CONFIG_CHROMEOS */

struct romstage_handoff;

/* TODO(shawnn): Remove these CONFIGs and define default weak functions
 * that can be overridden in the platform / MB code. */
#if CONFIG_VBOOT_VERIFY_FIRMWARE
/*
 * This is a dual purpose routine. If dest is non-NULL the region at
 * offset_addr will be read into the area pointed to by dest.  If dest
 * is NULL,the region will be mapped to a memory location. NULL is
 * returned on error else the location of the requested region.
 */
void *vboot_get_region(uintptr_t offset_addr, size_t size, void *dest);
/* Returns 0 on success < 0 on error. */
int vboot_get_handoff_info(void **addr, uint32_t *size);
int vboot_enable_developer(void);
int vboot_enable_recovery(void);
int vboot_skip_display_init(void);
#else
static inline void vboot_verify_firmware(struct romstage_handoff *h) {}
static inline void *vboot_get_payload(int *len) { return NULL; }
static inline int vboot_get_handoff_info(void **addr, uint32_t *size)
{
	return -1;
}
static inline int vboot_skip_display_init(void) { return 0; }
#endif
int vboot_get_sw_write_protect(void);

#include "gnvs.h"
struct device;

#if CONFIG_CHROMEOS_RAMOOPS
void chromeos_ram_oops_init(chromeos_acpi_t *chromeos);
#if CONFIG_CHROMEOS_RAMOOPS_DYNAMIC
static inline void chromeos_reserve_ram_oops(struct device *dev, int idx) {}
#else /* CONFIG_CHROMEOS_RAMOOPS_DYNAMIC */
void chromeos_reserve_ram_oops(struct device *dev, int idx);
#endif /* CONFIG_CHROMEOS_RAMOOPS_DYNAMIC */
#else  /* !CONFIG_CHROMEOS_RAMOOPS */
static inline void chromeos_ram_oops_init(chromeos_acpi_t *chromeos) {}
static inline void chromeos_reserve_ram_oops(struct device *dev, int idx) {}
#endif /* CONFIG_CHROMEOS_RAMOOPS */

#endif
