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
 * setting-privacy.h
 *
 *  Created on: Jan 7, 2014
 *      Author: Sunyeop Hwang
 */

#ifndef SETTING_PRIVACY_H_
#define SETTING_PRIVACY_H_

#include <Elementary.h>

struct _privacy_menu_item {
	char *name;
	void (*func)(void *data, Evas_Object *obj, void *event_info);
};

typedef struct Privacy_Item_Data {
	int index;
	Elm_Object_Item *item;
	Evas_Object *check;
} Privacy_Item_Data;

Evas_Object *create_privacy_list(void *data);
Eina_Bool clear_privacy_cb(void *data, Elm_Object_Item *it);

#endif /* SETTING_PRIVACY_H_ */
