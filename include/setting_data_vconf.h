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
#ifndef _SETTING_DATA_VCONF_H_
#define _SETTING_DATA_VCONF_H_

#include <vconf.h>
#include <vconf-keys.h>


int unregister_vconf_changing(const char *vconf, vconf_callback_fn cb);
int register_vconf_changing(const char *vconf, vconf_callback_fn cb, void *data);

#endif
