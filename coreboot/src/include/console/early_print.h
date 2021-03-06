/*
 * This file is part of the coreboot project.
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

#ifndef __CONSOLE_EARLY_PRINT_H_
#define __CONSOLE_EARLY_PRINT_H_

#include <console/console.h>
#include <console/streams.h>
#include <console/loglevel.h>

#if defined(__ROMCC__)
/* While in romstage, console loglevel is built-time constant.
 * With ROMCC we inline this test with help from preprocessor.
 */
#define console_log_level(msg_level) (CONFIG_DEFAULT_CONSOLE_LOGLEVEL >= msg_level)

#define CALL_CONSOLE_TX(loglevel, tx_func, x) \
	do { 						\
		if (console_log_level(loglevel)) { 	\
			tx_func(x);		 	\
			console_tx_flush();		\
		}	\
	} while (0)

#define __console_tx_char(level, x)	CALL_CONSOLE_TX(level, console_tx_byte, x)
#define __console_tx_hex8(level, x)	CALL_CONSOLE_TX(level, console_tx_hex8, x)
#define __console_tx_hex16(level, x)	CALL_CONSOLE_TX(level, console_tx_hex16, x)
#define __console_tx_hex32(level, x)	CALL_CONSOLE_TX(level, console_tx_hex32, x)
#define __console_tx_string(level, x)	CALL_CONSOLE_TX(level, console_tx_string, x)

#define print_emerg(STR)         __console_tx_string(BIOS_EMERG, STR)
#define print_alert(STR)         __console_tx_string(BIOS_ALERT, STR)
#define print_crit(STR)          __console_tx_string(BIOS_CRIT, STR)
#define print_err(STR)           __console_tx_string(BIOS_ERR, STR)
#define print_warning(STR)       __console_tx_string(BIOS_WARNING, STR)
#define print_notice(STR)        __console_tx_string(BIOS_NOTICE, STR)
#define print_info(STR)          __console_tx_string(BIOS_INFO, STR)
#define print_debug(STR)         __console_tx_string(BIOS_DEBUG, STR)
#define print_spew(STR)          __console_tx_string(BIOS_SPEW, STR)

#define print_emerg_char(CH)     __console_tx_char(BIOS_EMERG, CH)
#define print_alert_char(CH)     __console_tx_char(BIOS_ALERT, CH)
#define print_crit_char(CH)      __console_tx_char(BIOS_CRIT, CH)
#define print_err_char(CH)       __console_tx_char(BIOS_ERR, CH)
#define print_warning_char(CH)   __console_tx_char(BIOS_WARNING, CH)
#define print_notice_char(CH)    __console_tx_char(BIOS_NOTICE, CH)
#define print_info_char(CH)      __console_tx_char(BIOS_INFO, CH)
#define print_debug_char(CH)     __console_tx_char(BIOS_DEBUG, CH)
#define print_spew_char(CH)      __console_tx_char(BIOS_SPEW, CH)

#define print_emerg_hex8(HEX)    __console_tx_hex8(BIOS_EMERG, HEX)
#define print_alert_hex8(HEX)    __console_tx_hex8(BIOS_ALERT, HEX)
#define print_crit_hex8(HEX)     __console_tx_hex8(BIOS_CRIT, HEX)
#define print_err_hex8(HEX)      __console_tx_hex8(BIOS_ERR, HEX)
#define print_warning_hex8(HEX)  __console_tx_hex8(BIOS_WARNING, HEX)
#define print_notice_hex8(HEX)   __console_tx_hex8(BIOS_NOTICE, HEX)
#define print_info_hex8(HEX)     __console_tx_hex8(BIOS_INFO, HEX)
#define print_debug_hex8(HEX)    __console_tx_hex8(BIOS_DEBUG, HEX)
#define print_spew_hex8(HEX)     __console_tx_hex8(BIOS_SPEW, HEX)

#define print_emerg_hex16(HEX)   __console_tx_hex16(BIOS_EMERG, HEX)
#define print_alert_hex16(HEX)   __console_tx_hex16(BIOS_ALERT, HEX)
#define print_crit_hex16(HEX)    __console_tx_hex16(BIOS_CRIT, HEX)
#define print_err_hex16(HEX)     __console_tx_hex16(BIOS_ERR, HEX)
#define print_warning_hex16(HEX) __console_tx_hex16(BIOS_WARNING, HEX)
#define print_notice_hex16(HEX)  __console_tx_hex16(BIOS_NOTICE, HEX)
#define print_info_hex16(HEX)    __console_tx_hex16(BIOS_INFO, HEX)
#define print_debug_hex16(HEX)   __console_tx_hex16(BIOS_DEBUG, HEX)
#define print_spew_hex16(HEX)    __console_tx_hex16(BIOS_SPEW, HEX)

