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
#ifndef _SETTING_CONTROL_HAPTIC_
#define _SETTING_CONTROL_HAPTIC_

#include <Elementary.h>
#include <dd-haptic.h>

#define SETTING_DEFAULT_HAPTIC_PREVIEW_VIB		"/opt/share/settings/Vibrations/B2_System_Vibration_Preview_140221.ivt"
#define SETTING_DEFAULT_SYSTEM_HAPTIC_PREVIEW_VIB		"/opt/share/settings/Vibrations/B2_System_Long_v2_140221.ivt"
#define SETTING_DEFAULT_NOTIFICATION_GENERAL_PREVIEW_VIB		"/opt/usr/share/settings/Vibrations/B2_Notification_General_v5_140306.ivt"
#define SETTING_VIB_FEEDBACK_RATE				20

#define SETTING_VIB_STRONG_RATE			49	/* 70 */
#define SETTING_VIB_MEDIUM_RATE			49
#define SETTING_VIB_WEAK_RATE			20	/* 30 */

struct _haptic_data {
	int is_haptic_opened;
};

int _haptic_open();
int _is_haptic_open();
int _haptic_close();

Eina_Bool __vibration_timeout(void *data);
void _start_vibration(int level, int feedback_rate, char *res_path);

#endif
