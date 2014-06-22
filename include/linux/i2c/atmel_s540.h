/*
 * Atmel maXTouch Touchscreen driver
 *
 * Copyright (C) 2010 Samsung Electronics Co.Ltd
 * Author: Joonyoung Shim <jy0922.shim@samsung.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

#ifndef __LINUX_ATMEL_MXT_TS_H
#define __LINUX_ATMEL_MXT_TS_H

#ifndef CUST_B_TOUCH
#define CUST_B_TOUCH
#endif

#include <linux/types.h>

#define MXT_DEVICE_NAME			"lge_touch"
#define MXT_MAX_NUM_TOUCHES		10
#define MXT_GESTURE_RECOGNIZE

#ifdef MXT_GESTURE_RECOGNIZE
#define MXT_LATEST_FW_VERSION       0x10
#define MXT_LATEST_FW_BUILD         0xE2
#else
#define MXT_LATEST_FW_VERSION       0x30
#define MXT_LATEST_FW_BUILD         0xAA
#endif

#ifdef CUST_B_TOUCH
enum{
	TIME_START_TIME,
	TIME_CURR_TIME,
	TIME_EX_PROFILE_MAX
};

enum{
	FINGER_INACTIVE,
	FINGER_RELEASED,
	FINGER_PRESSED,
	FINGER_MOVED
};
#endif

enum { MXT_T6 = 0,
	MXT_T38,
	MXT_T71,
	MXT_T7,
	MXT_T8,
	MXT_T15,
	MXT_T18,
	MXT_T19,
	MXT_T23,
#ifdef MXT_GESTURE_RECOGNIZE
	MXT_T24,
#endif
	MXT_T25,
#ifdef MXT_GESTURE_RECOGNIZE
	MXT_T35,
#endif
	MXT_T40,
	MXT_T42,
	MXT_T46,
	MXT_T47,
	MXT_T55,
	MXT_T56,
	MXT_T61,
	MXT_T65,
	MXT_T66,
	MXT_T69,
	MXT_T70,
	MXT_T72,
	MXT_T78,
	MXT_T80,
	MXT_T84,
	MXT_T100,
	MXT_T101,
	MXT_T102,
	MXT_T103,
	MXT_T104,
	MXT_T105,
	MXT_TMAX,
};

/* Config data for a given maXTouch controller with a specific firmware */
struct mxt_config_info {
	u8 *config_t[MXT_TMAX];
};

/* The platform data for the Atmel maXTouch touchscreen driver */
struct mxt_platform_data {
	const struct mxt_config_info *config_array;
	size_t config_array_size;
	u8    numtouch;	/* Number of touches to report	*/
	int   max_x;    /* The default reported X range   */
	int   max_y;    /* The default reported Y range   */
	bool i2c_pull_up;
	unsigned long irqflags;
	u8 t19_num_keys;
	const unsigned int *t19_keymap;
	int t15_num_keys;
	const unsigned int *t15_keymap;
	unsigned long gpio_reset;
	unsigned long gpio_int;
	const char *cfg_name;
};

#endif /* __LINUX_ATMEL_MXT_TS_H */
