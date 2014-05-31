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
 * setting-language.h
 *
 *  Created on: Oct 9, 2013
 *      Author: min-hoyun
 */

#ifndef SETTING_LANGUAGE_H_
#define SETTING_LANGUAGE_H_

#include <Elementary.h>
#include <libintl.h>
#include <string.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "util.h"

#define LANGLIST_FILE_PATH_IN_RW		"/opt/usr/data/setting/langlist.xml"
#define LANGLIST_FILE_PATH_IN_RO		"/usr/apps/org.tizen.clocksetting/data/langlist.xml"

#define ITEM_COUNT				2

#if defined(FEATURE_SETTING_SDK) || defined(FEATURE_SETTING_EMUL)
#define LANGUAGE_ITEM_COUNT	49	
#else
#define LANGUAGE_ITEM_COUNT	84
#endif

struct _lang_menu_item {
	char *name;
	char *sub_name;
	char *id;
	char *lang;
};

appdata * tmp_ad;
static Eina_List * s_langlist;
static void (*lang_update_cb)(void*);


char * _gl_lang_title_get(void *data, Evas_Object *obj, const char *part);
Evas_Object * _gl_lang_ridio_get(void *data, Evas_Object *obj, const char *part);
Evas_Object * _create_lang_list(void* data);
void _lang_sel_changed_cb(void *data, Evas_Object *obj, void *event_info);
void _gl_lang_sel_cb(void * data, Evas_Object * obj, void * event_info);
void _clear_lang_cb(void *data , Evas *e, Evas_Object *obj, void *event_info);
void _initialize_language(void * data);
void _set_launguage_update_cb(void (*cb)(void*));

void _langlist_load();
Eina_List* _get_language_list();
void _langlist_destroy();
static void _parseLangListXML(char* docname);
static void _tree_walk_langlist(xmlNodePtr cur);



#endif /* SETTING_LANGUAGE_H_ */