#define print_emerg_hex32(HEX)   __console_tx_hex32(BIOS_EMERG, HEX)
#define print_alert_hex32(HEX)   __console_tx_hex32(BIOS_ALERT, HEX)
#define print_crit_hex32(HEX)    __console_tx_hex32(BIOS_CRIT, HEX)
#define print_err_hex32(HEX)     __console_tx_hex32(BIOS_ERR, HEX)
#define print_warning_hex32(HEX) __console_tx_hex32(BIOS_WARNING, HEX)
#define print_notice_hex32(HEX)  __console_tx_hex32(BIOS_NOTICE, HEX)
#define print_info_hex32(HEX)    __console_tx_hex32(BIOS_INFO, HEX)
#define print_debug_hex32(HEX)   __console_tx_hex32(BIOS_DEBUG, HEX)
#define print_spew_hex32(HEX)    __console_tx_hex32(BIOS_SPEW, HEX)

#else

#define print_emerg(STR)         printk(BIOS_EMERG,  "%s", (STR))
#define print_alert(STR)         printk(BIOS_ALERT,  "%s", (STR))
#define print_crit(STR)          printk(BIOS_CRIT,   "%s", (STR))
#define print_err(STR)           printk(BIOS_ERR,    "%s", (STR))
#define print_warning(STR)       printk(BIOS_WARNING,"%s", (STR))
#define print_notice(STR)        printk(BIOS_NOTICE, "%s", (STR))
#define print_info(STR)          printk(BIOS_INFO,   "%s", (STR))
#define print_debug(STR)         printk(BIOS_DEBUG,  "%s", (STR))
#define print_spew(STR)          printk(BIOS_SPEW,   "%s", (STR))

#define print_emerg_char(CH)     printk(BIOS_EMERG,  "%c", (CH))
#define print_alert_char(CH)     printk(BIOS_ALERT,  "%c", (CH))
#define print_crit_char(CH)      printk(BIOS_CRIT,   "%c", (CH))
#define print_err_char(CH)       printk(BIOS_ERR,    "%c", (CH))
#define print_warning_char(CH)   printk(BIOS_WARNING,"%c", (CH))
#define print_notice_char(CH)    printk(BIOS_NOTICE, "%c", (CH))
#define print_info_char(CH)      printk(BIOS_INFO,   "%c", (CH))
#define print_debug_char(CH)     printk(BIOS_DEBUG,  "%c", (CH))
#define print_spew_char(CH)      printk(BIOS_SPEW,   "%c", (CH))

#define print_emerg_hex8(HEX)    printk(BIOS_EMERG,  "%02x",  (HEX))
#define print_alert_hex8(HEX)    printk(BIOS_ALERT,  "%02x",  (HEX))
#define print_crit_hex8(HEX)     printk(BIOS_CRIT,   "%02x",  (HEX))
#define print_err_hex8(HEX)      printk(BIOS_ERR,    "%02x",  (HEX))
#define print_warning_hex8(HEX)  printk(BIOS_WARNING,"%02x",  (HEX))
#define print_notice_hex8(HEX)   printk(BIOS_NOTICE, "%02x",  (HEX))
#define print_info_hex8(HEX)     printk(BIOS_INFO,   "%02x",  (HEX))
#define print_debug_hex8(HEX)    printk(BIOS_DEBUG,  "%02x",  (HEX))
#define print_spew_hex8(HEX)     printk(BIOS_SPEW,   "%02x",  (HEX))

#define print_emerg_hex16(HEX)   printk(BIOS_EMERG,  "%04x", (HEX))
#define print_alert_hex16(HEX)   printk(BIOS_ALERT,  "%04x", (HEX))
#define print_crit_hex16(HEX)    printk(BIOS_CRIT,   "%04x", (HEX))
#define print_err_hex16(HEX)     printk(BIOS_ERR,    "%04x", (HEX))
#define print_warning_hex16(HEX) printk(BIOS_WARNING,"%04x", (HEX))
#define print_notice_hex16(HEX)  printk(BIOS_NOTICE, "%04x", (HEX))
#define print_info_hex16(HEX)    printk(BIOS_INFO,   "%04x", (HEX))
#define print_debug_hex16(HEX)   printk(BIOS_DEBUG,  "%04x", (HEX))
#define print_spew_hex16(HEX)    printk(BIOS_SPEW,   "%04x", (HEX))

#define print_emerg_hex32(HEX)   printk(BIOS_EMERG,  "%08x", (HEX))
#define print_alert_hex32(HEX)   printk(BIOS_ALERT,  "%08x", (HEX))
#define print_crit_hex32(HEX)    printk(BIOS_CRIT,   "%08x", (HEX))
#define print_err_hex32(HEX)     printk(BIOS_ERR,    "%08x", (HEX))
#define print_warning_hex32(HEX) printk(BIOS_WARNING,"%08x", (HEX))
#define print_notice_hex32(HEX)  printk(BIOS_NOTICE, "%08x", (HEX))
#define print_info_hex32(HEX)    printk(BIOS_INFO,   "%08x", (HEX))
#define print_debug_hex32(HEX)   printk(BIOS_DEBUG,  "%08x", (HEX))
#define print_spew_hex32(HEX)    printk(BIOS_SPEW,   "%08x", (HEX))

#endif

#endif /* __CONSOLE_EARLY_PRINT_H_ */
