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
/*
 * setting-clock.h
 *
 *  Created on: Oct 8, 2013
 *      Author: min-hoyun
 */

#ifndef SETTING_CLOCK_H_
#define SETTING_CLOCK_H_

#include <Elementary.h>
#include <libintl.h>
#include <string.h>
#include <vconf.h>
#include <langinfo.h>
#include <time.h>
#include <dd-deviced-managed.h>
#include <dd-deviced.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#define CLOCK_LIST_XML_FILE_PATH	"/usr/apps/org.tizen.clocksetting/data/clocklist.xml"
#define WALLPAPER_PATH_PREFIX	"/opt/share/settings/Wallpapers"

#define CLOCK_DATE_AND_TIME_COUNT	3

#define IDLE_CLOCK_CATEGROY2	"http://tizen.org/category/idle-clock"
#define IDLE_CLOCK_CATEGROY	"com.samsung.wmanager.WATCH_CLOCK"

enum {
	HOURLY_ALERT_OFF,
	HOURLY_ALERT_SOUND,
	HOURLY_ALERT_VIBRATION
};


struct _clock_menu_item {
	char *name;
	int type_num;
	void (*func)(void *data, Evas_Object *obj, void *event_info);
};

struct _dt_menu_item {
	char *name;
	char *date_or_time;
	void (*func)(void *data, Evas_Object *obj, void *event_info);
};

typedef struct dt_Item_Data
{
	int index;
	Elm_Object_Item *item;
	Evas_Object *check;
	Evas_Object *state_label;
} DT_Item_Data;

typedef struct alert_Item_Data
{
	int index;
	Elm_Object_Item *item;
	Evas_Object *radio;
	Evas_Object *radio_group;
} Alert_Item_Data;

typedef struct _clock_page_data clock_page_data;
struct _clock_page_data
{
	Evas_Object *mapbuf[32];
};

enum {
	CLOCKTYPE_INVALID = -1,
	CLOCKTYPE_FUNCTION,
	CLOCKTYPE_STYLE,
	CLOCKTYPE_3RD
};

typedef struct _clock_type_item {
	int index;
	char *appid;
	char *pkgid;
	char *name;
	char *icon;
} Clock_Type_Item;

static Eina_List *g_clock_list[3];

int is_alert_on_or_off;
int is_running_clock;

void  _clear_clock_cb(void *data , Evas *e, Evas_Object *obj, void *event_info);
void _dt_cb(void *data, Evas_Object *obj, void *event_info);
void _hourly_alert_cb(void *data, Evas_Object *obj, void *event_info);
char * _gl_Clock_title_get(void *data, Evas_Object *obj, const char *part);
Evas_Object* _create_clock_list(void* data);
char * _gl_date_and_time_title_get(void *data, Evas_Object *obj, const char *part);
void _show_date_and_time_list(void* data);

void _alert_sel_changed_cb(void *data, Evas_Object *obj, void *event_info);
char * _gl_alert_title_get(void *data, Evas_Object *obj, const char *part);
Evas_Object * _gl_alert_ridio_get(void *data, Evas_Object *obj, const char *part);
char * _gl_alert_title_get(void *data, Evas_Object *obj, const char *part);
void _show_hourly_alert_list(void* data);

Evas_Object *_clock_type_cb(void *data);

void initialize_clock(void *data);

void _clocklist_load();
Eina_List* _get_clock_type_list();
void _clocklist_destroy();

#endif /* SETTING_CLOCK_H_ */
