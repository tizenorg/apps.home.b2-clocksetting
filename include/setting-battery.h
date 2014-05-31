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
 * setting-battery.h
 *
 *  Created on: Oct 12, 2013
 *      Author: min-hoyun
 */

#ifndef SETTING_BATTERY_H_
#define SETTING_BATTERY_H_

#include <Elementary.h>
#include <libintl.h>
#include <string.h>
#include <device.h>

struct _battery_menu_item {
	char *name;
	int is_enable;
	void (*func)(void *data, Evas_Object *obj, void *event_info);
};

enum {
	CHARGING_NONE,
	CHARGING_AC,
	CHARGING_USB
};

enum {
	BATT_MENU_STATUS,
	//BATT_MENU_PERCENT,
	BATT_MENU_POWER_SAVING
};

struct _battery_info {
	int percent;
	int is_charging;
};

Ecore_Timer * battery_timer;

int percent;
bool is_charging;
bool prev_charging_state;
int image_index;
int is_alive;


// ----------------method----------------------//

Evas_Object* _create_battery_list(void* data);

Evas_Object *_battery_status_cb(void *data);
void _clear_battery_cb(void *data , Evas *e, Evas_Object *obj, void *event_info);
Eina_Bool _clear_battery_list_cb(void *data, Elm_Object_Item *it);
void _start_timer_for_update(Evas_Object * obj);

void _initialize_battery();

#endif /* SETTING_BATTERY_H_ */
