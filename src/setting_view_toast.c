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
#include <string.h>

#include "setting_view_toast.h"
#include "util.h"

Toast_Data* _create_toast( void * data, char * msg )
{
	Toast_Data * toast = (Toast_Data *) calloc(sizeof(Toast_Data), 1);

	toast->is_show = 0;
	toast->str = strdup(msg);
	toast->toast_popup = NULL;

	return toast;
}

void _destroy_toast( Toast_Data* toast )
{
	if( toast ) {
		if(toast->str) {
			free(toast->str);
		}
		if(toast->toast_popup) {
			evas_object_del(toast->toast_popup);
			toast->toast_popup = NULL;
		}
		free(toast);
	}
}

void _dismiss_toast(void *data, Evas_Object *obj, void *event_info)
{
	 Toast_Data* toast =(Toast_Data*)data;
	_destroy_toast(toast);
}

void _show_toast( void * data, Toast_Data* toast )
{
	appdata * ad = data;
	if( ad == NULL || toast == NULL ) {
		return;
	}

	if( toast->is_show ) {
		return;
	}

	toast->toast_popup = elm_popup_add(ad->nf);
	elm_object_style_set(toast->toast_popup, "toast");
	elm_popup_orient_set(toast->toast_popup, ELM_POPUP_ORIENT_BOTTOM);
	evas_object_size_hint_weight_set(toast->toast_popup, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	ea_object_event_callback_add(toast->toast_popup, EA_CALLBACK_BACK, ea_popup_back_cb, NULL);
	elm_object_part_text_set(toast->toast_popup,"elm.text", toast->str);
	elm_popup_timeout_set(toast->toast_popup, 2.0);

	evas_object_smart_callback_add(toast->toast_popup, "block,clicked", _dismiss_toast, toast);
	evas_object_smart_callback_add(toast->toast_popup, "timeout", _dismiss_toast, toast);

	evas_object_show(toast->toast_popup);
}
