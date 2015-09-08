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
#include "setting_data_vconf.h"
#include "util.h"


int unregister_vconf_changing(const char *vconf, vconf_callback_fn cb)
{
	int ret = TRUE;
	if (vconf && cb) {
		ret = vconf_ignore_key_changed(vconf, cb);
		if (ret == VCONF_OK) {
			DBG("Setting - vconf's changed callback unregisted!!");
		} else {
			DBG("Setting - vconf's changed callback do not unregist");
			ret = FALSE;
		}
	}
	return ret;
}

int register_vconf_changing(const char *vconf, vconf_callback_fn cb, void *data)
{
	int ret = TRUE;
	if (vconf && cb) {
		ret = vconf_notify_key_changed(vconf, cb, data);
		if (ret == VCONF_OK) {
			DBG("Setting - vconf's changed callback is registed!");
		} else {
			DBG("Setting - vconf's changed callback is not registed!");
			ret = FALSE;
		}
	}
	return ret;
}
