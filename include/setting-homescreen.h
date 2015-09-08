/*
 *  Copyright (c) 2014 Samsung Electronics Co., Ltd.
 *
 *  Licensed under the Flora License, Version 1.0 (the License);
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://floralicense.org/license/
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an AS IS BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */
/*
 * setting-display.h
 *
 *  Created on: Oct 9, 2013
 *      Author: min-hoyun
 */

#ifndef SETTING_HOMESCREEN_H_
#define SETTING_HOMESCREEN_H_

#include <Elementary.h>
#include <libintl.h>
#include <string.h>

#define HOME_MENU_COUNT		3
#define VIEWTYPE_COUNT	2
#define BG_COLOR_COUNT	12
#define HOME_BG_LIST_COUNT 3
#define NUM_MAX_THUMB_IN_PAGES 2
#define NUM_DEFAULT_THUMB_BUTTON 2
#define DEFAULT_WALLPAPER_COUNT 6
#define WALLPAPER_CNT_PER_PAGE 4
#define SETTING_DEFAULT_WALLPAPER_PATH	"/opt/share/settings/Wallpapers"
#define CROPPED_GALLERY_DEFAULT_WALLPAPER_PATH		"/opt/usr/media/.bgwallpaper.jpg"

struct _homescreen_menu_item {
	char *name;
	int is_check_type;
	int state;
	void (*func)(void *data, Evas_Object *obj, void *event_info);
};

struct _homebg_menu_item {
	char *name;
	void (*func)(void *data, Evas_Object *obj, void *event_info);
};

typedef struct _Homescreen_Item_Data {
	int index;
	Elm_Object_Item *item;
} Homescreen_Item_Data;

typedef struct _page_data page_data;
struct _page_data {
	Evas_Object *mapbuf[BG_COLOR_COUNT / 2];
};

struct _color {
	int r;
	int g;
	int b;
	char *hex;
};

typedef struct _wallpaper_page_data wallpaper_page_data;
struct _wallpaper_page_data {
	Evas_Object *mapbuf[DEFAULT_WALLPAPER_COUNT / NUM_MAX_THUMB_IN_PAGES];
};

char *_get_homeview_type_subtitle();
char *_gl_homescreen_title_get(void *data, Evas_Object *obj, const char *part);
Evas_Object *_gl_homescreen_check_get(void *data, Evas_Object *obj, const char *part);
Evas_Object *_create_homescreen_list(void *data);
void _homescreen_gl_viewtype_cb(void *data, Evas_Object *obj, void *event_info);
void _homescreen_gl_homebg_cb(void *data, Evas_Object *obj, void *event_info);
void _homescreen_gl_edit_home_cb(void *data, Evas_Object *obj, void *event_info);
void _homescreen_gl_edit_apps_cb(void *data, Evas_Object *obj, void *event_info);
void _show_bg_slide_cb(void *data, Evas_Object *obj, void *event_info);
void _wallpaper_gl_cb(void *data, Evas_Object *obj, void *event_info);
void _gallery_gl_cb(void *data, Evas_Object *obj, void *event_info);
void _clear_homescreen_cb(void *data , Evas *e, Evas_Object *obj, void *event_info);

Evas_Object *create_wallpaper_list(void *data);

#endif /* SETTING_HOMESCREEN_H_ */
