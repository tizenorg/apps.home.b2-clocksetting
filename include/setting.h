/*
 * Copyright (c) 2000 - 2013 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef __SETTING_H__
#define __SETTING_H__

#include <Elementary.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dlog.h>
#include <app.h>
#include <feedback.h>
#include <efl_assist.h>
#include <bluetooth.h>

//#include "util.h"


#define NUM_OF_SETTING_MAIN_MENU	 11

struct _menu_item {
	char *name;
	char *icon_name;
	void (*func)(void *data, Evas_Object *obj, void *event_info);
};


// Main Screen's callback functions
void clock_cb(void *data, Evas_Object *obj, void *event_info);
void notification_cb(void *data, Evas_Object *obj, void *event_info);
void sound_cb(void *data, Evas_Object *obj, void *event_info);
void homescreen_cb(void *data, Evas_Object *obj, void *event_info);
void volume_cb(void *data, Evas_Object *obj, void *event_info);
void display_cb(void *data, Evas_Object *obj, void *event_info);
void battery_cb(void *data, Evas_Object *obj, void *event_info);
void bluetooth_cb(void *data, Evas_Object *obj, void *event_info);
void motion_cb(void *data, Evas_Object *obj, void *event_info);
void lockscreen_cb(void *data, Evas_Object *obj, void *event_info);
void double_pressing_cb(void *data, Evas_Object *obj, void *event_info);
void language_cb(void *data, Evas_Object *obj, void *event_info);
void safety_cb(void *data, Evas_Object *obj, void *event_info);
void reset_gear_cb(void *data, Evas_Object *obj, void *event_info);
void gear_info_cb(void *data, Evas_Object *obj, void *event_info);
void profile_cb(void *data, Evas_Object *obj, void *event_info);

static void _update_main_menu_title( void * data );

#endif
