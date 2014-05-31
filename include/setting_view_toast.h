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
#ifndef _SETTING_VIEW_TOAST_H_
#define _SETTING_VIEW_TOAST_H_

#include <Elementary.h>

typedef struct _toast_data {
	char * str;
	int is_show;

	Evas_Object * toast_popup;
} Toast_Data;

Toast_Data * _create_toast( void * data, char * msg );
void _destroy_toast( struct _toast_data * toast );
void _dismiss_toast(void *data, Evas_Object *obj, void *event_info);
//void _dismiss_toast( struct _toast_data * toast );
void _show_toast( void * data, struct _toast_data * toast );

#endif
