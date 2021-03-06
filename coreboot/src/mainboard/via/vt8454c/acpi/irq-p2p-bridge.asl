/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2007-2009 coresystems GmbH
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of
 * the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

Name (PICM, Package () {
	//           _ADR        PIN   SRC   IDX

	Package () { 0x0003FFFF, 0x00, LNKA, 0x00 },
	Package () { 0x0003FFFF, 0x01, LNKB, 0x00 },
	Package () { 0x0003FFFF, 0x02, LNKC, 0x00 },
	Package () { 0x0003FFFF, 0x03, LNKD, 0x00 },

	Package () { 0x0004FFFF, 0x00, LNKB, 0x00 },
	Package () { 0x0004FFFF, 0x01, LNKC, 0x00 },
	Package () { 0x0004FFFF, 0x02, LNKD, 0x00 },
	Package () { 0x0004FFFF, 0x03, LNKA, 0x00 },

	Package () { 0x0005FFFF, 0x00, LNKC, 0x00 },
	Package () { 0x0005FFFF, 0x01, LNKD, 0x00 },
	Package () { 0x0005FFFF, 0x02, LNKA, 0x00 },
	Package () { 0x0005FFFF, 0x03, LNKB, 0x00 },

	Package () { 0x0006FFFF, 0x00, LNKD, 0x00 },
	Package () { 0x0006FFFF, 0x01, LNKA, 0x00 },
	Package () { 0x0006FFFF, 0x02, LNKB, 0x00 },
	Package () { 0x0006FFFF, 0x03, LNKC, 0x00 },

	Package () { 0x0007FFFF, 0x00, LNKA, 0x00 },
	Package () { 0x0007FFFF, 0x01, LNKB, 0x00 },
	Package () { 0x0007FFFF, 0x02, LNKC, 0x00 },
	Package () { 0x0007FFFF, 0x03, LNKD, 0x00 },

	Package () { 0x0008FFFF, 0x00, LNKB, 0x00 },
	Package () { 0x0008FFFF, 0x01, LNKC, 0x00 },
	Package () { 0x0008FFFF, 0x02, LNKD, 0x00 },
	Package () { 0x0008FFFF, 0x03, LNKA, 0x00 },
})

Name (APIC, Package () {
	Package () { 0x0003FFFF, 0x00, 0x00, 0x10 },
	Package () { 0x0003FFFF, 0x01, 0x00, 0x11 },
	Package () { 0x0003FFFF, 0x02, 0x00, 0x12 },
	Package () { 0x0003FFFF, 0x03, 0x00, 0x13 },

	Package () { 0x0004FFFF, 0x00, 0x00, 0x11 },
	Package () { 0x0004FFFF, 0x01, 0x00, 0x12 },
	Package () { 0x0004FFFF, 0x02, 0x00, 0x13 },
	Package () { 0x0004FFFF, 0x03, 0x00, 0x10 },

	Package () { 0x0005FFFF, 0x00, 0x00, 0x12 },
	Package () { 0x0005FFFF, 0x01, 0x00, 0x13 },
	Package () { 0x0005FFFF, 0x02, 0x00, 0x10 },
	Package () { 0x0005FFFF, 0x03, 0x00, 0x11 },

	Package () { 0x0006FFFF, 0x00, 0x00, 0x13 },
	Package () { 0x0006FFFF, 0x01, 0x00, 0x10 },
	Package () { 0x0006FFFF, 0x02, 0x00, 0x11 },
	Package () { 0x0006FFFF, 0x03, 0x00, 0x12 },

	Package () { 0x0007FFFF, 0x00, 0x00, 0x10 },
	Package () { 0x0007FFFF, 0x01, 0x00, 0x11 },
	Package () { 0x0007FFFF, 0x02, 0x00, 0x12 },
	Package () { 0x0007FFFF, 0x03, 0x00, 0x13 },

	Package () { 0x0008FFFF, 0x00, 0x00, 0x11 },
	Package () { 0x0008FFFF, 0x01, 0x00, 0x12 },
	Package () { 0x0008FFFF, 0x02, 0x00, 0x13 },
	Package () { 0x0008FFFF, 0x03, 0x00, 0x10 },
})
