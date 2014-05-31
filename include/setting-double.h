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
 * setting-double.h
 *
 *  Created on: Jan 8, 2014
 *      Author: Sunyeop Hwang
 */

#ifndef SETTING_DOUBLE_H_
#define SETTING_DOUBLE_H_

#include <Elementary.h>

struct _double_menu_item {
	int index;
	char *appid;
	char *pkgid;
	char *name;
};

typedef struct Double_Item_Data {
	struct _double_menu_item *pitem;
	Elm_Object_Item *item;
	Evas_Object *check;
} Double_Item_Data;

void init_double_pressing(void *data);
Evas_Object *create_double_app_list(void *data);
Evas_Object *create_double_list(void *data);
void clear_double_app_cb(void *data , Evas *e, Evas_Object *obj, void *event_info);
void clear_double_cb(void *data , Evas *e, Evas_Object *obj, void *event_info);

#endif /* SETTING_DOUBLE_H_ */
