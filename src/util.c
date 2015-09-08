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
 * util.c
 *
 *  Created on: Nov 21, 2013
 *      Author: min-hoyun
 */

#include <string.h>
#include <vconf.h>
#include <unicode/unum.h>
#include <fcntl.h>
#include "util.h"


char *setting_gettext(const char *s)
{
	/* fisrt find in app pg */

	if (s == NULL) {
		return "NULL";
	}

	char *p = dgettext(SETTING_PACKAGE, s);

	if (!strcmp(s, p)) {	/* not found */
		/* find in system pkg */
		p = dgettext(SYSTEM_PACKAGE, s);
	}
	return p;
}

char *replace(char *str, char *orig, char *repl)
{
	static char buffer[124];
	char *ch;
	if (!(ch = strstr(str, orig))) {
		return str;
	}
	strncpy(buffer, str, ch - str);
	buffer[ch - str] = 0;
	sprintf(buffer + (ch - str), "%s%s", repl, ch + strlen(orig));

	return buffer;
}

void setting_popup_back_cb(void *data, Evas_Object *obj, void *event_info)
{
	appdata *ad = (appdata *)data;
	if (ad == NULL) {
		return;
	}

	if (ad->popup) {
		evas_object_del(ad->popup);
		ad->popup = NULL;
	}
}

int is_connected_GM()
{
	int enable = 0;
	vconf_get_bool(VCONFKEY_WMS_WMANAGER_CONNECTED, &enable);

	return enable;
}

bool colorstr_to_decimal(char *color, int *R, int *G, int *B)
{
	DBG("_colorstr_to_decimal");
	if (color == NULL)
		return false;

	char *ptr;
	long value;
	value = strtol(color, &ptr, 16);
	*R = (value >> 16) & 0xFF;
	*G = (value >> 8) & 0xFF;
	*B = value & 0xFF;
	return true;
}

char *_get_strnum_from_icu(int number)
{
	char *locale_tmp = vconf_get_str(VCONFKEY_REGIONFORMAT);
	char locale[32] = {0,};
	char *p = NULL;
	if (strlen(locale_tmp) < 32)
		strcpy(locale, locale_tmp);

	if (locale[0] != '\0') {
		p = strstr(locale, ".UTF-8");
		if (p) {
			*p = 0;
		}
	}

	char *ret_str = NULL;
	UErrorCode status = U_ZERO_ERROR;

	UNumberFormat *num_fmt;
	UChar result[20] = { 0, };
	char res[20] = { 0, };
	int32_t len = (int32_t)(sizeof(result) / sizeof((result)[0]));

	num_fmt = unum_open(UNUM_DEFAULT, NULL, -1, locale, NULL, &status);
	unum_format(num_fmt, number, result, len, NULL, &status);

	u_austrcpy(res, result);

	unum_close(num_fmt);

	ret_str = strdup(res);
	return ret_str;
}

bool is_file_exist(char *file_path)
{
	int fd;

	if (!file_path) {
		DBG("Setting - file path is wrong!!");
		return false;
	}

	if ((fd = open(file_path, O_RDONLY)) == -1) {
		DBG("Setting - file(%s) do not exist!!", file_path);
		return false;
	}

	DBG("Setting - file exist!!");

	return true;
}
