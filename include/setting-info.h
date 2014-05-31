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
 * setting-info.h
 *
 *  Created on: Oct 8, 2013
 *      Author: min-hoyun
 */

#ifndef SETTING_INFO_H_
#define SETTING_INFO_H_

#include <Elementary.h>
#include <libintl.h>
#include <string.h>
#include <system_info.h>

#define ITEM_COUNT			2
#define ABOUT_ITEM_COUNT	5

struct _info_menu_item {
	char *name;
	int type;
	void (*func)(void *data, Evas_Object *obj, void *event_info);
};

typedef struct Info_Item_Data
{
	int index;
	Elm_Object_Item *item;
	Evas_Object *check;
} Info_Item_Data;

int get_enable_USB_debugging();
char * _gl_info_title_get(void *data, Evas_Object *obj, const char *part);
Evas_Object * _gl_info_check_get(void *data, Evas_Object *obj, const char *part);
Evas_Object* _create_info_list(void* data);
void _gl_usb_debug_cb(void *data, Evas_Object *obj, void *event_info);
void _usb_debug_chk_changed_cb(void *data, Evas_Object *obj, void *event_info);


void _gl_info_cb(void *data, Evas_Object *obj, void *event_info);
void _info_open_src_gl_cb(void *data, Evas_Object *obj, void *event_info);
void _info_safety_inform_gl_cb(void *data, Evas_Object *obj, void *event_info);
void _info_gl_sel_cb(void *data, Evas_Object *obj, void *event_info);

Eina_Bool _clear_info_cb(void *data, Elm_Object_Item *it);


#endif /* SETTING_INFO_H_ */
